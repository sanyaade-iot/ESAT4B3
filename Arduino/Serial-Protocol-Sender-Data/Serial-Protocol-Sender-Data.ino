#include "Serial_Protocol.h"

const word ecg[] PROGMEM = { 499, 495, 495, 498, 499, 503, 502, 497, 492, 488, 491, 491, 491, 489, 485, 489, 496, 507, 527, 550, 577, 598, 611, 614, 607, 588, 556, 526, 505, 493, 490, 496, 503, 506, 508, 506, 507, 502, 504, 508, 510, 512, 512, 510, 503, 503, 507, 510, 515, 514, 511, 508, 505, 506, 508, 517, 521, 514, 512, 507, 510, 511, 517, 517, 515, 511, 511, 511, 514, 518, 519, 518, 518, 515, 514, 515, 520, 520, 522, 518, 514, 514, 515, 520, 521, 527, 524, 520, 517, 518, 523, 526, 526, 524, 522, 518, 519, 523, 528, 528, 527, 524, 520, 523, 525, 530, 528, 529, 526, 524, 523, 525, 529, 530, 530, 526, 523, 522, 525, 528, 530, 532, 531, 527, 521, 525, 530, 533, 536, 533, 529, 525, 528, 534, 539, 542, 538, 534, 535, 535, 539, 544, 546, 545, 544, 539, 539, 544, 548, 551, 549, 550, 549, 545, 546, 549, 551, 555, 552, 549, 547, 548, 552, 555, 553, 552, 549, 547, 547, 550, 555, 555, 555, 548, 548, 547, 552, 556, 559, 555, 554, 550, 550, 552, 556, 559, 560, 556, 551, 549, 550, 556, 556, 560, 557, 552, 551, 553, 557, 562, 562, 562, 556, 552, 556, 558, 562, 563, 561, 554, 553, 553, 560, 562, 563, 560, 559, 558, 560, 558, 561, 565, 565, 562, 559, 560, 561, 562, 568, 567, 566, 563, 561, 562, 564, 570, 574, 570, 566, 563, 563, 565, 573, 575, 573, 570, 568, 569, 571, 578, 579, 580, 579, 577, 577, 578, 580, 583, 583, 581, 578, 575, 577, 582, 584, 585, 584, 581, 580, 577, 578, 581, 580, 578, 573, 568, 571, 576, 578, 581, 579, 574, 571, 571, 575, 578, 580, 578, 576, 572, 573, 577, 578, 580, 582, 582, 576, 574, 576, 577, 579, 578, 573, 567, 560, 559, 560, 568, 577, 586, 598, 611, 636, 664, 691, 709, 713, 708, 690, 662, 633, 609, 596, 583, 576, 569, 569, 574, 581, 586, 587, 583, 581, 581, 581, 583, 589, 588, 589, 580, 578, 579, 585, 586, 589, 587, 583, 582, 582, 585, 588, 591, 587, 584, 581, 582, 585, 587, 591, 590, 587, 583, 582, 585, 587, 591, 593, 588, 586, 586, 588, 590, 595, 595, 594, 591, 585, 587, 593, 598, 600, 596, 592, 586, 589, 593, 598, 601, 596, 590, 589, 590, 593, 597, 599, 598, 592, 591, 591, 591, 596, 599, 598, 596, 592, 590, 592, 592, 597, 599, 596, 593, 589, 590, 592, 598, 600, 599, 592, 589, 590, 596, 599, 603, 600, 597, 598, 600, 603, 608, 613, 612, 610, 608, 609, 611, 613, 615, 618, 614, 611, 612, 610, 614, 617, 619, 617, 616, 612, 610, 616, 619, 622, 619, 613, 613, 614, 616, 618, 622, 619, 617, 615, 617, 620, 622, 622, 622, 617, 616, 614, 617, 621, 623, 624, 621, 617, 615, 615, 620, 624, 624, 622, 619, 613, 616, 619, 624, 625, 623, 619, 616, 617, 623, 624, 627, 624, 620, 619, 619, 622, 625, 625, 624, 623, 617, 620, 621, 625, 627, 629, 627, 622, 621, 622, 625, 629, 630, 627, 623, 620, 621, 626, 629, 634, 629, 626, 623, 625, 628, 631, 631, 630, 624, 624, 625, 629, 637, 638, 638, 635, 630, 634, 635, 639, 642, 644, 641, 640, 639, 639, 641, 645, 646, 643, 639, 637, 636, 639, 642, 646, 649, 644, 639, 637, 641, 645, 643, 640, 635, 630, 631, 633, 636, 638, 635, 631, 631, 631, 630, 635, 637, 637, 635, 631, 629, 630, 634, 637, 637, 637, 632, 628, 628, 629, 632, 629, 626, 619, 610, 611, 618, 635, 653, 668, 685, 711, 738, 761, 771, 762, 729, 680, 639, 619, 622, 631, 637, 640, 636, 632, 632, 633, 635, 639, 638, 639, 636, 631, 632, 636, 640, 642, 639, 636, 630, 631, 634, 640, 639, 640, 633, 632, 632, 636, 640, 641, 639, 638, 633, 634, 636, 638, 642, 644, 642, 636, 634, 637, 639, 644, 646, 640, 638, 634, 634, 639, 643, 643, 643, 638, 634, 636, 637, 644, 647, 642, 637, 637, 638, 640, 645, 646, 645, 643, 641, 637, 642, 645, 646, 646, 645, 640, 639, 640, 642, 645, 648, 645, 641, 637, 638, 641, 646, 648, 645, 641, 638, 639, 641, 646, 650, 649, 648, 646, 648, 650, 658, 656, 656, 654, 651, 651, 653, 656, 661, 659, 657, 654, 652, 653, 656, 660, 661, 658, 654, 650, 651, 656, 659, 663, 658, 652, 652, 653, 658, 661, 660, 660, 655, 652, 654, 653, 659, 656, 657, 656, 652, 651, 651, 655, 655, 656, 655, 651, 649, 650, 653, 656, 659, 656, 651, 650, 649, 654, 658, 658, 658, 650, 648, 647, 651, 657, 658, 657, 651, 650, 648, 653, 660, 659, 656, 652, 652, 650, 656, 657, 658, 657, 655, 652, 651, 650, 653, 659, 659, 657, 653, 651, 650, 655, 659, 659, 658, 658, 655, 655, 659, 663, 666, 662, 659, 660, 658, 662, 666, 666, 667, 664, 662, 663, 665, 667, 667, 668, 666, 662, 660, 661, 665, 667, 669, 664, 665, 662, 664, 663, 664, 665, 658, 653, 648, 649, 656, 657, 659, 655, 652, 650, 650, 653, 657, 659, 653, 652, 652, 650, 652, 655, 655, 655, 653, 651, 647, 648, 648, 649, 646, 643, 637, 634, 628, 629, 634, 640, 645, 653, 663, 678, 700, 732, 760, 776, 778, 764, 736, 698, 665, 647, 644, 645, 647, 650, 650, 653, 656, 655, 653, 650, 648, 650, 653, 656, 655, 653, 650, 647, 648, 651, 657, 655, 655, 649, 647, 645, 653, 657, 655, 655, 653, 647, 647, 649, 653, 655, 657, 651, 649, 648, 652, 656, 656, 657, 655, 652, 648, 648, 653, 657, 658, 655, 651, 647, 647, 654, 658, 657, 656, 650, 649, 647, 652, 656, 657, 655, 651, 649, 648, 651, 657, 656, 653, 654, 649, 646, 650, 653, 654, 657, 653, 651, 646, 648, 653, 657, 656, 654, 647, 646, 646, 651, 656, 658, 654, 651, 651, 650, 656, 661, 661, 660, 657, 655, 655, 657, 661, 665, 662, 659, 658, 654, 658, 660, 662, 662, 662, 655, 653, 653, 659, 664, 665, 661, 656, 653, 653, 657, 660, 661, 660, 655, 652, 654, 655, 659, 658, 658, 654, 651, 651, 654, 655, 656, 658, 654, 649, 652, 652, 655, 656, 658, 655, 651, 647, 647, 651, 655, 656, 651, 648, 645, 646, 651, 654, 656, 653, 649, 645, 645, 652, 653, 653, 653, 646, 642, 645, 648, 651, 652, 651, 650, 644, 643, 646, 646, 652, 649, 648, 643, 643, 644, 649, 652, 653, 649, 644, 643, 645, 648, 653, 655, 651, 649, 648, 647, 652, 656, 658, 659, 651, 650, 652, 653, 657, 657, 656, 655, 653, 648, 648, 655, 656, 654, 653, 648, 647, 650, 653, 655, 654, 648, 644, 638, 640, 642, 648, 648, 643, 639, 637, 636, 641, 644, 645, 643, 638, 634, 633, 636, 639, 641, 640, 637, 635, 634, 634, 638, 642, 641, 640, 634, 630, 633, 635, 633, 633, 625, 617, 611, 612, 623, 640, 654, 667, 688, 716, 736, 751, 751, 726, 686, 650, 625, 617, 621, 628, 633, 633, 631, 626, 625, 624, 628, 630, 632, 630, 624, 623, 623, 628, 632, 634, 628, 624, 623, 625, 626, 629, 634, 630, 621, 618, 621, 625, 628, 627, 627, 622, 620, 621, 624, 624, 628, 627, 623, 621, 616, 620, 623, 626, 623, 624, 619, 618, 618, 623, 627, 627, 621, 617, 614, 615, 620, 624, 624, 621, 618, 616, 616, 619, 621, 622, 620, 617, 614, 614, 618, 618, 619, 618, 615, 613, 609, 610, 612, 614, 616, 611, 606, 606, 606, 610, 616, 616, 613, 606, 606, 608, 610, 615, 617, 612, 611, 607, 611, 615, 619, 622, 618, 615, 615, 616, 621, 623, 624, 623, 617, 615, 616, 616, 619, 622, 621, 619, 618, 614, 612, 618, 621, 622, 620, 613, 614, 615, 620, 623, 622, 619, 613, 612, 612, 614, 617, 617, 615, 611, 609, 608, 610, 612, 614, 615, 611, 608, 606, 606, 608, 612, 612, 610, 605, 604, 605, 608, 610, 611, 609, 605, 602, 605, 607, 612, 612, 608, 602, 599, 600, 603, 609, 609, 606, 603, 599, 601, 602, 604, 609, 604, 603, 598, 599, 600, 603, 605, 605, 603, 599, 595, 595, 599, 605, 607, 602, 600, 598, 601, 605, 609, 611, 606, 604, 602, 602, 606, 609, 611, 608, 606, 601, 603, 602, 606, 607, 607, 603, 600, 596, 599, 604, 606, 609, 606, 601, 597, 595, 598, 601, 602, 596, 589, 586, 587, 590, 592, 592, 591, 585, 584, 584, 588, 590, 592, 587, 586, 582, 580, 585, 585, 585, 588, 585, 581, 578, 582, 582, 581, 582, 575, 570, 565, 561, 562, 568, 570, 578, 582, 595, 615, 647, 680, 698, 703, 691, 662, 624, 590, 573, 567, 566, 566, 567, 568, 569, 574, 576, 575, 573, 568, 567, 567, 569, 572, 572, 570, 567, 562, 563, 567, 570, 574, 569, 562, 559, 560, 566, 568, 571, 564, 563, 560, 561, 562, 567, 568, 563, 561, 558, 558, 562, 563, 564, 563, 561, 557, 554, 557, 558, 561, 562, 558, 556, 553, 553, 556, 563, 563, 559, 553, 550, 551, 554, 556, 556, 556, 550, 550, 551, 552, 557, 558, 553, 553, 550, 548, 550, 554, 554, 553, 550, 547, 543, 544, 546, 549, 550, 548, 544, 540, 539, 544, 547, 548, 545, 539, 537, 540, 544, 548, 549, 548, 543, 544, 548, 551, 552, 556, 554, 552, 548, 550, 550, 554, 555, 555, 552, 549, 545, 550, 552, 556, 553, 552, 548, 547, 547, 551, 555, 556, 552, 549, 544, 545, 549, 553, 552, 549, 543, 541, 540, 546, 547, 548, 545, 539, 540, 537, 541, 543, 542, 542, 541, 535, 533, 535, 538, 542, 543, 537, 534, 531, 532, 535, 540, 540, 537, 531, 529, 529, 534, 537, 537, 534, 531, 526, 528, 532, 535, 535, 534, 530, 526, 526, 528, 531, 532, 529, 531, 526, 523, 524, 528, 531, 531, 527, 524, 522, 522, 527, 529, 529, 526, 521, 517, 519, 522, 530, 529, 527, 523, 519, 524, 527, 529, 532, 531, 526, 525, 523, 527, 532, 534, 530, 528, 525, 524, 523, 526, 530, 528, 529, 521, 519, 520, 523, 529, 531, 526, 518, 513, 511, 517, 518, 517, 514, 510, 507, 503, 511, 515, 511, 511, 506, 505, 505, 506, 509, 508, 507, 505, 503, 499, 500, 505, 508, 507, 504, 501, 497, 497, 500, 503, 500, 491, 484, 479, 480, 481, 486, 494, 508, 515, 536, 558, 588, 615, 630, 626, 607, 570, 527, 499, 487, 488, 489, 492, 489, 488, 490, 490, 494, 493, 491, 486, 484, 482, 488, 493, 492, 491, 483, 480, 482, 485, 488, 488, 485, 480, 477, 477, 481, 483, 483, 482, 480, 476, 476, 479, 481, 482, 481, 480, 476, 477, 476, 481, 481, 484, 478, 475, 474, 474, 479, 480, 482, 479, 473, 469, 469, 474, 479, 478, 474, 469, 468, 468, 471, 475, 475, 471, 469, 465, 466, 468, 473, 475, 475, 471, 466, 465, 464, 466, 469, 469, 465, 464, 462, 461, 466, 467, 469, 468, 462, 459, 462, 466, 467, 468, 466, 458, 459, 459, 463, 464, 467, 464, 460, 457, 458, 462, 467, 469, 468, 464, 463, 463, 464, 467, 472, 472, 467, 463, 461, 461, 467, 468, 468, 465, 462, 458, 459, 462, 467, 466, 463, 458, 456, 456, 457, 463, 465, 460, 460, 454, 455, 457, 460, 460, 458, 456, 454, 452, 455, 457, 459, 458, 455, 454, 452, 453, 457, 460, 461, 460, 452, 452, 452, 459, 461, 458, 455, 455, 453, 454, 456, 455, 457, 455, 452, 447, 446, 447, 448, 448, 446, 444, 437, 435, 436, 438, 441, 442, 437, 433, 430, 431, 436, 438, 439, 436, 431, 427, 431, 434, 436, 437, 434, 431, 429, 427, 432, 434, 434, 433, 426, 423, 419, 421, 420, 416, 414, 408, 405, 405, 416, 433, 453, 469, 487, 511, 529, 543, 549, 539, 506, 458, 423, 408, 409, 418, 426, 425, 422, 415, 414, 414, 418, 421, 420, 419, 417, 414, 413, 413, 414, 419, 417, 415, 410, 411, 410, 414, 417, 417, 414, 410, 404, 407, 411, 411, 416, 411, 410, 405, 404, 410, 414, 415, 410, 405, 404, 403, 408, 409, 410, 407, 406, 403, 402, 407, 406, 407, 405, 405, 401, 401, 399, 405, 408, 407, 404, 399, 398, 396, 402, 406, 406, 404, 398, 395, 396, 400, 404, 404, 402, 396, 391, 394, 398, 401, 403, 399, 394, 391, 392, 391, 397, 396, 394, 394, 389, 389, 389, 391, 396, 398, 394, 391, 387, 387, 391, 398, 397, 395, 388, 386, 389, 395, 396, 401, 398, 389, 393, 391, 396, 400, 399, 396, 394, 391, 390, 394, 392, 398, 394, 391, 388, 387, 391, 393, 396, 395, 392, 388, 383, 386, 388, 392, 395, 392, 386, 382, 382, 387, 391, 393, 387, 384, 379, 381, 381, 385, 384, 383, 381, 378, 375, 379, 384, 383, 383, 378, 378, 373, 375, 381, 382, 380, 379, 376, 373, 373, 377, 381, 380, 376, 374, 371, 371, 375, 380, 380, 374, 371, 368, 371, 372, 375, 377, 373, 369, 367, 366, 367, 371, 370, 375, 369, 366, 367, 369, 370, 373, 373, 367, 366, 362, 363, 368, 370, 371, 368, 363, 359, 359, 365, 367, 367, 366, 362, 359, 360, 364, 365, 366, 365, 362, 361, 358, 361, 366, 367, 367, 361, 359, 358, 359, 361, 364, 364, 360, 357, 353, 355, 359, 365, 363, 359, 354, 349, 352, 357, 360, 361, 357, 356, 353, 354, 353, 361, 360, 360, 355, 350, 352, 351, 358, 357, 358, 352, 351, 351, 352, 356, 361, 361, 358, 353, 352, 353, 358, 364, 363, 362, 356, 355, 356, 358, 361, 363, 358, 353, 352, 352, 356, 359, 359, 353, 350, 350, 351, 352, 359, 358, 354, 350, 345, 345, 342, 346, 348, 349, 345, 339, 336, 340, 344, 347, 347, 340, 335, 331, 334, 338, 342, 345, 338, 334, 330, 334, 335, 337, 340, 335, 332, 326, 322, 325, 324, 321, 318, 323, 328, 337, 352, 375, 398, 426, 445, 455, 458, 450, 427, 398, 369, 345, 326, 315, 314, 317, 324, 327, 328, 323, 322, 324, 329, 330, 332, 329, 327, 321, 320, 324, 326, 327, 324, 323, 322, 320, 321, 324, 326, 328, 324, 320, 319, 319, 320, 326, 326, 324, 318, 316, 318, 322, 327, 325, 322, 318, 316, 317, 321, 322, 323, 322, 318, 315, 316, 317, 320, 321, 320, 317, 314, 313, 314, 318, 322, 320, 319, 316, 313, 314, 320, 323, 322, 318, 316, 312, 311, 320, 323, 323, 321, 311, 313, 314, 316, 319, 318, 312, 309, 310, 304, 307, 311, 312, 309, 309, 303, 302, 305, 303, 311, 311, 307, 303, 300, 300, 307, 310, 311, 310, 304, 303, 304, 311, 314, 314, 316, 311, 309, 309, 316, 321, 322, 320, 318, 313, 315, 320, 320, 323, 324, 322, 317, 314, 317, 318, 322, 322, 320, 314, 313, 313, 318, 322, 323, 318, 313, 311, 311, 315, 319, 320, 319, 310, 310, 312, 314, 318, 318, 317, 313, 309, 311, 314, 315, 314, 315, 313, 309, 308, 307, 310, 316, 315, 312, 308, 305, 308, 312, 315, 317, 314, 308, 304, 305, 309, 313, 314, 310, 307, 306, 306, 308, 311, 312, 307, 306, 304, 305, 305, 309, 311, 310, 307, 303, 303, 303, 308, 311, 310, 309, 304, 301, 301, 305, 311, 312, 308, 304, 300, 302, 305, 313, 313, 311, 308, 307, 306, 311, 316, 318, 317, 311, 309, 308, 314, 316, 317, 317, 311, 310, 308, 307, 311, 315, 314, 310, 310, 308, 312, 312, 313, 313, 309, 303, 299, 299, 302, 306, 306, 304, 297, 294, 296, 302, 303, 305, 301, 299, 297, 295, 298, 300, 303, 301, 301, 296, 292, 296, 297, 301, 301, 298, 293, 289, 285, 286, 288, 287, 280, 275, 278, 291, 310, 329, 349, 372, 392, 411, 419, 417, 395, 356, 318, 289, 280, 282, 287, 293, 297, 296, 292, 290, 290, 290, 292, 296, 295, 293, 290, 287, 287, 294, 299, 296, 292, 290, 286, 291, 293, 298, 298, 296, 291, 290, 290, 291, 296, 300, 295, 293, 289, 289, 292, 296, 297, 294, 292, 289, 289, 290, 293, 296, 297, 294, 289, 287, 288, 294, 296, 297, 294, 291, 288, 289, 293, 296, 299, 294, 288, 286, 288, 291, 294, 297, 293, 292, 289, 289, 291, 292, 292, 294, 293, 289, 288, 288, 290, 294, 296, 292, 290, 286, 287, 290, 296, 296, 293, 290, 284, 285, 291, 294, 296, 293, 289, 289, 290, 296, 301, 301, 300, 299, 296, 299, 300, 304, 303, 305, 302, 299, 301, 301, 306, 307, 307, 306, 303, 297, 299, 305, 308, 310, 305, 302, 298, 300, 305, 308, 308, 305, 301, 299, 300, 300, 306, 306, 305, 303, 301, 298, 302, 306, 304, 303, 301, 299, 299, 299, 301, 302, 306, 301, 298, 296, 296, 301, 304, 307, 303, 299, 293, 297, 301, 306, 306, 302, 297, 293, 299, 302, 305, 303, 301, 299, 296, 296, 299, 302, 304, 305, 302, 299, 296, 298, 300, 304, 306, 304, 301, 297, 296, 302, 305, 307, 306, 300, 295, 298, 304, 307, 308, 303, 300, 298, 300, 306, 307, 310, 309, 307, 306, 305, 310, 315, 316, 314, 314, 311, 307, 313, 315, 319, 318, 314, 310, 308, 308, 315, 317, 316, 317, 311, 311, 314, 316, 317, 317, 313, 308, 302, 304, 307, 309, 312, 304, 304, 301, 302, 303, 307, 308, 307, 304, 301, 300, 301, 304, 307, 309, 309, 303, 302, 300, 304, 309, 310, 302, 293, 286, 287, 292, 288, 296, 305, 316, 330, 351, 381, 413, 434, 437, 419, 383, 339, 308, 298, 298, 305, 306, 303, 301, 303, 305, 309, 311, 306, 302, 300, 301, 306, 309, 309, 307, 303, 298, 301, 304, 307, 310, 308, 300, 300, 303, 306, 310, 310, 311, 304, 302, 304, 306, 309, 310, 312, 307, 303, 303, 305, 308, 313, 313, 311, 307, 303, 304, 309, 313, 315, 312, 309, 307, 307, 310, 316, 316, 313, 308, 308, 307, 313, 316, 315, 314, 312, 307, 308, 313, 314, 317, 317, 313, 311, 308, 310, 316, 318, 319, 314, 311, 309, 308, 313, 316, 320, 317, 313, 309, 310, 316, 320, 323, 320, 313, 315, 315, 322, 325, 325, 326, 320, 318, 320, 322, 326, 330, 331, 328, 326, 324, 324, 327, 333, 335, 332, 328, 325, 325, 331, 335, 333, 332, 327, 326, 327, 330, 337, 336, 333, 328, 325, 325, 331, 336, 336, 334, 330, 329, 329, 331, 334, 335, 334, 334, 328, 328, 332, 331, 337, 336, 334, 329, 327, 327, 331, 337, 336, 336, 330, 326, 330, 333, 338, 337, 335, 331, 330, 332, 336, 338, 338, 336, 334, 333, 332, 337, 337, 339, 338, 335, 334, 331, 335, 339, 341, 341, 339, 337, 334, 336, 339, 342, 342, 341, 335, 334, 335, 342, 344, 346, 342, 339, 338, 341, 347, 350, 352, 350, 349, 348, 346, 351, 358, 359, 358, 355, 352, 353, 352, 357, 358, 359, 355, 352, 350, 349, 356, 364, 365, 359, 351, 350, 349, 351, 353, 352, 351, 346, 342, 346, 350, 353, 353, 351, 348, 345, 345, 350, 352, 353, 353, 349, 347, 345, 347, 349, 354, 353, 350, 347, 343, 342, 343, 346, 343, 341, 331, 328, 332, 350, 364, 382, 398, 423, 447, 464, 474, 462, 435, 395, 359, 341, 337, 344, 352, 355, 358, 355, 349, 350, 352, 354, 359, 361, 356, 355, 353, 353, 359, 360, 362, 359, 356, 352, 352, 357, 361, 363, 359, 357, 354, 358, 360, 364, 364, 361, 360, 357, 359, 361, 363, 365, 364, 363, 362, 358, 361, 361, 366, 368, 364, 359, 359, 359, 364, 369, 368, 369, 363, 364, 364, 369, 372, 373, 368, 367, 364, 362, 365, 372, 373, 370, 370, 367, 365, 366, 372, 375, 373, 372, 368, 367, 368, 370, 374, 377, 372, 369, 366, 366, 372, 375, 378, 375, 370, 369, 370, 374, 382, 382, 381, 376, 375, 377, 381, 384, 390, 385, 383, 382, 384, 384, 389, 390, 394, 390, 387, 385, 387, 391, 396, 394, 393, 388, 388, 383, 390, 394, 395, 393, 388, 386, 388, 392, 395, 396, 393, 389, 387, 388, 393, 394, 399, 394, 393, 390, 391, 394, 397, 396, 398, 392, 390, 388, 389, 395, 399, 399, 395, 391, 390, 391, 397, 398, 402, 398, 394, 392, 394, 398, 402, 403, 400, 397, 395, 394, 401, 401, 405, 403, 401, 397, 399, 402, 404, 407, 406, 403, 399, 398, 400, 403, 408, 410, 405, 402, 399, 402, 407, 411, 413, 413, 410, 408, 408, 413, 420, 421, 420, 415, 414, 416, 419, 424, 424, 421, 417, 413, 416, 417, 419, 421, 421, 419, 420, 418, 417, 418, 421, 422, 417, 411, 410, 410, 412, 417, 420, 418, 414, 410, 412, 414, 419, 421, 419, 414, 411, 410, 414, 419, 420, 418, 417, 410, 413, 416, 420, 422, 418, 412, 407, 406, 405, 404, 407, 412, 415, 427, 439, 461, 494, 525, 539, 542, 527, 495, 458, 432, 421, 418, 415, 414, 415, 418, 423, 427, 427, 426, 420, 421, 421, 422, 426, 430, 430, 427, 424, 423, 424, 428, 434, 432, 431, 428, 424, 425, 429, 432, 433, 430, 426, 423, 426, 429, 432, 436, 431, 428, 427, 430, 434, 435, 437, 436, 433, 430, 430, 432, 434, 438, 439, 436, 431, 430, 432, 435, 440, 442, 439, 433, 433, 435, 439, 444, 445, 442, 439, 435, 437, 442, 445, 448, 445, 439, 437, 438, 440, 442, 443, 443, 441, 438, 439, 440, 444, 442, 445, 442, 438, 438, 440, 443, 447, 448, 445, 443, 442, 441, 448, 450, 455, 453, 449, 448, 451, 455, 460, 463, 462, 458, 455, 460, 463, 464, 469, 467, 463, 462, 462, 465, 470, 470, 471, 466, 465, 465, 468, 470, 473, 473, 472, 469, 466, 466, 469, 474, 475, 472, 468, 464, 468, 472, 476, 476, 471, 471, 469, 467, 473, 475, 478, 476, 473, 471, 472, 475, 476, 479, 478, 478, 475, 472, 475, 477, 482, 481, 479, 477, 474, 474, 479, 483, 484, 483, 476, 473, 478, 482, 485, 486, 483, 480, 476, 480, 482, 487, 489, 484, 482, 478, 481, 484, 486, 489, 491, 486, 483, 483, 484, 486, 492, 492, 490, 487, 484, 487, 489, 494, 495, 493, 488, 488, 489, 495, 500, 500, 499, 495, 495, 495, 501, 506, 507, 506, 502, 500, 502, 506, 508, 511, 508 };
const size_t datalength  = sizeof(ecg) / sizeof(uint16_t);

const float samplefreq = 360e0;

void setup() {
  Serial.begin(1000000);
  while (!Serial);
}

const unsigned long interval = round(1e6 / samplefreq);

void loop() {
  static uint16_t index = 0;
  static unsigned long prevmicros = micros();
  if (micros() - prevmicros >= interval) {
    uint16_t value = pgm_read_word_near(ecg + index);
    send(value, ECG);
    index = (index + 1) % datalength;
    prevmicros += interval;
  }
}

