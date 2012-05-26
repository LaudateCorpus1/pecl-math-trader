--TEST--
ta_apo() basic test
--SKIPIF--
if (!extension_loaded("ta")) die("skip");
--FILE--
<?php

include "data.php";
include "func.php";

$fast_period = 14;

var_dump(ta_apo(get_data("high", $data0), $fast_period));
--EXPECT--
array(228) {
  [13]=>
  float(0.711)
  [14]=>
  float(-3.055)
  [15]=>
  float(-2.684)
  [16]=>
  float(-1.427)
  [17]=>
  float(-2.329)
  [18]=>
  float(-2.759)
  [19]=>
  float(-1.785)
  [20]=>
  float(-2.265)
  [21]=>
  float(-3.767)
  [22]=>
  float(-4.513)
  [23]=>
  float(-5.495)
  [24]=>
  float(-6.557)
  [25]=>
  float(-5.869)
  [26]=>
  float(-4.82)
  [27]=>
  float(-2.254)
  [28]=>
  float(-0.183)
  [29]=>
  float(-0.029)
  [30]=>
  float(-0.067)
  [31]=>
  float(-0.762)
  [32]=>
  float(-0.323)
  [33]=>
  float(0.77)
  [34]=>
  float(2.107)
  [35]=>
  float(2.448)
  [36]=>
  float(1.025)
  [37]=>
  float(-0.958)
  [38]=>
  float(-2.09)
  [39]=>
  float(-2.377)
  [40]=>
  float(-2.519)
  [41]=>
  float(-0.939)
  [42]=>
  float(1.464)
  [43]=>
  float(2.151)
  [44]=>
  float(3.259)
  [45]=>
  float(3.679)
  [46]=>
  float(3.545)
  [47]=>
  float(3.488)
  [48]=>
  float(2.498)
  [49]=>
  float(2.377)
  [50]=>
  float(1.583)
  [51]=>
  float(-0.063)
  [52]=>
  float(-0.866)
  [53]=>
  float(-2.663)
  [54]=>
  float(-5.209)
  [55]=>
  float(-4.977)
  [56]=>
  float(-3.368)
  [57]=>
  float(-1.876)
  [58]=>
  float(-0.282)
  [59]=>
  float(1.117)
  [60]=>
  float(1.963)
  [61]=>
  float(1.279)
  [62]=>
  float(1.831)
  [63]=>
  float(3.98)
  [64]=>
  float(4.629)
  [65]=>
  float(4.589)
  [66]=>
  float(4.337)
  [67]=>
  float(2.761)
  [68]=>
  float(1.161)
  [69]=>
  float(0.746)
  [70]=>
  float(-0.602)
  [71]=>
  float(-2.254)
  [72]=>
  float(-3.822)
  [73]=>
  float(-5.349)
  [74]=>
  float(-5.113)
  [75]=>
  float(1.384)
  [76]=>
  float(9.246)
  [77]=>
  float(11.389)
  [78]=>
  float(12.575)
  [79]=>
  float(11.711)
  [80]=>
  float(9.401)
  [81]=>
  float(8.548)
  [82]=>
  float(8.352)
  [83]=>
  float(8.429)
  [84]=>
  float(7.313)
  [85]=>
  float(5.54)
  [86]=>
  float(5.176)
  [87]=>
  float(5.284)
  [88]=>
  float(4.593)
  [89]=>
  float(5.173)
  [90]=>
  float(9.794)
  [91]=>
  float(12.39)
  [92]=>
  float(9.926)
  [93]=>
  float(8.133)
  [94]=>
  float(6.85)
  [95]=>
  float(4.881)
  [96]=>
  float(2.784)
  [97]=>
  float(0.833)
  [98]=>
  float(-1.493)
  [99]=>
  float(-0.817)
  [100]=>
  float(0.537)
  [101]=>
  float(-0.659)
  [102]=>
  float(-2.368)
  [103]=>
  float(-3.462)
  [104]=>
  float(-2.193)
  [105]=>
  float(-1.092)
  [106]=>
  float(1.963)
  [107]=>
  float(3.93)
  [108]=>
  float(3.413)
  [109]=>
  float(1.956)
  [110]=>
  float(-0.214)
  [111]=>
  float(-0.636)
  [112]=>
  float(-0.111)
  [113]=>
  float(2.411)
  [114]=>
  float(3.89)
  [115]=>
  float(3.525)
  [116]=>
  float(4.551)
  [117]=>
  float(6.768)
  [118]=>
  float(5.354)
  [119]=>
  float(3.096)
  [120]=>
  float(3.586)
  [121]=>
  float(3.367)
  [122]=>
  float(2.829)
  [123]=>
  float(5.395)
  [124]=>
  float(7.337)
  [125]=>
  float(6.302)
  [126]=>
  float(6.474)
  [127]=>
  float(6.242)
  [128]=>
  float(6.088)
  [129]=>
  float(6.915)
  [130]=>
  float(7.586)
  [131]=>
  float(7.644)
  [132]=>
  float(6.527)
  [133]=>
  float(5.019)
  [134]=>
  float(3.679)
  [135]=>
  float(3.041)
  [136]=>
  float(-0.13)
  [137]=>
  float(-4.535)
  [138]=>
  float(-6.149)
  [139]=>
  float(-7.817)
  [140]=>
  float(-8.882)
  [141]=>
  float(-7.852)
  [142]=>
  float(-5.58)
  [143]=>
  float(-4.747)
  [144]=>
  float(-4.89)
  [145]=>
  float(-4.258)
  [146]=>
  float(-4.945)
  [147]=>
  float(-5.848)
  [148]=>
  float(-4.444)
  [149]=>
  float(-1.03)
  [150]=>
  float(-0.261)
  [151]=>
  float(-1.993)
  [152]=>
  float(-1.999)
  [153]=>
  float(-1.227)
  [154]=>
  float(-0.808)
  [155]=>
  float(1.123)
  [156]=>
  float(3.162)
  [157]=>
  float(3.827)
  [158]=>
  float(2.112)
  [159]=>
  float(-0.4)
  [160]=>
  float(-0.525)
  [161]=>
  float(-1.025)
  [162]=>
  float(-1.434)
  [163]=>
  float(-0.229)
  [164]=>
  float(0.282)
  [165]=>
  float(-0.065)
  [166]=>
  float(0.178)
  [167]=>
  float(1.283)
  [168]=>
  float(1.497)
  [169]=>
  float(1.988)
  [170]=>
  float(4.663)
  [171]=>
  float(6.45)
  [172]=>
  float(7.525)
  [173]=>
  float(8.448)
  [174]=>
  float(7.215)
  [175]=>
  float(4.44)
  [176]=>
  float(3.378)
  [177]=>
  float(2.323)
  [178]=>
  float(0.097)
  [179]=>
  float(-1.028)
  [180]=>
  float(-2.192)
  [181]=>
  float(-3.918)
  [182]=>
  float(-4.904)
  [183]=>
  float(-5.69)
  [184]=>
  float(-5.77)
  [185]=>
  float(-5.238)
  [186]=>
  float(-6.26)
  [187]=>
  float(-6.407)
  [188]=>
  float(-6.247)
  [189]=>
  float(-6.403)
  [190]=>
  float(-4.469)
  [191]=>
  float(-2.406)
  [192]=>
  float(-3.561)
  [193]=>
  float(-6.276)
  [194]=>
  float(-6.602)
  [195]=>
  float(-5.812)
  [196]=>
  float(-7.512)
  [197]=>
  float(-10.054)
  [198]=>
  float(-9.773)
  [199]=>
  float(-7.773)
  [200]=>
  float(-6.936)
  [201]=>
  float(-4.249)
  [202]=>
  float(-9.995)
  [203]=>
  float(-17.402)
  [204]=>
  float(-14.333)
  [205]=>
  float(-11.732)
  [206]=>
  float(-9.824)
  [207]=>
  float(-8.759)
  [208]=>
  float(-5.775)
  [209]=>
  float(-2.878)
  [210]=>
  float(-2.969)
  [211]=>
  float(-3.596)
  [212]=>
  float(-3.75)
  [213]=>
  float(-4.103)
  [214]=>
  float(-3.313)
  [215]=>
  float(-0.779)
  [216]=>
  float(0.49)
  [217]=>
  float(1.285)
  [218]=>
  float(0.799)
  [219]=>
  float(0.207)
  [220]=>
  float(-0.377)
  [221]=>
  float(-1.095)
  [222]=>
  float(0.582)
  [223]=>
  float(5.257)
  [224]=>
  float(9.521)
  [225]=>
  float(10.901)
  [226]=>
  float(8.427)
  [227]=>
  float(5.559)
  [228]=>
  float(4.743)
  [229]=>
  float(3.35)
  [230]=>
  float(2.573)
  [231]=>
  float(2.849)
  [232]=>
  float(5.877)
  [233]=>
  float(9.534)
  [234]=>
  float(10.966)
  [235]=>
  float(11.35)
  [236]=>
  float(11.11)
  [237]=>
  float(6.092)
  [238]=>
  float(1.1)
  [239]=>
  float(0.202)
  [240]=>
  float(-2.412)
}
