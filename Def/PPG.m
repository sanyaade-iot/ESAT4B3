classdef PPG < handle
    properties (SetAccess = private)
        windowsize;
        visiblesamples;
        extrasamples;
        samplefreq;
        range;
        bufferlen;
        SPO2_Bufferlen;
        SPO2_Buffer;
        buffer_RD;
        buffer_IR;
        ringBuffer_RD;
        ringBuffer_IR;
        ringBufferIndex = uint16(1);
        samplesSinceLastDraw_RD = uint16(0);
        samplesSinceLastDraw_IR = uint16(0);
        filtered_RD;
        filtered_IR;
        settings;
        baseline;
        SPO2_minuteAverage = Average;
        SPO2_averages = double.empty();
        plot_SPO2;
        plot_RD;
        plot_IR;
        cursor_plot_RD;
        cursor_plot_IR;
        button;
    end
    
    methods
        function o = PPG(windowsize, extrasamples, samplefreq, SPO2_windowsize, ...
                range, lineWidth, cursorWidth, ...
                baseline, ...
                axes_home, axes_RD, axes_IR, button)
            o.windowsize      = windowsize;
            o.visiblesamples  = windowsize * samplefreq;
            o.extrasamples    = extrasamples;
            o.samplefreq      = samplefreq;
            o.range           = range;
            o.bufferlen       = o.visiblesamples + extrasamples;
            o.SPO2_Bufferlen  = SPO2_windowsize * samplefreq;
            o.SPO2_Buffer     = double(zeros(o.SPO2_Bufferlen,1));
            o.buffer_RD       = int16(zeros(o.bufferlen,1));
            o.buffer_IR       = int16(zeros(o.bufferlen,1));
            o.ringBuffer_RD   = double(zeros(o.visiblesamples,1));
            o.ringBuffer_IR   = double(zeros(o.visiblesamples,1));
            o.filtered_RD     = double(zeros(o.bufferlen,1));
            o.filtered_IR     = double(zeros(o.bufferlen,1));
            o.settings        = PPG_setup(samplefreq);
            o.baseline        = baseline;
            SPO2_time         = linspace(0, SPO2_windowsize, o.SPO2_Bufferlen);
            time              = linspace(0, windowsize, o.visiblesamples);
            o.plot_SPO2       = plot(axes_home, SPO2_time, ...
                o.SPO2_Buffer);
            hold(axes_RD, 'on');
            o.plot_RD         = plot(axes_RD, time, ...
                o.ringBuffer_RD, ...
                'LineWidth',lineWidth);
            o.cursor_plot_RD  = plot(axes_RD,[0 0],[o.range(1)*0.95,o.range(2)], ...
                'LineWidth',cursorWidth, 'Color', 'k');
            hold(axes_IR, 'on');
            o.plot_IR          = plot(axes_IR, time, ...
                o.ringBuffer_IR, ...
                'LineWidth',lineWidth);
            o.cursor_plot_IR  = plot(axes_IR,[0 0],[o.range(1)*0.95,o.range(2)], ...
                'LineWidth',cursorWidth, 'Color', 'k');
            set(axes_home,'XLim',[0 windowsize],'YLim',o.range,'TickDir','out');
            o.button = button;
            
        end
        
        function add_RD(o, value)
            o.buffer_RD(1:(o.bufferlen-1)) = o.buffer_RD(2:o.bufferlen); % shift the buffer one place to the left
            o.buffer_RD(o.bufferlen) = int16(value) - o.baseline; % add the new value to the end of the buffer
            o.samplesSinceLastDraw_RD = o.samplesSinceLastDraw_RD + 1;
        end
        function add_IR(o, value)
            o.buffer_IR(1:(o.bufferlen-1)) = o.buffer_IR(2:o.bufferlen); % shift the buffer one place to the left
            o.buffer_IR(o.bufferlen) = int16(value) - o.baseline; % add the new value to the end of the buffer
            o.samplesSinceLastDraw_IR = o.samplesSinceLastDraw_IR + 1;
        end
        
        function draw(o)
            if o.samplesSinceLastDraw_IR > 0 && o.samplesSinceLastDraw_RD > 0
                o.filtered_RD = PPG_filter(o.buffer_RD, o.settings);
                o.filtered_RD = o.filtered_RD(o.extrasamples+1:o.bufferlen);
                
                o.filtered_IR = PPG_filter(o.buffer_IR, o.settings);
                o.filtered_IR = o.filtered_IR(o.extrasamples+1:o.bufferlen);

                while(o.samplesSinceLastDraw_IR > 0 && o.samplesSinceLastDraw_RD > 0)
                    o.ringBuffer_RD(o.ringBufferIndex) ...
                       = o.filtered_RD(o.visiblesamples-o.samplesSinceLastDraw_RD+1);
                    o.samplesSinceLastDraw_RD = o.samplesSinceLastDraw_RD - 1;

                    o.ringBuffer_IR(o.ringBufferIndex) ...
                       = o.filtered_IR(o.visiblesamples-o.samplesSinceLastDraw_IR+1);
                    o.samplesSinceLastDraw_IR = o.samplesSinceLastDraw_IR - 1;
                    
                    o.ringBufferIndex = mod(o.ringBufferIndex, o.visiblesamples) + 1;
                end
                
                set(o.plot_RD,'YData', o.ringBuffer_RD);
                set(o.plot_IR,'YData', o.ringBuffer_IR);
                cursorPos = double(o.ringBufferIndex) * o.windowsize / o.visiblesamples;
                if cursorPos > 0.01
                    set(o.cursor_plot_RD, 'XData',[cursorPos  cursorPos ]);
                    set(o.cursor_plot_IR, 'XData',[cursorPos  cursorPos ]);
                end
            end
        end
        
        function displaySPO2(o)
            SPO2 = 0.97; %PPG_getSPO2(o.filtered_RD(o.bufferlen), o.filtered_RD(o.bufferlen)); % TODO
            SPO2_text = char(strcat(string(round(SPO2*1000)/10.0),'%'));
            o.button.Text = SPO2_text;
            o.SPO2_minuteAverage.add(SPO2);
        end
        function saveSPO2(o, now)
            SPO2 = o.SPO2_minuteAverage.getAverage;
            disp(strcat({'Average SPO2: '}, string(SPO2)));
            o.SPO2_averages = [o.SPO2_averages SPO2];
            fileID = fopen('SPO2.csv','a');
            fprintf(fileID,'%d\t%f\r\n', now, SPO2);
            % fprintf(fileID,'%016X\t%f\r\n', now, SPO2);
            fclose(fileID);
        end
        function resetSPO2(o)
            o.SPO2_minuteAverage.reset;
        end
    end
end
