--TEST--
trader_avgprice() basic test
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--INI--
trader.real_precision=5
--FILE--
<?php

include "inc/data.php";
include "inc/func.php";

var_dump(trader_avgprice(
	get_data("open", $data0),
	get_data("high", $data0),
	get_data("low", $data0),
	get_data("close", $data0)
));

--EXPECT--
array(252) {
  [0]=>
  float(92)
  [1]=>
  float(93.165)
  [2]=>
  float(95.03875)
  [3]=>
  float(94.68875)
  [4]=>
  float(94.52375)
  [5]=>
  float(94.33625)
  [6]=>
  float(93.6325)
  [7]=>
  float(91.93)
  [8]=>
  float(91.01)
  [9]=>
  float(91.7425)
  [10]=>
  float(94.75)
  [11]=>
  float(97.6725)
  [12]=>
  float(98.1175)
  [13]=>
  float(90.86)
  [14]=>
  float(90.0475)
  [15]=>
  float(92.22)
  [16]=>
  float(91.2175)
  [17]=>
  float(89.6325)
  [18]=>
  float(90.5475)
  [19]=>
  float(91.03125)
  [20]=>
  float(89)
  [21]=>
  float(87.64875)
  [22]=>
  float(86.3125)
  [23]=>
  float(84)
  [24]=>
  float(83.25125)
  [25]=>
  float(82.625)
  [26]=>
  float(82.845)
  [27]=>
  float(86.96125)
  [28]=>
  float(87.055)
  [29]=>
  float(87.21125)
  [30]=>
  float(85.515)
  [31]=>
  float(86.3675)
  [32]=>
  float(86.47)
  [33]=>
  float(87.39875)
  [34]=>
  float(88.83625)
  [35]=>
  float(87.9775)
  [36]=>
  float(86.11)
  [37]=>
  float(84.89125)
  [38]=>
  float(84.06375)
  [39]=>
  float(84.50875)
  [40]=>
  float(83.65625)
  [41]=>
  float(86.45375)
  [42]=>
  float(88.11875)
  [43]=>
  float(89.32125)
  [44]=>
  float(90.68875)
  [45]=>
  float(90.7825)
  [46]=>
  float(91.5875)
  [47]=>
  float(90.26625)
  [48]=>
  float(90.07875)
  [49]=>
  float(90.83625)
  [50]=>
  float(89.445)
  [51]=>
  float(88.2275)
  [52]=>
  float(86.39875)
  [53]=>
  float(84.1025)
  [54]=>
  float(83.00125)
  [55]=>
  float(84.3125)
  [56]=>
  float(85.7575)
  [57]=>
  float(86.23499)
  [58]=>
  float(88.25125)
  [59]=>
  float(89.21125)
  [60]=>
  float(89.40625)
  [61]=>
  float(88.33625)
  [62]=>
  float(90.68)
  [63]=>
  float(91.88375)
  [64]=>
  float(92.14875)
  [65]=>
  float(92.92125)
  [66]=>
  float(93)
  [67]=>
  float(91.45375)
  [68]=>
  float(90.9925)
  [69]=>
  float(90.455)
  [70]=>
  float(88.78125)
  [71]=>
  float(86.93875)
  [72]=>
  float(84.25)
  [73]=>
  float(83.6875)
  [74]=>
  float(84.83)
  [75]=>
  float(97.89875)
  [76]=>
  float(99.07875)
  [77]=>
  float(103.46125)
  [78]=>
  float(105.96875)
  [79]=>
  float(103.53125)
  [80]=>
  float(102.78125)
  [81]=>
  float(104.01625)
  [82]=>
  float(104.85125)
  [83]=>
  float(106.43875)
  [84]=>
  float(105.50875)
  [85]=>
  float(105.39125)
  [86]=>
  float(107.1325)
  [87]=>
  float(109.3525)
  [88]=>
  float(110.11)
  [89]=>
  float(111.32125)
  [90]=>
  float(120)
  [91]=>
  float(120.03125)
  [92]=>
  float(118.14125)
  [93]=>
  float(119.2975)
  [94]=>
  float(118.2425)
  [95]=>
  float(117.17375)
  [96]=>
  float(115.7125)
  [97]=>
  float(113.3125)
  [98]=>
  float(111.33625)
  [99]=>
  float(114.665)
  [100]=>
  float(115.545)
  [101]=>
  float(115.735)
  [102]=>
  float(112.67)
  [103]=>
  float(112.39)
  [104]=>
  float(113.5925)
  [105]=>
  float(114.515)
  [106]=>
  float(119.4525)
  [107]=>
  float(118.105)
  [108]=>
  float(117.7625)
  [109]=>
  float(115.295)
  [110]=>
  float(114.6075)
  [111]=>
  float(115.3425)
  [112]=>
  float(116.6075)
  [113]=>
  float(120.2325)
  [114]=>
  float(120.11)
  [115]=>
  float(120.5325)
  [116]=>
  float(123.9975)
  [117]=>
  float(124.4975)
  [118]=>
  float(122.7825)
  [119]=>
  float(122.92)
  [120]=>
  float(123.825)
  [121]=>
  float(123.36)
  [122]=>
  float(123.92)
  [123]=>
  float(127.6075)
  [124]=>
  float(130.07749)
  [125]=>
  float(131.22)
  [126]=>
  float(132.0475)
  [127]=>
  float(131.985)
  [128]=>
  float(133.5325)
  [129]=>
  float(135.675)
  [130]=>
  float(137.32999)
  [131]=>
  float(137.14249)
  [132]=>
  float(137.5625)
  [133]=>
  float(136.735)
  [134]=>
  float(136.3775)
  [135]=>
  float(135.925)
  [136]=>
  float(129.61)
  [137]=>
  float(128.28)
  [138]=>
  float(125.8725)
  [139]=>
  float(124.2175)
  [140]=>
  float(123.6225)
  [141]=>
  float(125.3275)
  [142]=>
  float(127.3125)
  [143]=>
  float(125.715)
  [144]=>
  float(125.6725)
  [145]=>
  float(123.515)
  [146]=>
  float(120.8575)
  [147]=>
  float(119.6075)
  [148]=>
  float(121.1875)
  [149]=>
  float(123.375)
  [150]=>
  float(122.8425)
  [151]=>
  float(120.5625)
  [152]=>
  float(121.7475)
  [153]=>
  float(122.42)
  [154]=>
  float(123.155)
  [155]=>
  float(126.185)
  [156]=>
  float(128.03)
  [157]=>
  float(126.345)
  [158]=>
  float(123.2325)
  [159]=>
  float(122.8875)
  [160]=>
  float(123.5925)
  [161]=>
  float(122.4975)
  [162]=>
  float(122.325)
  [163]=>
  float(123.3725)
  [164]=>
  float(124.235)
  [165]=>
  float(123.9375)
  [166]=>
  float(124.45)
  [167]=>
  float(126.7175)
  [168]=>
  float(125.8425)
  [169]=>
  float(128.7475)
  [170]=>
  float(130.4875)
  [171]=>
  float(131.72)
  [172]=>
  float(133.845)
  [173]=>
  float(136.14249)
  [174]=>
  float(133.64249)
  [175]=>
  float(132.70249)
  [176]=>
  float(133.22)
  [177]=>
  float(130.985)
  [178]=>
  float(127.985)
  [179]=>
  float(128.3775)
  [180]=>
  float(127.9375)
  [181]=>
  float(126)
  [182]=>
  float(124.6875)
  [183]=>
  float(122.735)
  [184]=>
  float(124.45)
  [185]=>
  float(123.235)
  [186]=>
  float(121.2325)
  [187]=>
  float(120.9675)
  [188]=>
  float(118.8275)
  [189]=>
  float(118.655)
  [190]=>
  float(121.5775)
  [191]=>
  float(120.8125)
  [192]=>
  float(117.435)
  [193]=>
  float(113.655)
  [194]=>
  float(114.39)
  [195]=>
  float(112.2175)
  [196]=>
  float(107.935)
  [197]=>
  float(106.36)
  [198]=>
  float(106.7625)
  [199]=>
  float(107.1725)
  [200]=>
  float(107.015)
  [201]=>
  float(108.92)
  [202]=>
  float(91.5)
  [203]=>
  float(93.7025)
  [204]=>
  float(93.84)
  [205]=>
  float(95.2475)
  [206]=>
  float(94.2175)
  [207]=>
  float(94.75)
  [208]=>
  float(97.625)
  [209]=>
  float(97.6075)
  [210]=>
  float(95.515)
  [211]=>
  float(94.92)
  [212]=>
  float(92.61)
  [213]=>
  float(91.5325)
  [214]=>
  float(92.22)
  [215]=>
  float(94.075)
  [216]=>
  float(95.7)
  [217]=>
  float(96.2175)
  [218]=>
  float(95.28)
  [219]=>
  float(95.075)
  [220]=>
  float(94.31)
  [221]=>
  float(94.0275)
  [222]=>
  float(95.9525)
  [223]=>
  float(101.6075)
  [224]=>
  float(106.5625)
  [225]=>
  float(107.685)
  [226]=>
  float(104.0775)
  [227]=>
  float(105.265)
  [228]=>
  float(104.36)
  [229]=>
  float(103.3425)
  [230]=>
  float(103.1675)
  [231]=>
  float(104.5975)
  [232]=>
  float(110.6225)
  [233]=>
  float(114.5)
  [234]=>
  float(117.0625)
  [235]=>
  float(117.7575)
  [236]=>
  float(117.06)
  [237]=>
  float(110.03)
  [238]=>
  float(109.2825)
  [239]=>
  float(109.125)
  [240]=>
  float(106.7975)
  [241]=>
  float(108.1575)
  [242]=>
  float(110.0925)
  [243]=>
  float(109.1125)
  [244]=>
  float(109.2)
  [245]=>
  float(109.045)
  [246]=>
  float(109.0925)
  [247]=>
  float(109.39)
  [248]=>
  float(109.795)
  [249]=>
  float(109.6725)
  [250]=>
  float(109.375)
  [251]=>
  float(108.295)
}
