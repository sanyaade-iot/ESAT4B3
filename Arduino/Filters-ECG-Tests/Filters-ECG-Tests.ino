#include "FIRFilter.h"
#include "IIRFilter.h"

void printArray(float *arr, uint8_t len, const char *name);

const word ECG_data[] PROGMEM = {500,497,494,499,502,501,502,498,496,491,489,495,491,488,487,488,496,510,528,551,577,598,612,617,609,588,557,524,504,492,492,495,503,507,507,509,507,503,505,505,510,511,511,510,503,504,506,511,515,516,511,509,504,504,511,517,518,516,512,510,507,513,517,518,517,512,509,511,513,521,519,519,517,515,512,514,518,523,522,520,517,513,515,521,522,526,525,518,518,516,521,526,528,527,520,517,519,521,527,528,527,522,521,521,525,528,530,529,527,523,520,525,530,529,531,528,525,521,523,525,534,533,532,526,523,524,530,533,536,531,529,525,527,535,539,540,537,535,534,535,538,543,544,545,542,539,540,544,547,551,552,549,547,544,547,549,552,556,551,547,546,546,550,557,556,553,548,546,547,552,554,553,552,550,548,549,552,555,557,557,552,551,550,552,556,559,558,558,553,551,551,555,558,559,557,553,552,552,556,562,563,559,557,553,555,558,561,562,561,556,554,557,559,561,562,560,559,558,558,558,561,565,565,562,558,558,560,564,568,569,568,562,560,561,565,570,573,566,564,563,562,568,572,575,575,569,568,570,573,577,578,581,579,577,576,578,584,581,586,581,578,574,577,581,584,583,584,580,580,578,577,582,581,577,572,568,569,576,578,581,579,574,570,572,574,577,579,577,578,572,573,575,579,581,581,579,574,575,572,575,581,579,573,568,563,559,561,568,579,588,599,610,635,665,689,708,713,707,690,663,632,609,596,583,574,569,569,575,580,587,585,581,580,577,580,582,589,589,583,583,577,578,582,588,588,589,582,581,583,587,590,591,587,582,583,582,586,590,591,588,587,583,584,584,589,592,593,589,587,586,585,590,594,596,594,589,585,588,590,597,601,596,591,588,588,595,598,600,595,592,588,590,593,596,597,597,592,592,590,592,596,598,596,594,592,590,591,593,598,600,597,592,589,587,594,599,599,596,592,588,590,595,600,602,602,597,599,599,606,608,612,610,610,608,606,608,611,616,618,614,613,611,609,615,617,621,617,616,610,611,616,618,621,620,614,610,613,617,619,624,620,619,613,616,618,621,623,622,620,618,615,618,622,623,625,621,617,616,615,619,623,623,622,619,616,615,620,624,626,624,618,616,617,623,627,626,624,618,620,620,622,626,626,625,622,619,619,624,624,626,627,625,622,621,621,625,629,631,630,624,620,619,626,628,632,629,628,623,624,628,632,633,630,626,625,624,629,637,637,637,636,632,634,635,640,644,643,640,638,639,638,641,646,645,645,639,638,635,639,644,646,646,645,641,636,640,642,644,642,634,631,633,633,639,638,634,631,631,631,632,635,636,636,632,630,629,630,633,636,638,636,631,629,628,631,633,630,626,619,614,612,621,635,652,669,684,710,739,761,773,764,730,678,639,619,622,632,638,640,639,634,632,634,636,639,639,640,634,633,631,636,641,640,638,635,630,632,634,638,639,638,632,630,633,634,640,641,639,637,633,632,636,639,643,643,639,637,635,637,638,645,643,641,637,634,635,638,642,644,643,638,634,636,640,647,647,645,638,636,637,640,644,647,645,643,639,639,642,643,646,646,645,639,637,637,641,645,646,644,640,638,638,642,645,647,645,641,637,637,641,647,650,648,646,644,648,651,655,657,655,654,651,651,652,656,659,659,656,654,651,652,655,659,656,657,653,650,651,654,661,661,659,652,650,652,656,662,662,657,652,653,654,655,657,659,656,654,652,650,651,656,657,658,655,651,649,650,654,658,658,655,652,649,649,652,656,659,657,652,648,650,652,655,657,657,654,650,648,654,656,658,657,653,653,653,654,657,657,659,658,653,649,650,652,659,659,657,652,650,650,656,658,660,659,654,653,653,658,664,665,663,659,659,657,662,665,667,668,664,663,664,663,667,669,667,667,661,661,660,663,669,668,667,664,662,659,665,664,665,660,653,649,651,654,657,657,656,653,650,649,651,656,656,654,652,650,650,650,654,654,655,652,652,648,647,646,647,644,645,638,634,628,627,633,641,643,652,661,675,701,732,762,776,778,764,735,696,664,648,643,645,647,649,652,654,654,655,654,650,647,649,653,655,656,652,649,645,647,651,657,658,653,649,648,647,653,657,656,656,651,647,647,652,654,654,655,654,649,649,651,656,656,657,653,652,649,648,653,656,658,655,650,646,648,653,660,657,657,651,649,648,652,656,655,655,653,650,650,652,654,655,655,653,651,649,650,653,656,660,654,647,649,648,652,659,658,654,648,644,646,650,655,658,654,652,651,652,656,661,660,660,656,655,655,658,660,663,664,660,658,655,657,657,663,665,662,657,653,654,659,663,663,661,655,652,654,660,660,663,658,656,654,652,658,658,660,659,654,655,655,654,653,656,655,653,649,650,653,653,656,659,655,651,648,648,651,655,655,652,648,645,646,650,655,655,653,649,645,645,651,654,653,653,646,643,643,646,649,652,653,649,646,645,643,645,650,650,647,643,643,643,648,651,651,650,646,644,643,647,653,656,652,649,646,646,652,656,656,654,652,649,652,654,657,656,656,654,653,649,649,655,656,654,653,648,648,650,653,655,652,649,643,641,639,643,648,646,644,640,637,637,642,644,644,641,637,634,635,637,640,639,640,638,633,632,635,638,641,642,638,634,631,631,634,636,632,626,617,612,612,624,639,654,668,688,717,737,752,754,727,688,648,625,616,621,626,633,634,628,625,625,625,627,629,631,629,624,622,623,627,634,631,631,625,621,623,629,632,632,628,622,619,621,623,627,630,626,625,620,617,624,626,626,627,622,620,618,620,622,625,625,625,620,619,618,622,626,625,623,617,613,614,619,624,625,622,619,614,616,620,623,624,621,616,615,615,616,620,620,618,617,612,613,609,614,617,619,613,605,606,605,612,616,618,615,608,606,606,612,617,617,613,609,609,612,617,619,620,618,618,615,615,621,624,624,622,620,617,614,616,619,623,622,621,618,613,614,619,622,623,620,614,613,616,621,622,620,619,612,611,612,614,616,616,614,612,609,608,609,613,615,616,611,607,608,607,609,610,611,610,605,605,605,608,611,612,610,607,602,603,607,611,611,606,601,600,600,604,610,611,606,601,601,602,602,606,607,607,603,598,598,599,603,605,606,603,598,595,596,599,604,606,603,601,598,600,604,609,610,607,603,602,605,607,612,610,608,607,602,600,602,607,606,609,602,601,598,598,604,607,610,607,600,595,595,600,600,600,595,587,587,585,589,591,592,589,587,584,586,588,590,589,585,584,580,582,583,587,586,586,585,581,579,582,582,583,582,576,569,565,562,562,566,572,576,582,594,615,646,678,698,704,691,660,621,589,572,566,565,566,566,568,570,573,576,573,572,566,566,566,569,571,572,568,565,565,565,566,571,571,568,561,558,561,564,568,573,566,562,561,559,564,567,567,565,560,559,558,560,563,565,562,560,556,556,557,559,560,563,560,558,552,554,559,561,562,557,552,550,551,554,559,557,555,550,549,554,556,558,559,554,552,549,549,551,553,553,551,550,547,545,545,548,551,548,547,543,537,540,544,549,548,545,540,535,540,542,549,552,547,546,545,546,550,555,556,554,552,550,549,552,553,554,557,552,550,548,548,551,554,556,552,548,544,546,550,554,554,551,548,541,545,549,551,551,548,542,541,541,544,549,549,546,541,538,539,539,545,544,542,539,534,533,537,541,543,542,537,534,532,532,538,539,540,538,529,529,530,534,537,538,535,529,527,528,529,533,535,533,531,528,527,527,534,535,531,529,523,524,525,529,529,530,527,525,520,522,525,530,530,526,520,517,521,524,526,527,527,522,520,521,525,531,531,528,527,524,524,528,532,532,533,533,524,525,524,526,528,530,530,520,519,519,526,530,530,526,518,514,513,514,518,518,512,509,508,504,509,512,513,509,507,504,506,507,509,511,509,504,502,501,502,505,508,510,502,500,498,498,502,503,499,492,485,480,479,479,487,495,507,518,534,557,588,613,630,627,607,571,527,500,487,488,490,490,490,488,488,492,495,493,490,487,485,485,487,492,493,489,483,479,480,483,486,488,483,482,478,476,481,484,484,483,480,476,476,477,481,481,483,479,477,476,478,479,481,482,479,476,473,473,479,480,479,478,473,469,471,473,477,479,476,470,468,467,471,472,476,472,470,468,467,469,473,473,475,469,467,465,464,468,471,471,466,465,462,462,466,467,469,466,461,456,461,465,468,469,463,459,458,460,464,465,464,463,461,461,460,463,467,468,469,464,464,462,463,468,469,469,467,462,460,461,464,468,469,464,459,456,458,463,465,466,463,459,456,456,459,463,463,462,459,455,455,457,459,459,458,457,456,454,456,456,460,459,458,454,453,452,457,460,462,457,453,449,453,459,461,459,456,456,455,453,455,456,458,456,452,446,445,445,446,448,447,443,438,437,436,437,440,440,438,434,428,430,434,439,438,435,430,427,430,434,436,439,436,432,428,430,430,435,436,431,429,425,422,421,420,416,415,409,403,406,416,433,456,468,491,511,530,543,549,538,506,457,426,408,408,417,425,426,423,417,415,414,419,421,422,418,416,414,414,413,417,419,414,415,414,409,411,413,418,417,413,411,405,405,411,413,417,414,407,404,406,409,416,416,411,406,403,404,408,410,411,408,404,403,403,405,406,411,407,405,402,402,401,402,407,408,405,402,399,398,401,404,408,402,396,395,396,399,404,403,399,393,392,393,398,400,402,397,397,391,393,393,397,395,396,394,388,388,389,393,395,397,395,390,387,386,392,397,396,394,388,388,391,395,399,398,395,390,391,392,395,398,399,398,393,389,390,391,394,396,395,390,390,388,390,394,397,395,394,387,384,386,390,392,394,391,385,383,382,389,391,393,387,383,381,382,382,383,384,383,382,379,377,382,382,384,382,377,377,375,377,380,380,384,380,374,372,371,379,381,381,378,373,372,371,375,378,379,375,371,370,372,373,375,376,370,367,366,366,368,370,372,373,370,367,367,370,370,372,375,367,367,365,363,367,369,371,365,361,359,360,365,368,368,364,361,358,361,363,367,367,365,363,358,358,360,367,367,365,364,357,356,357,359,365,363,360,356,352,355,359,363,363,359,354,352,352,355,359,362,359,353,352,354,355,360,360,357,353,350,352,353,357,359,356,353,352,350,352,358,361,361,357,354,353,353,359,364,362,362,356,355,357,360,363,363,359,355,352,354,356,357,358,354,351,348,352,352,357,357,354,350,347,343,342,345,349,345,346,339,338,340,343,346,345,342,335,332,334,337,342,346,339,334,331,332,335,340,338,334,331,325,322,325,326,323,319,320,329,339,351,374,399,425,445,455,458,448,427,399,368,346,326,318,311,316,325,327,328,324,322,323,330,331,332,329,324,322,323,323,325,327,327,323,321,318,320,322,327,328,323,320,319,319,322,327,326,322,318,315,318,321,324,325,324,317,316,317,320,322,322,320,319,315,317,316,322,321,319,318,314,314,315,317,318,322,319,315,313,313,319,323,322,320,315,313,311,317,321,322,320,313,311,313,317,318,317,312,310,307,307,309,313,312,311,310,301,299,302,303,309,310,306,303,299,300,306,309,310,309,304,302,306,310,313,316,314,310,308,310,316,320,321,319,317,314,315,319,321,324,323,319,315,317,317,319,323,324,320,313,312,315,318,324,322,317,314,310,312,317,320,321,317,312,310,309,315,319,317,315,314,309,309,314,315,317,314,311,309,307,308,312,314,314,313,308,306,308,309,317,315,314,309,303,306,313,314,316,310,308,306,305,307,311,311,310,305,305,303,305,310,310,310,307,305,301,305,308,311,309,308,304,302,302,308,314,311,308,301,297,304,308,311,313,313,307,303,306,310,315,317,313,312,310,309,314,316,317,315,312,311,307,309,314,316,315,313,311,310,313,312,313,315,310,303,300,298,302,305,306,301,297,294,299,301,305,305,303,300,298,296,300,302,303,303,301,298,294,295,298,302,299,298,293,289,284,287,289,286,281,273,280,291,309,327,350,374,394,412,419,417,396,356,318,291,277,279,286,294,297,296,293,290,289,293,293,294,298,292,289,289,287,292,297,299,294,290,287,290,295,298,297,296,292,290,291,294,297,298,297,292,288,287,293,295,296,293,293,289,288,289,292,296,294,292,290,287,288,293,298,297,293,288,287,290,293,297,299,296,290,288,289,292,295,294,293,291,288,289,291,293,294,294,291,289,288,288,288,294,295,293,290,285,288,291,294,296,293,288,285,286,289,296,295,295,289,289,293,297,299,302,302,299,295,299,300,303,305,304,302,299,301,301,304,308,307,308,302,300,301,305,308,309,305,302,298,300,306,308,308,303,301,297,298,304,307,306,304,302,300,296,300,303,305,303,303,299,297,301,303,304,306,304,297,298,297,301,305,307,302,297,294,295,302,307,306,301,299,294,299,298,302,304,301,299,297,298,298,302,304,304,301,298,298,299,302,305,307,305,300,297,298,304,306,307,305,302,297,300,302,308,308,307,300,298,300,304,308,307,310,304,307,305,309,314,314,318,315,310,308,312,316,316,318,315,311,310,308,313,319,318,315,311,311,313,316,316,315,314,307,305,302,307,308,310,307,304,299,301,304,307,308,306,305,301,300,302,306,311,307,306,304,300,303,305,311,308,301,295,288,286,287,291,295,301,313,333,352,381,412,433,437,420,385,339,307,298,297,304,306,303,301,302,308,309,309,306,302,298,303,306,308,309,306,303,299,300,305,310,309,306,302,299,302,304,310,310,308,305,304,306,306,311,309,311,308,305,303,303,308,313,313,310,308,305,304,309,314,315,310,310,305,306,310,316,316,312,309,306,310,313,315,316,314,311,308,308,310,317,315,315,313,310,307,312,315,316,318,315,313,308,309,314,316,319,314,311,309,311,313,321,321,317,313,315,315,319,326,326,324,322,320,318,322,325,329,330,329,326,323,327,330,335,334,332,326,325,326,329,334,336,333,328,324,327,332,334,334,335,328,327,328,330,335,335,333,332,329,327,333,334,335,333,332,329,327,329,332,336,339,333,330,326,329,332,336,338,335,331,324,329,335,337,339,338,332,329,331,334,337,339,337,333,331,331,335,338,339,338,337,334,332,337,338,342,342,341,337,336,338,339,343,343,340,335,334,335,342,344,346,343,337,339,340,346,350,354,349,350,348,346,350,356,359,358,355,353,352,351,354,359,358,355,351,349,350,355,363,364,358,350,348,348,352,353,353,349,348,342,345,346,352,354,350,348,346,348,349,353,353,351,349,345,346,348,351,354,354,351,348,345,344,346,347,344,340,331,328,331,350,363,381,398,421,448,465,474,463,437,396,361,342,338,345,354,356,357,352,350,351,353,356,359,361,357,354,355,354,355,362,362,359,354,353,354,357,362,364,360,357,355,355,358,362,364,362,361,361,357,359,364,366,365,364,360,356,360,361,367,367,366,358,358,359,365,369,369,367,363,364,364,367,371,373,370,366,364,363,366,370,371,370,369,368,368,367,372,373,373,373,369,368,368,369,373,374,373,370,367,365,372,375,378,377,371,369,370,377,380,382,379,376,376,375,383,385,389,383,382,383,383,384,387,392,393,390,388,386,387,392,396,394,393,390,386,385,391,395,395,391,388,385,388,391,396,398,394,388,389,389,392,395,398,397,393,390,390,392,394,398,398,393,393,389,391,397,396,399,395,392,389,392,394,399,401,398,394,390,394,398,399,402,399,395,394,394,399,403,407,404,401,397,398,402,405,405,405,404,400,398,400,405,407,409,406,404,399,402,406,412,413,412,409,406,408,412,419,421,420,416,415,417,420,423,425,420,417,414,416,416,419,420,419,419,420,418,418,418,423,421,417,414,410,408,414,417,420,418,415,410,412,418,418,419,418,413,411,412,417,417,418,418,416,413,413,418,419,421,420,413,407,406,405,404,407,410,417,426,440,461,492,523,538,542,528,496,460,432,422,417,417,415,417,420,423,426,427,425,421,420,420,422,426,430,431,428,424,422,425,427,435,433,430,427,424,425,428,431,432,429,427,425,424,431,434,435,431,429,426,429,433,436,435,437,430,428,431,432,435,438,439,435,433,432,433,437,439,440,438,435,432,434,438,443,446,443,439,436,437,441,446,447,445,438,437,437,440,445,444,441,439,437,437,440,443,443,443,442,439,438,439,444,446,448,444,443,440,442,448,451,455,455,450,448,451,457,461,462,462,459,456,458,463,469,470,466,463,460,464,464,470,471,469,469,466,467,467,470,472,474,471,466,465,466,469,474,475,472,468,464,467,472,475,477,475,471,468,470,474,476,478,476,474,469,471,475,479,479,479,476,474,471,474,477,483,479,478,475,472,473,476,482,482,482,476,475,478,481,484,487,485,479,477,479,484,487,488,483,481,478,479,483,487,488,488,487,486,483,484,490,492,492,491,486,485,487,491,493,494,493,491,487,489,495,500,502,499,493,494,497,500,505,506,506,503,503,502,506,511,511,511};
const size_t ECG_len  = sizeof(ECG_data) / sizeof(uint16_t);

