--TEST--
trader_adosc() basic test
--SKIPIF--
<?php
if (!extension_loaded("trader")) die("skip");
--INI--
trader.real_precision=2
--FILE--
<?php

include "inc/data.php";
include "inc/func.php";

/* don't show notices */
var_dump(@trader_adosc(
	get_data("high", $data0),
	get_data("low", $data0),
	get_data("close", $data0),
	get_data("volume", $data0),
	NULL, 14
));

--EXPECT--
array(239) {
  [13]=>
  float(850629.11)
  [14]=>
  float(4887230.57)
  [15]=>
  float(8795101.46)
  [16]=>
  float(4913372.18)
  [17]=>
  float(2089939.47)
  [18]=>
  float(3103502.66)
  [19]=>
  float(1341754.9)
  [20]=>
  float(-490507.38)
  [21]=>
  float(-642511.88)
  [22]=>
  float(-3463916.04)
  [23]=>
  float(-6472312.7)
  [24]=>
  float(-5659496.1)
  [25]=>
  float(-7061872.44)
  [26]=>
  float(-3943014.72)
  [27]=>
  float(465284.2)
  [28]=>
  float(504336.74)
  [29]=>
  float(-1510020.21)
  [30]=>
  float(-2881435.09)
  [31]=>
  float(-972474.28)
  [32]=>
  float(-1644954.13)
  [33]=>
  float(760432.05)
  [34]=>
  float(318304.5)
  [35]=>
  float(-1707759.84)
  [36]=>
  float(278013.61)
  [37]=>
  float(1649035.29)
  [38]=>
  float(3145891.7)
  [39]=>
  float(1966019.21)
  [40]=>
  float(1184272.44)
  [41]=>
  float(-3428375.48)
  [42]=>
  float(-2028372.98)
  [43]=>
  float(-962929.58)
  [44]=>
  float(-171742.6)
  [45]=>
  float(-20383.15)
  [46]=>
  float(-842350.83)
  [47]=>
  float(-3587599.2)
  [48]=>
  float(-2206222.98)
  [49]=>
  float(-2510940.13)
  [50]=>
  float(-4111390.86)
  [51]=>
  float(-532574.83)
  [52]=>
  float(-4070422.82)
  [53]=>
  float(-7298492.57)
  [54]=>
  float(-8222905.15)
  [55]=>
  float(-6182819.44)
  [56]=>
  float(-5134785.41)
  [57]=>
  float(-5072015.71)
  [58]=>
  float(-3301734.06)
  [59]=>
  float(-2957262.47)
  [60]=>
  float(-3685723.34)
  [61]=>
  float(-2802928.54)
  [62]=>
  float(167596.93)
  [63]=>
  float(-492571.92)
  [64]=>
  float(1650494.21)
  [65]=>
  float(3560110.67)
  [66]=>
  float(4020367.96)
  [67]=>
  float(5839056.19)
  [68]=>
  float(4072751.28)
  [69]=>
  float(2348435.34)
  [70]=>
  float(2567794.26)
  [71]=>
  float(-563531.73)
  [72]=>
  float(-2845331.68)
  [73]=>
  float(675066.7)
  [74]=>
  float(5142091.42)
  [75]=>
  float(1769198.86)
  [76]=>
  float(637545.55)
  [77]=>
  float(4206084.84)
  [78]=>
  float(5069881.49)
  [79]=>
  float(3140339.94)
  [80]=>
  float(776782.69)
  [81]=>
  float(1280893.51)
  [82]=>
  float(3723068.33)
  [83]=>
  float(1945679.04)
  [84]=>
  float(3198032.74)
  [85]=>
  float(1976572.01)
  [86]=>
  float(3905325.57)
  [87]=>
  float(3227448.71)
  [88]=>
  float(4081451.7)
  [89]=>
  float(5721543.88)
  [90]=>
  float(12176846.61)
  [91]=>
  float(12316424.14)
  [92]=>
  float(12623568.73)
  [93]=>
  float(11190262.57)
  [94]=>
  float(9763232.88)
  [95]=>
  float(7101588.07)
  [96]=>
  float(4905304.17)
  [97]=>
  float(2566323.95)
  [98]=>
  float(-655581.05)
  [99]=>
  float(2685366.26)
  [100]=>
  float(6736101.16)
  [101]=>
  float(8717525.58)
  [102]=>
  float(7003981.64)
  [103]=>
  float(8368423.59)
  [104]=>
  float(7298670.56)
  [105]=>
  float(9148220.07)
  [106]=>
  float(10405160.82)
  [107]=>
  float(7057484.65)
  [108]=>
  float(3096797.2)
  [109]=>
  float(2008337.35)
  [110]=>
  float(1259379.39)
  [111]=>
  float(2237868.92)
  [112]=>
  float(1355065.59)
  [113]=>
  float(2406087.27)
  [114]=>
  float(1980089.51)
  [115]=>
  float(2577630.92)
  [116]=>
  float(3766860.57)
  [117]=>
  float(717515.54)
  [118]=>
  float(-285202.55)
  [119]=>
  float(-1402131.26)
  [120]=>
  float(-4035152.33)
  [121]=>
  float(-6778232.41)
  [122]=>
  float(-5683467.81)
  [123]=>
  float(-3631998.73)
  [124]=>
  float(-153829.03)
  [125]=>
  float(2755635.9)
  [126]=>
  float(680713.12)
  [127]=>
  float(1863163.82)
  [128]=>
  float(2396014.97)
  [129]=>
  float(4810266.22)
  [130]=>
  float(6341565.76)
  [131]=>
  float(6938401.17)
  [132]=>
  float(6286743.77)
  [133]=>
  float(5531458.94)
  [134]=>
  float(4331662.32)
  [135]=>
  float(1004671.63)
  [136]=>
  float(-2170890.36)
  [137]=>
  float(-648053.57)
  [138]=>
  float(-4182954.66)
  [139]=>
  float(-2776936.07)
  [140]=>
  float(-4449131.6)
  [141]=>
  float(-1652773.67)
  [142]=>
  float(1516734.42)
  [143]=>
  float(1535989.26)
  [144]=>
  float(1723378.93)
  [145]=>
  float(-300268.03)
  [146]=>
  float(-2765220.5)
  [147]=>
  float(-5592951.82)
  [148]=>
  float(-2972001.74)
  [149]=>
  float(-2496802.67)
  [150]=>
  float(-2905807.58)
  [151]=>
  float(-5237004.48)
  [152]=>
  float(-3148261.93)
  [153]=>
  float(-4719617.14)
  [154]=>
  float(-4528731.96)
  [155]=>
  float(-2235382.83)
  [156]=>
  float(1202694.27)
  [157]=>
  float(-1011174.57)
  [158]=>
  float(-1829060.47)
  [159]=>
  float(-3757141.45)
  [160]=>
  float(-1839059.9)
  [161]=>
  float(-2187092.97)
  [162]=>
  float(-2298584.84)
  [163]=>
  float(-3919512.91)
  [164]=>
  float(-3982236.27)
  [165]=>
  float(-5323771.56)
  [166]=>
  float(-4973271.39)
  [167]=>
  float(-3872889.43)
  [168]=>
  float(-2329090.72)
  [169]=>
  float(-1724389.56)
  [170]=>
  float(1342598.42)
  [171]=>
  float(-1593819.87)
  [172]=>
  float(-1036437.29)
  [173]=>
  float(-2482480.64)
  [174]=>
  float(-4543543.58)
  [175]=>
  float(-3042241.18)
  [176]=>
  float(-5355923.49)
  [177]=>
  float(-7784182.53)
  [178]=>
  float(-12380612.42)
  [179]=>
  float(-9820967.12)
  [180]=>
  float(-10016252.63)
  [181]=>
  float(-11040727.47)
  [182]=>
  float(-13691552.61)
  [183]=>
  float(-9266292.97)
  [184]=>
  float(-8676963.16)
  [185]=>
  float(-7041924.67)
  [186]=>
  float(-10425713.82)
  [187]=>
  float(-10301373.08)
  [188]=>
  float(-10423897.98)
  [189]=>
  float(-6076910.96)
  [190]=>
  float(-2895838.59)
  [191]=>
  float(-5714093.6)
  [192]=>
  float(-8797079.26)
  [193]=>
  float(-6808740.43)
  [194]=>
  float(-7161695.08)
  [195]=>
  float(-11041837.98)
  [196]=>
  float(-19027027.26)
  [197]=>
  float(-13555568.82)
  [198]=>
  float(-6315233.82)
  [199]=>
  float(-3290783.6)
  [200]=>
  float(-1644157.73)
  [201]=>
  float(-7091918.46)
  [202]=>
  float(-8035323.25)
  [203]=>
  float(-2493753.35)
  [204]=>
  float(552669.36)
  [205]=>
  float(3053652.94)
  [206]=>
  float(-1032898.6)
  [207]=>
  float(-600054.8)
  [208]=>
  float(2265187.77)
  [209]=>
  float(-616338.94)
  [210]=>
  float(-3065001.49)
  [211]=>
  float(-5087257.61)
  [212]=>
  float(-7867493.44)
  [213]=>
  float(-14980541.77)
  [214]=>
  float(-11157898.69)
  [215]=>
  float(-9634503.56)
  [216]=>
  float(-3897374.58)
  [217]=>
  float(-5330715.31)
  [218]=>
  float(-1318372.68)
  [219]=>
  float(-2875377.78)
  [220]=>
  float(-245167.72)
  [221]=>
  float(556274.97)
  [222]=>
  float(9658345.06)
  [223]=>
  float(18256675.1)
  [224]=>
  float(-21474836.48)
  [225]=>
  float(18415117.29)
  [226]=>
  float(18623389.66)
  [227]=>
  float(16922166.95)
  [228]=>
  float(15061623.37)
  [229]=>
  float(12539540.52)
  [230]=>
  float(10891381.48)
  [231]=>
  float(10417625.07)
  [232]=>
  float(14008042.67)
  [233]=>
  float(17773315.07)
  [234]=>
  float(15041493.94)
  [235]=>
  float(12962670.32)
  [236]=>
  float(4347388.21)
  [237]=>
  float(-828143)
  [238]=>
  float(-2194331.77)
  [239]=>
  float(-672364.52)
  [240]=>
  float(2110799.7)
  [241]=>
  float(5562174.12)
  [242]=>
  float(6602044.66)
  [243]=>
  float(6517111.69)
  [244]=>
  float(8460210.02)
  [245]=>
  float(6131504.2)
  [246]=>
  float(3420007.12)
  [247]=>
  float(3797285.96)
  [248]=>
  float(3323814.23)
  [249]=>
  float(1868650.02)
  [250]=>
  float(-192274.2)
  [251]=>
  float(-972559.42)
}
