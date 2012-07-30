--TEST--
trader_aroonosc() basic test
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--FILE--
<?php

include "inc/data.php";
include "inc/func.php";

$period = 14;

var_dump(trader_aroonosc(get_data("high", $data0), get_data("low", $data0), $period));
--EXPECT--
array(238) {
  [14]=>
  float(-21.428)
  [15]=>
  float(-21.428)
  [16]=>
  float(-21.428)
  [17]=>
  float(-21.428)
  [18]=>
  float(-21.428)
  [19]=>
  float(-21.428)
  [20]=>
  float(-21.428)
  [21]=>
  float(-71.428)
  [22]=>
  float(-78.571)
  [23]=>
  float(-85.714)
  [24]=>
  float(-92.857)
  [25]=>
  float(-100)
  [26]=>
  float(-92.857)
  [27]=>
  float(-64.285)
  [28]=>
  float(-64.285)
  [29]=>
  float(-64.285)
  [30]=>
  float(-64.285)
  [31]=>
  float(-42.857)
  [32]=>
  float(-42.857)
  [33]=>
  float(-42.857)
  [34]=>
  float(-35.714)
  [35]=>
  float(64.285)
  [36]=>
  float(64.285)
  [37]=>
  float(64.285)
  [38]=>
  float(64.285)
  [39]=>
  float(64.285)
  [40]=>
  float(57.142)
  [41]=>
  float(-42.857)
  [42]=>
  float(-42.857)
  [43]=>
  float(21.428)
  [44]=>
  float(28.571)
  [45]=>
  float(28.571)
  [46]=>
  float(42.857)
  [47]=>
  float(42.857)
  [48]=>
  float(42.857)
  [49]=>
  float(42.857)
  [50]=>
  float(42.857)
  [51]=>
  float(42.857)
  [52]=>
  float(42.857)
  [53]=>
  float(42.857)
  [54]=>
  float(-57.142)
  [55]=>
  float(-57.142)
  [56]=>
  float(-57.142)
  [57]=>
  float(-57.142)
  [58]=>
  float(-57.142)
  [59]=>
  float(-57.142)
  [60]=>
  float(-57.142)
  [61]=>
  float(-35.714)
  [62]=>
  float(57.142)
  [63]=>
  float(64.285)
  [64]=>
  float(71.428)
  [65]=>
  float(78.571)
  [66]=>
  float(85.714)
  [67]=>
  float(85.714)
  [68]=>
  float(85.714)
  [69]=>
  float(78.571)
  [70]=>
  float(71.428)
  [71]=>
  float(-35.714)
  [72]=>
  float(-42.857)
  [73]=>
  float(-50)
  [74]=>
  float(-50)
  [75]=>
  float(14.285)
  [76]=>
  float(21.428)
  [77]=>
  float(28.571)
  [78]=>
  float(35.714)
  [79]=>
  float(35.714)
  [80]=>
  float(35.714)
  [81]=>
  float(35.714)
  [82]=>
  float(35.714)
  [83]=>
  float(71.428)
  [84]=>
  float(71.428)
  [85]=>
  float(71.428)
  [86]=>
  float(92.857)
  [87]=>
  float(100)
  [88]=>
  float(100)
  [89]=>
  float(100)
  [90]=>
  float(100)
  [91]=>
  float(92.857)
  [92]=>
  float(64.285)
  [93]=>
  float(64.285)
  [94]=>
  float(64.285)
  [95]=>
  float(64.285)
  [96]=>
  float(57.142)
  [97]=>
  float(42.857)
  [98]=>
  float(42.857)
  [99]=>
  float(35.714)
  [100]=>
  float(28.571)
  [101]=>
  float(7.142)
  [102]=>
  float(7.142)
  [103]=>
  float(7.142)
  [104]=>
  float(-92.857)
  [105]=>
  float(-85.714)
  [106]=>
  float(21.428)
  [107]=>
  float(21.428)
  [108]=>
  float(21.428)
  [109]=>
  float(21.428)
  [110]=>
  float(21.428)
  [111]=>
  float(21.428)
  [112]=>
  float(21.428)
  [113]=>
  float(21.428)
  [114]=>
  float(78.571)
  [115]=>
  float(78.571)
  [116]=>
  float(92.857)
  [117]=>
  float(100)
  [118]=>
  float(92.857)
  [119]=>
  float(85.714)
  [120]=>
  float(50)
  [121]=>
  float(50)
  [122]=>
  float(50)
  [123]=>
  float(92.857)
  [124]=>
  float(92.857)
  [125]=>
  float(100)
  [126]=>
  float(100)
  [127]=>
  float(92.857)
  [128]=>
  float(100)
  [129]=>
  float(100)
  [130]=>
  float(78.571)
  [131]=>
  float(85.714)
  [132]=>
  float(85.714)
  [133]=>
  float(85.714)
  [134]=>
  float(71.428)
  [135]=>
  float(71.428)
  [136]=>
  float(64.285)
  [137]=>
  float(57.142)
  [138]=>
  float(-50)
  [139]=>
  float(-57.142)
  [140]=>
  float(-57.142)
  [141]=>
  float(-57.142)
  [142]=>
  float(-57.142)
  [143]=>
  float(-57.142)
  [144]=>
  float(-57.142)
  [145]=>
  float(-100)
  [146]=>
  float(-78.571)
  [147]=>
  float(-85.714)
  [148]=>
  float(-92.857)
  [149]=>
  float(-92.857)
  [150]=>
  float(-85.714)
  [151]=>
  float(-78.571)
  [152]=>
  float(-42.857)
  [153]=>
  float(-42.857)
  [154]=>
  float(-42.857)
  [155]=>
  float(-42.857)
  [156]=>
  float(-42.857)
  [157]=>
  float(64.285)
  [158]=>
  float(64.285)
  [159]=>
  float(64.285)
  [160]=>
  float(64.285)
  [161]=>
  float(64.285)
  [162]=>
  float(64.285)
  [163]=>
  float(42.857)
  [164]=>
  float(42.857)
  [165]=>
  float(42.857)
  [166]=>
  float(35.714)
  [167]=>
  float(-35.714)
  [168]=>
  float(-35.714)
  [169]=>
  float(50)
  [170]=>
  float(57.142)
  [171]=>
  float(64.285)
  [172]=>
  float(71.428)
  [173]=>
  float(78.571)
  [174]=>
  float(78.571)
  [175]=>
  float(78.571)
  [176]=>
  float(78.571)
  [177]=>
  float(71.428)
  [178]=>
  float(57.142)
  [179]=>
  float(57.142)
  [180]=>
  float(50)
  [181]=>
  float(-35.714)
  [182]=>
  float(-64.285)
  [183]=>
  float(-71.428)
  [184]=>
  float(-71.428)
  [185]=>
  float(-71.428)
  [186]=>
  float(-92.857)
  [187]=>
  float(-100)
  [188]=>
  float(-100)
  [189]=>
  float(-85.714)
  [190]=>
  float(-85.714)
  [191]=>
  float(-78.571)
  [192]=>
  float(-100)
  [193]=>
  float(-100)
  [194]=>
  float(-92.857)
  [195]=>
  float(-92.857)
  [196]=>
  float(-100)
  [197]=>
  float(-92.857)
  [198]=>
  float(-100)
  [199]=>
  float(-92.857)
  [200]=>
  float(-57.142)
  [201]=>
  float(-57.142)
  [202]=>
  float(-85.714)
  [203]=>
  float(-85.714)
  [204]=>
  float(-85.714)
  [205]=>
  float(-78.571)
  [206]=>
  float(-71.428)
  [207]=>
  float(-57.142)
  [208]=>
  float(-57.142)
  [209]=>
  float(-50)
  [210]=>
  float(-7.142)
  [211]=>
  float(-7.142)
  [212]=>
  float(-7.142)
  [213]=>
  float(-7.142)
  [214]=>
  float(-7.142)
  [215]=>
  float(-7.142)
  [216]=>
  float(42.857)
  [217]=>
  float(-28.571)
  [218]=>
  float(-28.571)
  [219]=>
  float(-28.571)
  [220]=>
  float(-28.571)
  [221]=>
  float(-28.571)
  [222]=>
  float(-28.571)
  [223]=>
  float(78.571)
  [224]=>
  float(85.714)
  [225]=>
  float(92.857)
  [226]=>
  float(92.857)
  [227]=>
  float(85.714)
  [228]=>
  float(78.571)
  [229]=>
  float(71.428)
  [230]=>
  float(28.571)
  [231]=>
  float(28.571)
  [232]=>
  float(78.571)
  [233]=>
  float(85.714)
  [234]=>
  float(92.857)
  [235]=>
  float(100)
  [236]=>
  float(100)
  [237]=>
  float(92.857)
  [238]=>
  float(71.428)
  [239]=>
  float(71.428)
  [240]=>
  float(71.428)
  [241]=>
  float(50)
  [242]=>
  float(50)
  [243]=>
  float(50)
  [244]=>
  float(42.857)
  [245]=>
  float(35.714)
  [246]=>
  float(-28.571)
  [247]=>
  float(-28.571)
  [248]=>
  float(-28.571)
  [249]=>
  float(-28.571)
  [250]=>
  float(-28.571)
  [251]=>
  float(-14.285)
}
