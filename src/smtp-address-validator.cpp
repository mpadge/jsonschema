/*

Snarfed from <https://github.com/gene-hightower/smtp-address-validator>

<http://opensource.org/licenses/MIT>:

Copyright (c) 2021 Gene Hightower

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#line 1 "smtp-address-validator.rl"
#include "smtp-address-validator.h"

#line 110 "smtp-address-validator.rl"

#line 7 "smtp-address-validator.cpp"
static const signed char _address_actions[] = {
    0, 1, 0, 1, 1, 0};

static const short _address_key_offsets[] = {
	0, 0, 24, 26, 50, 52, 54, 56,
	58, 60, 62, 86, 103, 105, 107, 109,
	111, 113, 115, 117, 134, 150, 161, 168,
	176, 180, 181, 190, 195, 196, 201, 202,
	207, 210, 213, 219, 222, 225, 228, 234,
	237, 240, 243, 249, 252, 261, 270, 282,
	293, 302, 311, 320, 328, 345, 353, 360,
	367, 368, 375, 382, 389, 396, 397, 404,
	411, 418, 425, 426, 433, 440, 447, 454,
	455, 462, 469, 476, 483, 484, 491, 498,
	505, 512, 513, 523, 531, 538, 545, 546,
	552, 559, 566, 573, 581, 589, 597, 608,
	618, 626, 634, 641, 649, 657, 665, 667,
	673, 681, 689, 697, 699, 705, 713, 721,
	729, 731, 737, 745, 753, 761, 763, 769,
	777, 785, 793, 795, 802, 812, 821, 829,
	837, 839, 848, 857, 865, 873, 875, 884,
	893, 901, 909, 911, 920, 929, 937, 945,
	947, 956, 965, 974, 983, 992, 1004, 1015,
	1024, 1033, 1042, 1051, 1060, 1072, 1083, 1092,
	1101, 1109, 1118, 1127, 1136, 1148, 1159, 1168,
	1177, 1185, 1194, 1203, 1212, 1224, 1235, 1244,
	1253, 1261, 1270, 1279, 1288, 1300, 1311, 1320,
	1329, 1337, 1339, 1353, 1355, 1357, 1359, 1361,
	1363, 1365, 1367, 1368, 1370, 1388, 0
};

static const signed char _address_trans_keys[] = {
	-32, -19, -16, -12, 34, 45, 61, 63,
	-62, -33, -31, -17, -15, -13, 33, 39,
	42, 43, 47, 57, 65, 90, 94, 126,
	-128, -65, -32, -19, -16, -12, 33, 46,
	61, 64, -62, -33, -31, -17, -15, -13,
	35, 39, 42, 43, 45, 57, 63, 90,
	94, 126, -96, -65, -128, -65, -128, -97,
	-112, -65, -128, -65, -128, -113, -32, -19,
	-16, -12, 33, 45, 61, 63, -62, -33,
	-31, -17, -15, -13, 35, 39, 42, 43,
	47, 57, 65, 90, 94, 126, -32, -19,
	-16, -12, 91, -62, -33, -31, -17, -15,
	-13, 48, 57, 65, 90, 97, 122, -128,
	-65, -96, -65, -128, -65, -128, -97, -112,
	-65, -128, -65, -128, -113, -32, -19, -16,
	-12, 45, -62, -33, -31, -17, -15, -13,
	48, 57, 65, 90, 97, 122, -32, -19,
	-16, -12, -62, -33, -31, -17, -15, -13,
	48, 57, 65, 90, 97, 122, 45, 48,
	49, 50, 73, 51, 57, 65, 90, 97,
	122, 45, 48, 57, 65, 90, 97, 122,
	45, 58, 48, 57, 65, 90, 97, 122,
	33, 90, 94, 126, 93, 45, 46, 58,
	48, 57, 65, 90, 97, 122, 48, 49,
	50, 51, 57, 46, 48, 49, 50, 51,
	57, 46, 48, 49, 50, 51, 57, 93,
	48, 57, 93, 48, 57, 53, 93, 48,
	52, 54, 57, 93, 48, 53, 46, 48,
	57, 46, 48, 57, 46, 53, 48, 52,
	54, 57, 46, 48, 53, 46, 48, 57,
	46, 48, 57, 46, 53, 48, 52, 54,
	57, 46, 48, 53, 45, 46, 58, 48,
	57, 65, 90, 97, 122, 45, 46, 58,
	48, 57, 65, 90, 97, 122, 45, 46,
	53, 58, 48, 52, 54, 57, 65, 90,
	97, 122, 45, 46, 58, 48, 53, 54,
	57, 65, 90, 97, 122, 45, 58, 80,
	48, 57, 65, 90, 97, 122, 45, 58,
	118, 48, 57, 65, 90, 97, 122, 45,
	54, 58, 48, 57, 65, 90, 97, 122,
	45, 58, 48, 57, 65, 90, 97, 122,
	58, 33, 47, 48, 57, 59, 64, 65,
	70, 71, 90, 94, 96, 97, 102, 103,
	126, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 48, 57, 65, 70, 97, 102,
	58, 48, 57, 65, 70, 97, 102, 58,
	58, 48, 57, 65, 70, 97, 102, 58,
	48, 57, 65, 70, 97, 102, 58, 48,
	57, 65, 70, 97, 102, 58, 48, 57,
	65, 70, 97, 102, 58, 58, 48, 57,
	65, 70, 97, 102, 58, 48, 57, 65,
	70, 97, 102, 58, 48, 57, 65, 70,
	97, 102, 58, 48, 57, 65, 70, 97,
	102, 58, 58, 48, 57, 65, 70, 97,
	102, 58, 48, 57, 65, 70, 97, 102,
	58, 48, 57, 65, 70, 97, 102, 58,
	48, 57, 65, 70, 97, 102, 58, 58,
	48, 57, 65, 70, 97, 102, 58, 48,
	57, 65, 70, 97, 102, 58, 48, 57,
	65, 70, 97, 102, 58, 48, 57, 65,
	70, 97, 102, 58, 58, 48, 57, 65,
	70, 97, 102, 58, 48, 57, 65, 70,
	97, 102, 58, 48, 57, 65, 70, 97,
	102, 58, 48, 57, 65, 70, 97, 102,
	58, 48, 49, 50, 58, 51, 57, 65,
	70, 97, 102, 46, 58, 48, 57, 65,
	70, 97, 102, 58, 48, 57, 65, 70,
	97, 102, 58, 48, 57, 65, 70, 97,
	102, 58, 48, 57, 65, 70, 97, 102,
	93, 48, 57, 65, 70, 97, 102, 93,
	48, 57, 65, 70, 97, 102, 93, 48,
	57, 65, 70, 97, 102, 46, 58, 48,
	57, 65, 70, 97, 102, 46, 58, 48,
	57, 65, 70, 97, 102, 46, 58, 48,
	57, 65, 70, 97, 102, 46, 53, 58,
	48, 52, 54, 57, 65, 70, 97, 102,
	46, 58, 48, 53, 54, 57, 65, 70,
	97, 102, 46, 58, 48, 57, 65, 70,
	97, 102, 46, 58, 48, 57, 65, 70,
	97, 102, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 58, 48, 57, 65, 70,
	97, 102, 48, 49, 50, 93, 51, 57,
	65, 70, 97, 102, 46, 58, 93, 48,
	57, 65, 70, 97, 102, 58, 93, 48,
	57, 65, 70, 97, 102, 58, 93, 48,
	57, 65, 70, 97, 102, 58, 93, 48,
	49, 50, 51, 57, 65, 70, 97, 102,
	46, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 49, 50, 51, 57,
	65, 70, 97, 102, 46, 58, 93, 48,
	57, 65, 70, 97, 102, 58, 93, 48,
	57, 65, 70, 97, 102, 58, 93, 48,
	57, 65, 70, 97, 102, 58, 93, 48,
	49, 50, 51, 57, 65, 70, 97, 102,
	46, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 49, 50, 51, 57,
	65, 70, 97, 102, 46, 58, 93, 48,
	57, 65, 70, 97, 102, 46, 58, 93,
	48, 57, 65, 70, 97, 102, 46, 58,
	93, 48, 57, 65, 70, 97, 102, 46,
	58, 93, 48, 57, 65, 70, 97, 102,
	46, 53, 58, 93, 48, 52, 54, 57,
	65, 70, 97, 102, 46, 58, 93, 48,
	53, 54, 57, 65, 70, 97, 102, 46,
	58, 93, 48, 57, 65, 70, 97, 102,
	46, 58, 93, 48, 57, 65, 70, 97,
	102, 46, 58, 93, 48, 57, 65, 70,
	97, 102, 46, 58, 93, 48, 57, 65,
	70, 97, 102, 46, 58, 93, 48, 57,
	65, 70, 97, 102, 46, 53, 58, 93,
	48, 52, 54, 57, 65, 70, 97, 102,
	46, 58, 93, 48, 53, 54, 57, 65,
	70, 97, 102, 46, 58, 93, 48, 57,
	65, 70, 97, 102, 46, 58, 93, 48,
	57, 65, 70, 97, 102, 58, 93, 48,
	57, 65, 70, 97, 102, 46, 58, 93,
	48, 57, 65, 70, 97, 102, 46, 58,
	93, 48, 57, 65, 70, 97, 102, 46,
	58, 93, 48, 57, 65, 70, 97, 102,
	46, 53, 58, 93, 48, 52, 54, 57,
	65, 70, 97, 102, 46, 58, 93, 48,
	53, 54, 57, 65, 70, 97, 102, 46,
	58, 93, 48, 57, 65, 70, 97, 102,
	46, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 46, 58, 93, 48, 57, 65, 70,
	97, 102, 46, 58, 93, 48, 57, 65,
	70, 97, 102, 46, 58, 93, 48, 57,
	65, 70, 97, 102, 46, 53, 58, 93,
	48, 52, 54, 57, 65, 70, 97, 102,
	46, 58, 93, 48, 53, 54, 57, 65,
	70, 97, 102, 46, 58, 93, 48, 57,
	65, 70, 97, 102, 46, 58, 93, 48,
	57, 65, 70, 97, 102, 58, 93, 48,
	57, 65, 70, 97, 102, 46, 58, 93,
	48, 57, 65, 70, 97, 102, 46, 58,
	93, 48, 57, 65, 70, 97, 102, 46,
	58, 93, 48, 57, 65, 70, 97, 102,
	46, 53, 58, 93, 48, 52, 54, 57,
	65, 70, 97, 102, 46, 58, 93, 48,
	53, 54, 57, 65, 70, 97, 102, 46,
	58, 93, 48, 57, 65, 70, 97, 102,
	46, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, 48, 57, 65, 70, 97,
	102, 58, 93, -32, -19, -16, -12, 34,
	92, -62, -33, -31, -17, -15, -13, 32,
	126, -128, -65, -96, -65, -128, -65, -128,
	-97, -112, -65, -128, -65, -128, -113, 64,
	32, 126, -32, -19, -16, -12, 45, 46,
	-62, -33, -31, -17, -15, -13, 48, 57,
	65, 90, 97, 122, 0
};

static const signed char _address_single_lengths[] = {
	0, 8, 0, 8, 0, 0, 0, 0,
	0, 0, 8, 5, 0, 0, 0, 0,
	0, 0, 0, 5, 4, 5, 1, 2,
	0, 1, 3, 3, 1, 3, 1, 3,
	1, 1, 2, 1, 1, 1, 2, 1,
	1, 1, 2, 1, 3, 3, 4, 3,
	3, 3, 3, 2, 1, 2, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 4, 2, 1, 1, 1, 0,
	1, 1, 1, 2, 2, 2, 3, 2,
	2, 2, 1, 2, 2, 2, 2, 0,
	2, 2, 2, 2, 0, 2, 2, 2,
	2, 0, 2, 2, 2, 2, 0, 2,
	2, 2, 2, 1, 4, 3, 2, 2,
	2, 3, 3, 2, 2, 2, 3, 3,
	2, 2, 2, 3, 3, 2, 2, 2,
	3, 3, 3, 3, 3, 4, 3, 3,
	3, 3, 3, 3, 4, 3, 3, 3,
	2, 3, 3, 3, 4, 3, 3, 3,
	2, 3, 3, 3, 4, 3, 3, 3,
	2, 3, 3, 3, 4, 3, 3, 3,
	2, 2, 6, 0, 0, 0, 0, 0,
	0, 0, 1, 0, 6, 0, 0
};

static const signed char _address_range_lengths[] = {
	0, 8, 1, 8, 1, 1, 1, 1,
	1, 1, 8, 6, 1, 1, 1, 1,
	1, 1, 1, 6, 6, 3, 3, 3,
	2, 0, 3, 1, 0, 1, 0, 1,
	1, 1, 2, 1, 1, 1, 2, 1,
	1, 1, 2, 1, 3, 3, 4, 4,
	3, 3, 3, 3, 8, 3, 3, 3,
	0, 3, 3, 3, 3, 0, 3, 3,
	3, 3, 0, 3, 3, 3, 3, 0,
	3, 3, 3, 3, 0, 3, 3, 3,
	3, 0, 3, 3, 3, 3, 0, 3,
	3, 3, 3, 3, 3, 3, 4, 4,
	3, 3, 3, 3, 3, 3, 0, 3,
	3, 3, 3, 0, 3, 3, 3, 3,
	0, 3, 3, 3, 3, 0, 3, 3,
	3, 3, 0, 3, 3, 3, 3, 3,
	0, 3, 3, 3, 3, 0, 3, 3,
	3, 3, 0, 3, 3, 3, 3, 0,
	3, 3, 3, 3, 3, 4, 4, 3,
	3, 3, 3, 3, 4, 4, 3, 3,
	3, 3, 3, 3, 4, 4, 3, 3,
	3, 3, 3, 3, 4, 4, 3, 3,
	3, 3, 3, 3, 4, 4, 3, 3,
	3, 0, 4, 1, 1, 1, 1, 1,
	1, 1, 0, 1, 6, 0, 0
};

static const short _address_index_offsets[] = {
	0, 0, 17, 19, 36, 38, 40, 42,
	44, 46, 48, 65, 77, 79, 81, 83,
	85, 87, 89, 91, 103, 114, 123, 128,
	134, 137, 139, 146, 151, 153, 158, 160,
	165, 168, 171, 176, 179, 182, 185, 190,
	193, 196, 199, 204, 207, 214, 221, 230,
	238, 245, 252, 259, 265, 275, 281, 286,
	291, 293, 298, 303, 308, 313, 315, 320,
	325, 330, 335, 337, 342, 347, 352, 357,
	359, 364, 369, 374, 379, 381, 386, 391,
	396, 401, 403, 411, 417, 422, 427, 429,
	433, 438, 443, 448, 454, 460, 466, 474,
	481, 487, 493, 498, 504, 510, 516, 519,
	523, 529, 535, 541, 544, 548, 554, 560,
	566, 569, 573, 579, 585, 591, 594, 598,
	604, 610, 616, 619, 624, 632, 639, 645,
	651, 654, 661, 668, 674, 680, 683, 690,
	697, 703, 709, 712, 719, 726, 732, 738,
	741, 748, 755, 762, 769, 776, 785, 793,
	800, 807, 814, 821, 828, 837, 845, 852,
	859, 865, 872, 879, 886, 895, 903, 910,
	917, 923, 930, 937, 944, 953, 961, 968,
	975, 981, 988, 995, 1002, 1011, 1019, 1026,
	1033, 1039, 1042, 1053, 1055, 1057, 1059, 1061,
	1063, 1065, 1067, 1069, 1071, 1084, 0
};

static const short _address_cond_targs[] = {
	4, 6, 7, 9, 186, 3, 3, 3,
	2, 5, 8, 3, 3, 3, 3, 3,
	0, 3, 0, 4, 6, 7, 9, 3,
	10, 3, 11, 2, 5, 8, 3, 3,
	3, 3, 3, 0, 2, 0, 2, 0,
	2, 0, 5, 0, 5, 0, 5, 0,
	4, 6, 7, 9, 3, 3, 3, 3,
	2, 5, 8, 3, 3, 3, 3, 3,
	0, 13, 15, 16, 18, 21, 12, 14,
	17, 196, 196, 196, 0, 196, 0, 12,
	0, 12, 0, 12, 0, 14, 0, 14,
	0, 14, 0, 13, 15, 16, 18, 19,
	12, 14, 17, 196, 196, 196, 0, 13,
	15, 16, 18, 12, 14, 17, 196, 196,
	196, 0, 22, 26, 44, 46, 48, 45,
	23, 23, 0, 22, 23, 23, 23, 0,
	22, 24, 23, 23, 23, 0, 25, 25,
	0, 197, 0, 22, 27, 24, 23, 23,
	23, 0, 28, 40, 42, 41, 0, 29,
	0, 30, 36, 38, 37, 0, 31, 0,
	25, 32, 34, 33, 0, 197, 33, 0,
	197, 25, 0, 35, 197, 33, 25, 0,
	197, 25, 0, 31, 37, 0, 31, 30,
	0, 31, 39, 37, 30, 0, 31, 30,
	0, 29, 41, 0, 29, 28, 0, 29,
	43, 41, 28, 0, 29, 28, 0, 22,
	27, 24, 45, 23, 23, 0, 22, 27,
	24, 26, 23, 23, 0, 22, 27, 47,
	24, 45, 26, 23, 23, 0, 22, 27,
	24, 26, 23, 23, 23, 0, 22, 24,
	49, 23, 23, 23, 0, 22, 24, 50,
	23, 23, 23, 0, 22, 51, 24, 23,
	23, 23, 0, 22, 52, 23, 23, 23,
	0, 185, 25, 53, 25, 53, 25, 25,
	53, 25, 0, 57, 197, 54, 54, 54,
	0, 57, 55, 55, 55, 0, 57, 56,
	56, 56, 0, 57, 0, 124, 58, 58,
	58, 0, 62, 59, 59, 59, 0, 62,
	60, 60, 60, 0, 62, 61, 61, 61,
	0, 62, 0, 124, 63, 63, 63, 0,
	67, 64, 64, 64, 0, 67, 65, 65,
	65, 0, 67, 66, 66, 66, 0, 67,
	0, 124, 68, 68, 68, 0, 72, 69,
	69, 69, 0, 72, 70, 70, 70, 0,
	72, 71, 71, 71, 0, 72, 0, 124,
	73, 73, 73, 0, 77, 74, 74, 74,
	0, 77, 75, 75, 75, 0, 77, 76,
	76, 76, 0, 77, 0, 98, 78, 78,
	78, 0, 82, 79, 79, 79, 0, 82,
	80, 80, 80, 0, 82, 81, 81, 81,
	0, 82, 0, 83, 91, 94, 98, 97,
	123, 123, 0, 27, 87, 84, 84, 84,
	0, 87, 85, 85, 85, 0, 87, 86,
	86, 86, 0, 87, 0, 88, 88, 88,
	0, 197, 89, 89, 89, 0, 197, 90,
	90, 90, 0, 197, 25, 25, 25, 0,
	27, 87, 92, 84, 84, 0, 27, 87,
	93, 85, 85, 0, 27, 87, 86, 86,
	86, 0, 27, 95, 87, 92, 96, 84,
	84, 0, 27, 87, 93, 85, 85, 85,
	0, 27, 87, 85, 85, 85, 0, 27,
	87, 96, 84, 84, 0, 197, 99, 99,
	99, 0, 103, 197, 100, 100, 100, 0,
	103, 197, 101, 101, 101, 0, 103, 197,
	102, 102, 102, 0, 103, 197, 0, 104,
	104, 104, 0, 108, 197, 105, 105, 105,
	0, 108, 197, 106, 106, 106, 0, 108,
	197, 107, 107, 107, 0, 108, 197, 0,
	109, 109, 109, 0, 113, 197, 110, 110,
	110, 0, 113, 197, 111, 111, 111, 0,
	113, 197, 112, 112, 112, 0, 113, 197,
	0, 114, 114, 114, 0, 118, 197, 115,
	115, 115, 0, 118, 197, 116, 116, 116,
	0, 118, 197, 117, 117, 117, 0, 118,
	197, 0, 119, 119, 119, 0, 87, 197,
	120, 120, 120, 0, 87, 197, 121, 121,
	121, 0, 87, 197, 122, 122, 122, 0,
	87, 197, 0, 87, 84, 84, 84, 0,
	125, 177, 180, 197, 183, 184, 184, 0,
	27, 129, 197, 126, 126, 126, 0, 129,
	197, 127, 127, 127, 0, 129, 197, 128,
	128, 128, 0, 129, 197, 0, 130, 169,
	172, 175, 176, 176, 0, 27, 134, 197,
	131, 131, 131, 0, 134, 197, 132, 132,
	132, 0, 134, 197, 133, 133, 133, 0,
	134, 197, 0, 135, 161, 164, 167, 168,
	168, 0, 27, 139, 197, 136, 136, 136,
	0, 139, 197, 137, 137, 137, 0, 139,
	197, 138, 138, 138, 0, 139, 197, 0,
	140, 153, 156, 159, 160, 160, 0, 27,
	144, 197, 141, 141, 141, 0, 144, 197,
	142, 142, 142, 0, 144, 197, 143, 143,
	143, 0, 144, 197, 0, 145, 146, 149,
	152, 119, 119, 0, 27, 87, 197, 120,
	120, 120, 0, 27, 87, 197, 147, 120,
	120, 0, 27, 87, 197, 148, 121, 121,
	0, 27, 87, 197, 122, 122, 122, 0,
	27, 150, 87, 197, 147, 151, 120, 120,
	0, 27, 87, 197, 148, 121, 121, 121,
	0, 27, 87, 197, 121, 121, 121, 0,
	27, 87, 197, 151, 120, 120, 0, 27,
	144, 197, 154, 141, 141, 0, 27, 144,
	197, 155, 142, 142, 0, 27, 144, 197,
	143, 143, 143, 0, 27, 157, 144, 197,
	154, 158, 141, 141, 0, 27, 144, 197,
	155, 142, 142, 142, 0, 27, 144, 197,
	142, 142, 142, 0, 27, 144, 197, 158,
	141, 141, 0, 144, 197, 141, 141, 141,
	0, 27, 139, 197, 162, 136, 136, 0,
	27, 139, 197, 163, 137, 137, 0, 27,
	139, 197, 138, 138, 138, 0, 27, 165,
	139, 197, 162, 166, 136, 136, 0, 27,
	139, 197, 163, 137, 137, 137, 0, 27,
	139, 197, 137, 137, 137, 0, 27, 139,
	197, 166, 136, 136, 0, 139, 197, 136,
	136, 136, 0, 27, 134, 197, 170, 131,
	131, 0, 27, 134, 197, 171, 132, 132,
	0, 27, 134, 197, 133, 133, 133, 0,
	27, 173, 134, 197, 170, 174, 131, 131,
	0, 27, 134, 197, 171, 132, 132, 132,
	0, 27, 134, 197, 132, 132, 132, 0,
	27, 134, 197, 174, 131, 131, 0, 134,
	197, 131, 131, 131, 0, 27, 129, 197,
	178, 126, 126, 0, 27, 129, 197, 179,
	127, 127, 0, 27, 129, 197, 128, 128,
	128, 0, 27, 181, 129, 197, 178, 182,
	126, 126, 0, 27, 129, 197, 179, 127,
	127, 127, 0, 27, 129, 197, 127, 127,
	127, 0, 27, 129, 197, 182, 126, 126,
	0, 129, 197, 126, 126, 126, 0, 124,
	197, 0, 188, 190, 191, 193, 194, 195,
	187, 189, 192, 186, 0, 186, 0, 187,
	0, 187, 0, 187, 0, 189, 0, 189,
	0, 189, 0, 11, 0, 186, 0, 13,
	15, 16, 18, 19, 20, 12, 14, 17,
	196, 196, 196, 0, 0, 0, 1, 2,
	3, 4, 5, 6, 7, 8, 9, 10,
	11, 12, 13, 14, 15, 16, 17, 18,
	19, 20, 21, 22, 23, 24, 25, 26,
	27, 28, 29, 30, 31, 32, 33, 34,
	35, 36, 37, 38, 39, 40, 41, 42,
	43, 44, 45, 46, 47, 48, 49, 50,
	51, 52, 53, 54, 55, 56, 57, 58,
	59, 60, 61, 62, 63, 64, 65, 66,
	67, 68, 69, 70, 71, 72, 73, 74,
	75, 76, 77, 78, 79, 80, 81, 82,
	83, 84, 85, 86, 87, 88, 89, 90,
	91, 92, 93, 94, 95, 96, 97, 98,
	99, 100, 101, 102, 103, 104, 105, 106,
	107, 108, 109, 110, 111, 112, 113, 114,
	115, 116, 117, 118, 119, 120, 121, 122,
	123, 124, 125, 126, 127, 128, 129, 130,
	131, 132, 133, 134, 135, 136, 137, 138,
	139, 140, 141, 142, 143, 144, 145, 146,
	147, 148, 149, 150, 151, 152, 153, 154,
	155, 156, 157, 158, 159, 160, 161, 162,
	163, 164, 165, 166, 167, 168, 169, 170,
	171, 172, 173, 174, 175, 176, 177, 178,
	179, 180, 181, 182, 183, 184, 185, 186,
	187, 188, 189, 190, 191, 192, 193, 194,
	195, 196, 197, 0
};

static const signed char _address_cond_actions[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	3, 0, 3, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 3, 0, 3, 0, 3,
	0, 3, 0, 3, 0, 3, 0, 3,
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0,
	0, 1, 1, 1, 3, 1, 3, 0,
	3, 0, 3, 0, 3, 0, 3, 0,
	3, 0, 3, 0, 0, 0, 0, 0,
	0, 0, 0, 1, 1, 1, 3, 0,
	0, 0, 0, 0, 0, 0, 1, 1,
	1, 3, 0, 0, 0, 0, 0, 0,
	0, 0, 3, 0, 0, 0, 0, 3,
	0, 0, 0, 0, 0, 3, 0, 0,
	3, 1, 3, 0, 0, 0, 0, 0,
	0, 3, 0, 0, 0, 0, 3, 0,
	3, 0, 0, 0, 0, 3, 0, 3,
	0, 0, 0, 0, 3, 1, 0, 3,
	1, 0, 3, 0, 1, 0, 0, 3,
	1, 0, 3, 0, 0, 3, 0, 0,
	3, 0, 0, 0, 0, 3, 0, 0,
	3, 0, 0, 3, 0, 0, 3, 0,
	0, 0, 0, 3, 0, 0, 3, 0,
	0, 0, 0, 0, 0, 3, 0, 0,
	0, 0, 0, 0, 3, 0, 0, 0,
	0, 0, 0, 0, 0, 3, 0, 0,
	0, 0, 0, 0, 0, 3, 0, 0,
	0, 0, 0, 0, 3, 0, 0, 0,
	0, 0, 0, 3, 0, 0, 0, 0,
	0, 0, 3, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 3, 0, 1, 0, 0, 0,
	3, 0, 0, 0, 0, 3, 0, 0,
	0, 0, 3, 0, 3, 0, 0, 0,
	0, 3, 0, 0, 0, 0, 3, 0,
	0, 0, 0, 3, 0, 0, 0, 0,
	3, 0, 3, 0, 0, 0, 0, 3,
	0, 0, 0, 0, 3, 0, 0, 0,
	0, 3, 0, 0, 0, 0, 3, 0,
	3, 0, 0, 0, 0, 3, 0, 0,
	0, 0, 3, 0, 0, 0, 0, 3,
	0, 0, 0, 0, 3, 0, 3, 0,
	0, 0, 0, 3, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 3, 0, 0,
	0, 0, 3, 0, 3, 0, 0, 0,
	0, 3, 0, 0, 0, 0, 3, 0,
	0, 0, 0, 3, 0, 0, 0, 0,
	3, 0, 3, 0, 0, 0, 0, 0,
	0, 0, 3, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 3, 0, 0,
	0, 0, 3, 0, 3, 0, 0, 0,
	3, 1, 0, 0, 0, 3, 1, 0,
	0, 0, 3, 1, 0, 0, 0, 3,
	0, 0, 0, 0, 0, 3, 0, 0,
	0, 0, 0, 3, 0, 0, 0, 0,
	0, 3, 0, 0, 0, 0, 0, 0,
	0, 3, 0, 0, 0, 0, 0, 0,
	3, 0, 0, 0, 0, 0, 3, 0,
	0, 0, 0, 0, 3, 1, 0, 0,
	0, 3, 0, 1, 0, 0, 0, 3,
	0, 1, 0, 0, 0, 3, 0, 1,
	0, 0, 0, 3, 0, 1, 3, 0,
	0, 0, 3, 0, 1, 0, 0, 0,
	3, 0, 1, 0, 0, 0, 3, 0,
	1, 0, 0, 0, 3, 0, 1, 3,
	0, 0, 0, 3, 0, 1, 0, 0,
	0, 3, 0, 1, 0, 0, 0, 3,
	0, 1, 0, 0, 0, 3, 0, 1,
	3, 0, 0, 0, 3, 0, 1, 0,
	0, 0, 3, 0, 1, 0, 0, 0,
	3, 0, 1, 0, 0, 0, 3, 0,
	1, 3, 0, 0, 0, 3, 0, 1,
	0, 0, 0, 3, 0, 1, 0, 0,
	0, 3, 0, 1, 0, 0, 0, 3,
	0, 1, 3, 0, 0, 0, 0, 3,
	0, 0, 0, 1, 0, 0, 0, 3,
	0, 0, 1, 0, 0, 0, 3, 0,
	1, 0, 0, 0, 3, 0, 1, 0,
	0, 0, 3, 0, 1, 3, 0, 0,
	0, 0, 0, 0, 3, 0, 0, 1,
	0, 0, 0, 3, 0, 1, 0, 0,
	0, 3, 0, 1, 0, 0, 0, 3,
	0, 1, 3, 0, 0, 0, 0, 0,
	0, 3, 0, 0, 1, 0, 0, 0,
	3, 0, 1, 0, 0, 0, 3, 0,
	1, 0, 0, 0, 3, 0, 1, 3,
	0, 0, 0, 0, 0, 0, 3, 0,
	0, 1, 0, 0, 0, 3, 0, 1,
	0, 0, 0, 3, 0, 1, 0, 0,
	0, 3, 0, 1, 3, 0, 0, 0,
	0, 0, 0, 3, 0, 0, 1, 0,
	0, 0, 3, 0, 0, 1, 0, 0,
	0, 3, 0, 0, 1, 0, 0, 0,
	3, 0, 0, 1, 0, 0, 0, 3,
	0, 0, 0, 1, 0, 0, 0, 0,
	3, 0, 0, 1, 0, 0, 0, 0,
	3, 0, 0, 1, 0, 0, 0, 3,
	0, 0, 1, 0, 0, 0, 3, 0,
	0, 1, 0, 0, 0, 3, 0, 0,
	1, 0, 0, 0, 3, 0, 0, 1,
	0, 0, 0, 3, 0, 0, 0, 1,
	0, 0, 0, 0, 3, 0, 0, 1,
	0, 0, 0, 0, 3, 0, 0, 1,
	0, 0, 0, 3, 0, 0, 1, 0,
	0, 0, 3, 0, 1, 0, 0, 0,
	3, 0, 0, 1, 0, 0, 0, 3,
	0, 0, 1, 0, 0, 0, 3, 0,
	0, 1, 0, 0, 0, 3, 0, 0,
	0, 1, 0, 0, 0, 0, 3, 0,
	0, 1, 0, 0, 0, 0, 3, 0,
	0, 1, 0, 0, 0, 3, 0, 0,
	1, 0, 0, 0, 3, 0, 1, 0,
	0, 0, 3, 0, 0, 1, 0, 0,
	0, 3, 0, 0, 1, 0, 0, 0,
	3, 0, 0, 1, 0, 0, 0, 3,
	0, 0, 0, 1, 0, 0, 0, 0,
	3, 0, 0, 1, 0, 0, 0, 0,
	3, 0, 0, 1, 0, 0, 0, 3,
	0, 0, 1, 0, 0, 0, 3, 0,
	1, 0, 0, 0, 3, 0, 0, 1,
	0, 0, 0, 3, 0, 0, 1, 0,
	0, 0, 3, 0, 0, 1, 0, 0,
	0, 3, 0, 0, 0, 1, 0, 0,
	0, 0, 3, 0, 0, 1, 0, 0,
	0, 0, 3, 0, 0, 1, 0, 0,
	0, 3, 0, 0, 1, 0, 0, 0,
	3, 0, 1, 0, 0, 0, 3, 0,
	1, 3, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 3, 0, 3, 0,
	3, 0, 3, 0, 3, 0, 3, 0,
	3, 0, 3, 0, 3, 0, 3, 0,
	0, 0, 0, 0, 0, 0, 0, 0,
	1, 1, 1, 3, 3, 0, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3,
	3, 0, 0, 0
};

static const short _address_eof_trans[] = {
	1086, 1087, 1088, 1089, 1090, 1091, 1092, 1093,
	1094, 1095, 1096, 1097, 1098, 1099, 1100, 1101,
	1102, 1103, 1104, 1105, 1106, 1107, 1108, 1109,
	1110, 1111, 1112, 1113, 1114, 1115, 1116, 1117,
	1118, 1119, 1120, 1121, 1122, 1123, 1124, 1125,
	1126, 1127, 1128, 1129, 1130, 1131, 1132, 1133,
	1134, 1135, 1136, 1137, 1138, 1139, 1140, 1141,
	1142, 1143, 1144, 1145, 1146, 1147, 1148, 1149,
	1150, 1151, 1152, 1153, 1154, 1155, 1156, 1157,
	1158, 1159, 1160, 1161, 1162, 1163, 1164, 1165,
	1166, 1167, 1168, 1169, 1170, 1171, 1172, 1173,
	1174, 1175, 1176, 1177, 1178, 1179, 1180, 1181,
	1182, 1183, 1184, 1185, 1186, 1187, 1188, 1189,
	1190, 1191, 1192, 1193, 1194, 1195, 1196, 1197,
	1198, 1199, 1200, 1201, 1202, 1203, 1204, 1205,
	1206, 1207, 1208, 1209, 1210, 1211, 1212, 1213,
	1214, 1215, 1216, 1217, 1218, 1219, 1220, 1221,
	1222, 1223, 1224, 1225, 1226, 1227, 1228, 1229,
	1230, 1231, 1232, 1233, 1234, 1235, 1236, 1237,
	1238, 1239, 1240, 1241, 1242, 1243, 1244, 1245,
	1246, 1247, 1248, 1249, 1250, 1251, 1252, 1253,
	1254, 1255, 1256, 1257, 1258, 1259, 1260, 1261,
	1262, 1263, 1264, 1265, 1266, 1267, 1268, 1269,
	1270, 1271, 1272, 1273, 1274, 1275, 1276, 1277,
	1278, 1279, 1280, 1281, 1282, 1283, 0
};

static const int address_start = 1;
static const int address_first_final = 196;
static const int address_error = 0;

static const int address_en_main = 1;


#line 112 "smtp-address-validator.rl"


bool is_address(const char* p, const char* pe)
{
	int cs = 0;
	
	const char* eof = pe;
	
	bool result = false;
	

#line 675 "smtp-address-validator.cpp"
	{
		cs = (int)address_start;
	}
	
#line 124 "smtp-address-validator.rl"


#line 680 "smtp-address-validator.cpp"
	{
		int _klen;
		unsigned int _trans = 0;
		const signed char * _keys;
		const signed char * _acts;
		unsigned int _nacts;
		_resume: {}
		if ( p == pe && p != eof )
			goto _out;
		if ( p == eof ) {
			if ( _address_eof_trans[cs] > 0 ) {
				_trans = (unsigned int)_address_eof_trans[cs] - 1;
			}
		}
		else {
			_keys = ( _address_trans_keys + (_address_key_offsets[cs]));
			_trans = (unsigned int)_address_index_offsets[cs];
			
			_klen = (int)_address_single_lengths[cs];
			if ( _klen > 0 ) {
				const signed char *_lower = _keys;
				const signed char *_upper = _keys + _klen - 1;
				const signed char *_mid;
				while ( 1 ) {
					if ( _upper < _lower ) {
						_keys += _klen;
						_trans += (unsigned int)_klen;
						break;
					}
					
					_mid = _lower + ((_upper-_lower) >> 1);
					if ( ( (*( p))) < (*( _mid)) )
						_upper = _mid - 1;
					else if ( ( (*( p))) > (*( _mid)) )
						_lower = _mid + 1;
					else {
						_trans += (unsigned int)(_mid - _keys);
						goto _match;
					}
				}
			}
			
			_klen = (int)_address_range_lengths[cs];
			if ( _klen > 0 ) {
				const signed char *_lower = _keys;
				const signed char *_upper = _keys + (_klen<<1) - 2;
				const signed char *_mid;
				while ( 1 ) {
					if ( _upper < _lower ) {
						_trans += (unsigned int)_klen;
						break;
					}
					
					_mid = _lower + (((_upper-_lower) >> 1) & ~1);
					if ( ( (*( p))) < (*( _mid)) )
						_upper = _mid - 2;
					else if ( ( (*( p))) > (*( _mid + 1)) )
						_lower = _mid + 2;
					else {
						_trans += (unsigned int)((_mid - _keys)>>1);
						break;
					}
				}
			}
			
			_match: {}
		}
		cs = (int)_address_cond_targs[_trans];
		
		if ( _address_cond_actions[_trans] != 0 ) {
			
			_acts = ( _address_actions + (_address_cond_actions[_trans]));
			_nacts = (unsigned int)(*( _acts));
			_acts += 1;
			while ( _nacts > 0 ) {
				switch ( (*( _acts)) )
				{
					case 0:  {
							{
#line 108 "smtp-address-validator.rl"
							result = true; }
						
#line 762 "smtp-address-validator.cpp"

						break; 
					}
					case 1:  {
							{
#line 108 "smtp-address-validator.rl"
							result = false; }
						
#line 770 "smtp-address-validator.cpp"

						break; 
					}
				}
				_nacts -= 1;
				_acts += 1;
			}
			
		}
		
		if ( p == eof ) {
			if ( cs >= 196 )
				goto _out;
		}
		else {
			if ( cs != 0 ) {
				p += 1;
				goto _resume;
			}
		}
		_out: {}
	}
	
#line 125 "smtp-address-validator.rl"

	
	return result;
}
