--TEST--
trader_bop() basic test
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--INI--
trader.real_precision=2
--FILE--
<?php

include "inc/data.php";
include "inc/func.php";

var_dump(trader_bop(
	get_data("open", $data0),
	get_data("high", $data0),
	get_data("low", $data0),
	get_data("close", $data0)
));

--EXPECT--
array(252) {
  [0]=>
  float(-0.4)
  [1]=>
  float(0.93)
  [2]=>
  float(-0.36)
  [3]=>
  float(0.41)
  [4]=>
  float(-0.54)
  [5]=>
  float(0.1)
  [6]=>
  float(-0.82)
  [7]=>
  float(0.31)
  [8]=>
  float(-0.49)
  [9]=>
  float(0.63)
  [10]=>
  float(0.64)
  [11]=>
  float(-0.07)
  [12]=>
  float(-0.1)
  [13]=>
  float(-0.54)
  [14]=>
  float(-0.02)
  [15]=>
  float(0.4)
  [16]=>
  float(-0.94)
  [17]=>
  float(-0.21)
  [18]=>
  float(0.83)
  [19]=>
  float(-0.95)
  [20]=>
  float(-0.49)
  [21]=>
  float(-0.15)
  [22]=>
  float(-0.77)
  [23]=>
  float(-0.68)
  [24]=>
  float(0)
  [25]=>
  float(-0.54)
  [26]=>
  float(1)
  [27]=>
  float(0.77)
  [28]=>
  float(-0.69)
  [29]=>
  float(-0.39)
  [30]=>
  float(0)
  [31]=>
  float(0.52)
  [32]=>
  float(-0.73)
  [33]=>
  float(0.82)
  [34]=>
  float(-0.24)
  [35]=>
  float(-0.53)
  [36]=>
  float(0.35)
  [37]=>
  float(-0.23)
  [38]=>
  float(-0.25)
  [39]=>
  float(-0.67)
  [40]=>
  float(-0.45)
  [41]=>
  float(-0.36)
  [42]=>
  float(0.86)
  [43]=>
  float(0.08)
  [44]=>
  float(0.36)
  [45]=>
  float(-0.04)
  [46]=>
  float(0.11)
  [47]=>
  float(-0.86)
  [48]=>
  float(0.54)
  [49]=>
  float(-0.3)
  [50]=>
  float(-0.71)
  [51]=>
  float(0.02)
  [52]=>
  float(-0.8)
  [53]=>
  float(-0.43)
  [54]=>
  float(-0.44)
  [55]=>
  float(0.37)
  [56]=>
  float(-0.18)
  [57]=>
  float(0.24)
  [58]=>
  float(0.65)
  [59]=>
  float(0.35)
  [60]=>
  float(-0.55)
  [61]=>
  float(-0.1)
  [62]=>
  float(0.91)
  [63]=>
  float(-0.02)
  [64]=>
  float(0.29)
  [65]=>
  float(0.17)
  [66]=>
  float(0.16)
  [67]=>
  float(-0.02)
  [68]=>
  float(-0.98)
  [69]=>
  float(-0.53)
  [70]=>
  float(-0.29)
  [71]=>
  float(-0.96)
  [72]=>
  float(-0.5)
  [73]=>
  float(0.4)
  [74]=>
  float(0.31)
  [75]=>
  float(-0.45)
  [76]=>
  float(0.46)
  [77]=>
  float(0.6)
  [78]=>
  float(0)
  [79]=>
  float(-0.6)
  [80]=>
  float(-0.03)
  [81]=>
  float(0.09)
  [82]=>
  float(0.71)
  [83]=>
  float(-0.05)
  [84]=>
  float(0)
  [85]=>
  float(-0.43)
  [86]=>
  float(0.93)
  [87]=>
  float(0.28)
  [88]=>
  float(0.11)
  [89]=>
  float(0.33)
  [90]=>
  float(1)
  [91]=>
  float(-0.3)
  [92]=>
  float(0.19)
  [93]=>
  float(0.06)
  [94]=>
  float(-0.41)
  [95]=>
  float(-0.7)
  [96]=>
  float(-0.56)
  [97]=>
  float(-0.73)
  [98]=>
  float(-0.26)
  [99]=>
  float(0.87)
  [100]=>
  float(-0.16)
  [101]=>
  float(0)
  [102]=>
  float(-0.6)
  [103]=>
  float(0.38)
  [104]=>
  float(-0.43)
  [105]=>
  float(0.66)
  [106]=>
  float(0.56)
  [107]=>
  float(-0.85)
  [108]=>
  float(0.08)
  [109]=>
  float(-0.18)
  [110]=>
  float(-0.19)
  [111]=>
  float(-0.18)
  [112]=>
  float(-0.45)
  [113]=>
  float(0.31)
  [114]=>
  float(0.31)
  [115]=>
  float(0.33)
  [116]=>
  float(0.6)
  [117]=>
  float(-0.1)
  [118]=>
  float(0.28)
  [119]=>
  float(-0.19)
  [120]=>
  float(-0.07)
  [121]=>
  float(-0.57)
  [122]=>
  float(0.63)
  [123]=>
  float(0.58)
  [124]=>
  float(0.3)
  [125]=>
  float(0.49)
  [126]=>
  float(-0.48)
  [127]=>
  float(0.63)
  [128]=>
  float(0.44)
  [129]=>
  float(0.94)
  [130]=>
  float(0.11)
  [131]=>
  float(0.61)
  [132]=>
  float(-0.45)
  [133]=>
  float(-0.46)
  [134]=>
  float(-0.06)
  [135]=>
  float(-0.36)
  [136]=>
  float(-0.61)
  [137]=>
  float(0.52)
  [138]=>
  float(-0.75)
  [139]=>
  float(0.28)
  [140]=>
  float(-0.26)
  [141]=>
  float(0.42)
  [142]=>
  float(0.69)
  [143]=>
  float(-0.43)
  [144]=>
  float(-0.1)
  [145]=>
  float(-0.41)
  [146]=>
  float(-0.68)
  [147]=>
  float(-0.39)
  [148]=>
  float(0.49)
  [149]=>
  float(0.25)
  [150]=>
  float(-0.43)
  [151]=>
  float(-0.61)
  [152]=>
  float(0.8)
  [153]=>
  float(-0.93)
  [154]=>
  float(0.24)
  [155]=>
  float(0.7)
  [156]=>
  float(0)
  [157]=>
  float(-0.73)
  [158]=>
  float(-0.25)
  [159]=>
  float(-0.79)
  [160]=>
  float(0.66)
  [161]=>
  float(-0.52)
  [162]=>
  float(0.11)
  [163]=>
  float(0.08)
  [164]=>
  float(-0.4)
  [165]=>
  float(-0.36)
  [166]=>
  float(0.06)
  [167]=>
  float(0.54)
  [168]=>
  float(-0.25)
  [169]=>
  float(0.27)
  [170]=>
  float(0.72)
  [171]=>
  float(-0.23)
  [172]=>
  float(0.46)
  [173]=>
  float(-0.75)
  [174]=>
  float(-0.63)
  [175]=>
  float(0.8)
  [176]=>
  float(-0.67)
  [177]=>
  float(-0.7)
  [178]=>
  float(-0.78)
  [179]=>
  float(0.74)
  [180]=>
  float(-0.48)
  [181]=>
  float(-0.69)
  [182]=>
  float(-0.86)
  [183]=>
  float(0.98)
  [184]=>
  float(-0.66)
  [185]=>
  float(0.16)
  [186]=>
  float(-0.71)
  [187]=>
  float(0)
  [188]=>
  float(-0.58)
  [189]=>
  float(0.57)
  [190]=>
  float(0)
  [191]=>
  float(-0.82)
  [192]=>
  float(-0.66)
  [193]=>
  float(-0.37)
  [194]=>
  float(0.21)
  [195]=>
  float(-0.82)
  [196]=>
  float(-0.97)
  [197]=>
  float(0.19)
  [198]=>
  float(0.28)
  [199]=>
  float(-0.23)
  [200]=>
  float(0.03)
  [201]=>
  float(-0.26)
  [202]=>
  float(-0.5)
  [203]=>
  float(0.08)
  [204]=>
  float(-0.12)
  [205]=>
  float(0.45)
  [206]=>
  float(-0.9)
  [207]=>
  float(0.41)
  [208]=>
  float(0.45)
  [209]=>
  float(-0.71)
  [210]=>
  float(-0.62)
  [211]=>
  float(-0.61)
  [212]=>
  float(-0.64)
  [213]=>
  float(-0.9)
  [214]=>
  float(1)
  [215]=>
  float(-0.42)
  [216]=>
  float(0.8)
  [217]=>
  float(-0.95)
  [218]=>
  float(-0.03)
  [219]=>
  float(-0.77)
  [220]=>
  float(0)
  [221]=>
  float(-0.49)
  [222]=>
  float(0.85)
  [223]=>
  float(0.73)
  [224]=>
  float(0.59)
  [225]=>
  float(-0.71)
  [226]=>
  float(-0.15)
  [227]=>
  float(-0.5)
  [228]=>
  float(-0.47)
  [229]=>
  float(-0.26)
  [230]=>
  float(0.39)
  [231]=>
  float(0.62)
  [232]=>
  float(0.41)
  [233]=>
  float(0.75)
  [234]=>
  float(-0.1)
  [235]=>
  float(0.36)
  [236]=>
  float(-0.72)
  [237]=>
  float(-0.59)
  [238]=>
  float(0.25)
  [239]=>
  float(-0.28)
  [240]=>
  float(-0.21)
  [241]=>
  float(0.3)
  [242]=>
  float(-0.28)
  [243]=>
  float(0.05)
  [244]=>
  float(0.78)
  [245]=>
  float(-0.8)
  [246]=>
  float(-0.22)
  [247]=>
  float(0.03)
  [248]=>
  float(0.14)
  [249]=>
  float(-0.82)
  [250]=>
  float(-0.48)
  [251]=>
  float(-0.45)
}
