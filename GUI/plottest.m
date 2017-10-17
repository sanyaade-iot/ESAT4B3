addpath('../ECG/')
addpath('../Wavelets/')

load('100m.mat')
t = testapp

samplefreq = 360;
seconds = 2;
viewportwidth = samplefreq * seconds; % 720 samples or 2 seconds

t.UIAxes.YLim = [0, 60000];

time = (0:length(val)-1)/samplefreq;

% val = val + 360*sin(time*2*pi/2) + 36*sin(time*2*pi*50) + 60*wgn(length(val),1,0)'; % 0.5 and 50 Hz + white gaussian nois

%%
[cols,rows] = size(val) 
for j = 0:(rows-viewportwidth)
    x = time(1,1+j:viewportwidth+j);
    t.UIAxes.XLim = [x(1), x(viewportwidth)];
    y = val(1,1+j:viewportwidth+j);
    y = waveletFilterECG(y).^2;
    plot(t.UIAxes, x, y)
    pause(0)
end
%%
tic;
for j = 0:((rows/100)-viewportwidth)
    y = val(1,1+j:viewportwidth+j);
    y = waveletFilterECG(y).^2;
end
timeElapsed = toc;
timeElapsed / ((rows/100)-viewportwidth)

%%

% Sample rate
fs = 360;

% Transport phenomena reduction
transportPhenomenaReduction = 0.15;

% Buffer length in seconds
bufferLengthSeconds = 5;
bufferLength = bufferLengthSeconds * fs;

% New data buffer length in seconds
newBufferLengthSeconds = 0.1;
newBufferLength = newBufferLengthSeconds * fs;

% Start a new figure
figure

% Initialize the buffer and the new data buffer
buffer = zeros(1, bufferLength);
newBuffer = zeros(1, newBufferLength);

% Keep track of the total number of samples we have already 'received'
totalSamplesRead = 0;

% Keep track of the number of smaples that are already filled in the new buffer
newBufferFilledCount = 0;

% Keep track of the number of samples that are already filled in the buffer
bufferFilledCount = 0;


% Continue to receive data
while 1

	% Read in the next byte
	newValue = val(1, totalSamplesRead + 1);
	newBuffer(newBufferFilledCount + 1) = newValue;

	totalSamplesRead = totalSamplesRead + 1;
	newBufferFilledCount = newBufferFilledCount + 1;
	
	
	% If the new buffer is filled...
	if newBufferFilledCount >= newBufferLength
		
		% Push the data from the new buffer to the main buffer
		buffer(1:bufferLength-newBufferLength) = buffer(newBufferLength+1:bufferLength);
		buffer(bufferLength-newBufferLength+1:bufferLength) = newBuffer;
		
		% And then empty the new buffer
		newBuffer = zeros(1, newBufferLength);
		newBufferFilledCount = 0;
		
		% Record the state of the main buffer
		bufferFilledCount = bufferFilledCount + newBufferLength;
		if bufferFilledCount > bufferLength
			bufferFilledCount = bufferLength;
		end
		
		% Calculate the bpm on the main buffer        
		waveletFilteredBuffer = waveletFilterECG(buffer(bufferLength - bufferFilledCount + 1:bufferLength));
		plot(waveletFilteredBuffer);
        
        lowerBound = floor(length(waveletFilteredBuffer) * transportPhenomenaReduction);
        upperBound = floor(length(waveletFilteredBuffer) * (1 - transportPhenomenaReduction));
        
		title(calculate_bpm2(waveletFilteredBuffer(lowerBound:upperBound)', fs, 220));
		
	end

	pause (1/fs);
end