const float b_notch[] = { 1.39972748302835,  -1.79945496605670, 1.39972748302835 };

const float b_lp[] = { 0.00113722762905776, 0.00568613814528881, 0.0113722762905776,  0.0113722762905776,  0.00568613814528881, 0.00113722762905776 };
const float a_lp[] = { 1, -3.03124451613593, 3.92924380774061,  -2.65660499035499, 0.928185738776705, -0.133188755896548 };

const float b_hp[] = { 1, -1 };
const float a_hp[] = { 1, -0.995 };

FIRFilter notch(b_notch);
IIRFilter lp(b_lp, a_lp);
IIRFilter hp(b_hp, a_hp);

void setup() {
  Serial.begin(115200);
  Serial.println("Start");
  Serial.println();

  unsigned long start = micros();
  for (size_t i = 0; i < ECG_len; i++) {
    float value = pgm_read_word_near(ECG_data + i) - 511.0;
    float filtered = notch.filter(lp.filter(hp.filter(value)));
    PORTC = filtered;
    // Serial.println(filtered);
  }
  unsigned long duration = micros() - start;
  unsigned long maxDuration = ECG_len * 1000000UL / 360;
  Serial.println();
  Serial.println("Duration: ");
  Serial.print(duration);
  Serial.println(" µs");
  Serial.println("Maximum duration: ");
  Serial.print(maxDuration);
  Serial.print(" µs");
  Serial.print(" (");
  Serial.print(ECG_len);
  Serial.println(" samples)");
  Serial.println("CPU usage: ");
  Serial.print((float) duration / maxDuration * 100.0);
  Serial.println('%');
}

void loop() { }

void printArray(float *arr, uint8_t len, const char *name) {
  Serial.println(name);
  Serial.println("----");
  for (uint8_t i = 0; i < len; i++) {
    Serial.print(arr[i]);
    Serial.print("  ");
  }
  Serial.println();
}


