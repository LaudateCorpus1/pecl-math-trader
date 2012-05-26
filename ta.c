/*
	Copyright (c) 2012, Anatoliy Belsky <ab@php.net>
	All rights reserved.

	Redistribution and use in source and binary forms, with or without
	modification, are permitted provided that the following conditions
	are met:

	- Redistributions of source code must retain the above copyright
	notice, this list of conditions and the following disclaimer.

	- Redistributions in binary form must reproduce the above copyright
	notice, this list of conditions and the following disclaimer in the
	documentation and/or other materials provided with the distribution.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
	A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
	HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
	SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
	LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
	DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
	THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
	(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
	OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_ta.h"

#include <ta_func.h>
#include <ta_common.h>

ZEND_DECLARE_MODULE_GLOBALS(ta)

/* True global resources - no need for thread safety here */
static int le_ta;

/* {{{ ta_arginfo */
ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_acos, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ad, 0, 0, 4)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, inVolume)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_add, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal0)
	ZEND_ARG_INFO(0, inReal1)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_adosc, 0, 0, 4)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, inVolume)
	ZEND_ARG_INFO(0, optInFastPeriod)
	ZEND_ARG_INFO(0, optInSlowPeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_adx, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_adxr, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_apo, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInFastPeriod)
	ZEND_ARG_INFO(0, optInSlowPeriod)
	ZEND_ARG_INFO(0, optInMAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_aroon, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_aroonosc, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_asin, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_atan, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_atr, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_avgprice, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_bbands, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
	ZEND_ARG_INFO(0, optInNbDevUp)
	ZEND_ARG_INFO(0, optInNbDevDn)
	ZEND_ARG_INFO(0, optInMAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_beta, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal0)
	ZEND_ARG_INFO(0, inReal1)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_bop, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cci, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdl2crows, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdl3blackcrows, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdl3inside, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdl3linestrike, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdl3outside, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdl3starsinsouth, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdl3whitesoldiers, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlabandonedbaby, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInPenetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdladvanceblock, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlbelthold, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlbreakaway, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlclosingmarubozu, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlconcealbabyswall, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlcounterattack, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdldarkcloudcover, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInPenetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdldoji, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdldojistar, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdldragonflydoji, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlengulfing, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdleveningdojistar, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInPenetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdleveningstar, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInPenetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlgapsidesidewhite, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlgravestonedoji, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlhammer, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlhangingman, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlharami, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlharamicross, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlhighwave, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlhikkake, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlhikkakemod, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlhomingpigeon, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlidentical3crows, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlinneck, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlinvertedhammer, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlkicking, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlkickingbylength, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlladderbottom, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdllongleggeddoji, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdllongline, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlmarubozu, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlmatchinglow, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlmathold, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInPenetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlmorningdojistar, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInPenetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlmorningstar, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInPenetration)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlonneck, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlpiercing, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlrickshawman, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlrisefall3methods, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlseparatinglines, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlshootingstar, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlshortline, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlspinningtop, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlstalledpattern, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlsticksandwich, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdltakuri, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdltasukigap, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlthrusting, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdltristar, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlunique3river, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlupsidegap2crows, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cdlxsidegap3methods, 0, 0, 4)
	ZEND_ARG_INFO(0, inOpen)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ceil, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cmo, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_correl, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal0)
	ZEND_ARG_INFO(0, inReal1)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cos, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_cosh, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_dema, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_div, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal0)
	ZEND_ARG_INFO(0, inReal1)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_dx, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ema, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_exp, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_floor, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ht_dcperiod, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ht_dcphase, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ht_phasor, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ht_sine, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ht_trendline, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ht_trendmode, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_kama, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_linearreg, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_linearreg_angle, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_linearreg_intercept, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_linearreg_slope, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ln, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_log10, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ma, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
	ZEND_ARG_INFO(0, optInMAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_macd, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInFastPeriod)
	ZEND_ARG_INFO(0, optInSlowPeriod)
	ZEND_ARG_INFO(0, optInSignalPeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_macdext, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInFastPeriod)
	ZEND_ARG_INFO(0, optInFastMAType)
	ZEND_ARG_INFO(0, optInSlowPeriod)
	ZEND_ARG_INFO(0, optInSlowMAType)
	ZEND_ARG_INFO(0, optInSignalPeriod)
	ZEND_ARG_INFO(0, optInSignalMAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_macdfix, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInSignalPeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_mama, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInFastLimit)
	ZEND_ARG_INFO(0, optInSlowLimit)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_mavp, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, inPeriods)
	ZEND_ARG_INFO(0, optInMinPeriod)
	ZEND_ARG_INFO(0, optInMaxPeriod)
	ZEND_ARG_INFO(0, optInMAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_max, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_maxindex, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_medprice, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_mfi, 0, 0, 4)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, inVolume)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_midpoint, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_midprice, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_min, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_minindex, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_minmax, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_minmaxindex, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_minus_di, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_minus_dm, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_mom, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_mult, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal0)
	ZEND_ARG_INFO(0, inReal1)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_natr, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_obv, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, inVolume)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_plus_di, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_plus_dm, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ppo, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInFastPeriod)
	ZEND_ARG_INFO(0, optInSlowPeriod)
	ZEND_ARG_INFO(0, optInMAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_roc, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_rocp, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_rocr, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_rocr100, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_rsi, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sar, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, optInAcceleration)
	ZEND_ARG_INFO(0, optInMaximum)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sarext, 0, 0, 2)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, optInStartValue)
	ZEND_ARG_INFO(0, optInOffsetOnReverse)
	ZEND_ARG_INFO(0, optInAccelerationInitLong)
	ZEND_ARG_INFO(0, optInAccelerationLong)
	ZEND_ARG_INFO(0, optInAccelerationMaxLong)
	ZEND_ARG_INFO(0, optInAccelerationInitShort)
	ZEND_ARG_INFO(0, optInAccelerationShort)
	ZEND_ARG_INFO(0, optInAccelerationMaxShort)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sin, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sinh, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sma, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sqrt, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_stddev, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
	ZEND_ARG_INFO(0, optInNbDev)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_stoch, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInFastK_Period)
	ZEND_ARG_INFO(0, optInSlowK_Period)
	ZEND_ARG_INFO(0, optInSlowK_MAType)
	ZEND_ARG_INFO(0, optInSlowD_Period)
	ZEND_ARG_INFO(0, optInSlowD_MAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_stochf, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInFastK_Period)
	ZEND_ARG_INFO(0, optInFastD_Period)
	ZEND_ARG_INFO(0, optInFastD_MAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_stochrsi, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
	ZEND_ARG_INFO(0, optInFastK_Period)
	ZEND_ARG_INFO(0, optInFastD_Period)
	ZEND_ARG_INFO(0, optInFastD_MAType)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sub, 0, 0, 2)
	ZEND_ARG_INFO(0, inReal0)
	ZEND_ARG_INFO(0, inReal1)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_sum, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_t3, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
	ZEND_ARG_INFO(0, optInVFactor)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_tan, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_tanh, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_tema, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_trange, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_trima, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_trix, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_tsf, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_typprice, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_ultosc, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod1)
	ZEND_ARG_INFO(0, optInTimePeriod2)
	ZEND_ARG_INFO(0, optInTimePeriod3)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_var, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
	ZEND_ARG_INFO(0, optInNbDev)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_wclprice, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_willr, 0, 0, 3)
	ZEND_ARG_INFO(0, inHigh)
	ZEND_ARG_INFO(0, inLow)
	ZEND_ARG_INFO(0, inClose)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();

ZEND_BEGIN_ARG_INFO_EX(arg_info_ta_wma, 0, 0, 1)
	ZEND_ARG_INFO(0, inReal)
	ZEND_ARG_INFO(0, optInTimePeriod)
ZEND_END_ARG_INFO();
/* }}} */

/* {{{ ta_functions[]
 *
 * Every user visible function must have an entry in ta_functions[].
 */
const zend_function_entry ta_functions[] = {
	PHP_FE(ta_acos, arg_info_ta_acos)
	PHP_FE(ta_ad, arg_info_ta_ad)
	PHP_FE(ta_add, arg_info_ta_add)
	PHP_FE(ta_adosc, arg_info_ta_adosc)
	PHP_FE(ta_adx, arg_info_ta_adx)
	PHP_FE(ta_adxr, arg_info_ta_adxr)
	PHP_FE(ta_apo, arg_info_ta_apo)
	PHP_FE(ta_aroon, arg_info_ta_aroon)
	PHP_FE(ta_aroonosc, arg_info_ta_aroonosc)
	PHP_FE(ta_asin, arg_info_ta_asin)
	PHP_FE(ta_atan, arg_info_ta_atan)
	PHP_FE(ta_atr, arg_info_ta_atr)
	PHP_FE(ta_avgprice, arg_info_ta_avgprice)
	PHP_FE(ta_bbands, arg_info_ta_bbands)
	PHP_FE(ta_beta, arg_info_ta_beta)
	PHP_FE(ta_bop, arg_info_ta_bop)
	PHP_FE(ta_cci, arg_info_ta_cci)
	PHP_FE(ta_cdl2crows, arg_info_ta_cdl2crows)
	PHP_FE(ta_cdl3blackcrows, arg_info_ta_cdl3blackcrows)
	PHP_FE(ta_cdl3inside, arg_info_ta_cdl3inside)
	PHP_FE(ta_cdl3linestrike, arg_info_ta_cdl3linestrike)
	PHP_FE(ta_cdl3outside, arg_info_ta_cdl3outside)
	PHP_FE(ta_cdl3starsinsouth, arg_info_ta_cdl3starsinsouth)
	PHP_FE(ta_cdl3whitesoldiers, arg_info_ta_cdl3whitesoldiers)
	PHP_FE(ta_cdlabandonedbaby, arg_info_ta_cdlabandonedbaby)
	PHP_FE(ta_cdladvanceblock, arg_info_ta_cdladvanceblock)
	PHP_FE(ta_cdlbelthold, arg_info_ta_cdlbelthold)
	PHP_FE(ta_cdlbreakaway, arg_info_ta_cdlbreakaway)
	PHP_FE(ta_cdlclosingmarubozu, arg_info_ta_cdlclosingmarubozu)
	PHP_FE(ta_cdlconcealbabyswall, arg_info_ta_cdlconcealbabyswall)
	PHP_FE(ta_cdlcounterattack, arg_info_ta_cdlcounterattack)
	PHP_FE(ta_cdldarkcloudcover, arg_info_ta_cdldarkcloudcover)
	PHP_FE(ta_cdldoji, arg_info_ta_cdldoji)
	PHP_FE(ta_cdldojistar, arg_info_ta_cdldojistar)
	PHP_FE(ta_cdldragonflydoji, arg_info_ta_cdldragonflydoji)
	PHP_FE(ta_cdlengulfing, arg_info_ta_cdlengulfing)
	PHP_FE(ta_cdleveningdojistar, arg_info_ta_cdleveningdojistar)
	PHP_FE(ta_cdleveningstar, arg_info_ta_cdleveningstar)
	PHP_FE(ta_cdlgapsidesidewhite, arg_info_ta_cdlgapsidesidewhite)
	PHP_FE(ta_cdlgravestonedoji, arg_info_ta_cdlgravestonedoji)
	PHP_FE(ta_cdlhammer, arg_info_ta_cdlhammer)
	PHP_FE(ta_cdlhangingman, arg_info_ta_cdlhangingman)
	PHP_FE(ta_cdlharami, arg_info_ta_cdlharami)
	PHP_FE(ta_cdlharamicross, arg_info_ta_cdlharamicross)
	PHP_FE(ta_cdlhighwave, arg_info_ta_cdlhighwave)
	PHP_FE(ta_cdlhikkake, arg_info_ta_cdlhikkake)
	PHP_FE(ta_cdlhikkakemod, arg_info_ta_cdlhikkakemod)
	PHP_FE(ta_cdlhomingpigeon, arg_info_ta_cdlhomingpigeon)
	PHP_FE(ta_cdlidentical3crows, arg_info_ta_cdlidentical3crows)
	PHP_FE(ta_cdlinneck, arg_info_ta_cdlinneck)
	PHP_FE(ta_cdlinvertedhammer, arg_info_ta_cdlinvertedhammer)
	PHP_FE(ta_cdlkicking, arg_info_ta_cdlkicking)
	PHP_FE(ta_cdlkickingbylength, arg_info_ta_cdlkickingbylength)
	PHP_FE(ta_cdlladderbottom, arg_info_ta_cdlladderbottom)
	PHP_FE(ta_cdllongleggeddoji, arg_info_ta_cdllongleggeddoji)
	PHP_FE(ta_cdllongline, arg_info_ta_cdllongline)
	PHP_FE(ta_cdlmarubozu, arg_info_ta_cdlmarubozu)
	PHP_FE(ta_cdlmatchinglow, arg_info_ta_cdlmatchinglow)
	PHP_FE(ta_cdlmathold, arg_info_ta_cdlmathold)
	PHP_FE(ta_cdlmorningdojistar, arg_info_ta_cdlmorningdojistar)
	PHP_FE(ta_cdlmorningstar, arg_info_ta_cdlmorningstar)
	PHP_FE(ta_cdlonneck, arg_info_ta_cdlonneck)
	PHP_FE(ta_cdlpiercing, arg_info_ta_cdlpiercing)
	PHP_FE(ta_cdlrickshawman, arg_info_ta_cdlrickshawman)
	PHP_FE(ta_cdlrisefall3methods, arg_info_ta_cdlrisefall3methods)
	PHP_FE(ta_cdlseparatinglines, arg_info_ta_cdlseparatinglines)
	PHP_FE(ta_cdlshootingstar, arg_info_ta_cdlshootingstar)
	PHP_FE(ta_cdlshortline, arg_info_ta_cdlshortline)
	PHP_FE(ta_cdlspinningtop, arg_info_ta_cdlspinningtop)
	PHP_FE(ta_cdlstalledpattern, arg_info_ta_cdlstalledpattern)
	PHP_FE(ta_cdlsticksandwich, arg_info_ta_cdlsticksandwich)
	PHP_FE(ta_cdltakuri, arg_info_ta_cdltakuri)
	PHP_FE(ta_cdltasukigap, arg_info_ta_cdltasukigap)
	PHP_FE(ta_cdlthrusting, arg_info_ta_cdlthrusting)
	PHP_FE(ta_cdltristar, arg_info_ta_cdltristar)
	PHP_FE(ta_cdlunique3river, arg_info_ta_cdlunique3river)
	PHP_FE(ta_cdlupsidegap2crows, arg_info_ta_cdlupsidegap2crows)
	PHP_FE(ta_cdlxsidegap3methods, arg_info_ta_cdlxsidegap3methods)
	PHP_FE(ta_ceil, arg_info_ta_ceil)
	PHP_FE(ta_cmo, arg_info_ta_cmo)
	PHP_FE(ta_correl, arg_info_ta_correl)
	PHP_FE(ta_cos, arg_info_ta_cos)
	PHP_FE(ta_cosh, arg_info_ta_cosh)
	PHP_FE(ta_dema, arg_info_ta_dema)
	PHP_FE(ta_div, arg_info_ta_div)
	PHP_FE(ta_dx, arg_info_ta_dx)
	PHP_FE(ta_ema, arg_info_ta_ema)
	PHP_FE(ta_exp, arg_info_ta_exp)
	PHP_FE(ta_floor, arg_info_ta_floor)
	PHP_FE(ta_ht_dcperiod, arg_info_ta_ht_dcperiod)
	PHP_FE(ta_ht_dcphase, arg_info_ta_ht_dcphase)
	PHP_FE(ta_ht_phasor, arg_info_ta_ht_phasor)
	PHP_FE(ta_ht_sine, arg_info_ta_ht_sine)
	PHP_FE(ta_ht_trendline, arg_info_ta_ht_trendline)
	PHP_FE(ta_ht_trendmode, arg_info_ta_ht_trendmode)
	PHP_FE(ta_kama, arg_info_ta_kama)
	PHP_FE(ta_linearreg, arg_info_ta_linearreg)
	PHP_FE(ta_linearreg_angle, arg_info_ta_linearreg_angle)
	PHP_FE(ta_linearreg_intercept, arg_info_ta_linearreg_intercept)
	PHP_FE(ta_linearreg_slope, arg_info_ta_linearreg_slope)
	PHP_FE(ta_ln, arg_info_ta_ln)
	PHP_FE(ta_log10, arg_info_ta_log10)
	PHP_FE(ta_ma, arg_info_ta_ma)
	PHP_FE(ta_macd, arg_info_ta_macd)
	PHP_FE(ta_macdext, arg_info_ta_macdext)
	PHP_FE(ta_macdfix, arg_info_ta_macdfix)
	PHP_FE(ta_mama, arg_info_ta_mama)
	PHP_FE(ta_mavp, arg_info_ta_mavp)
	PHP_FE(ta_max, arg_info_ta_max)
	PHP_FE(ta_maxindex, arg_info_ta_maxindex)
	PHP_FE(ta_medprice, arg_info_ta_medprice)
	PHP_FE(ta_mfi, arg_info_ta_mfi)
	PHP_FE(ta_midpoint, arg_info_ta_midpoint)
	PHP_FE(ta_midprice, arg_info_ta_midprice)
	PHP_FE(ta_min, arg_info_ta_min)
	PHP_FE(ta_minindex, arg_info_ta_minindex)
	PHP_FE(ta_minmax, arg_info_ta_minmax)
	PHP_FE(ta_minmaxindex, arg_info_ta_minmaxindex)
	PHP_FE(ta_minus_di, arg_info_ta_minus_di)
	PHP_FE(ta_minus_dm, arg_info_ta_minus_dm)
	PHP_FE(ta_mom, arg_info_ta_mom)
	PHP_FE(ta_mult, arg_info_ta_mult)
	PHP_FE(ta_natr, arg_info_ta_natr)
	PHP_FE(ta_obv, arg_info_ta_obv)
	PHP_FE(ta_plus_di, arg_info_ta_plus_di)
	PHP_FE(ta_plus_dm, arg_info_ta_plus_dm)
	PHP_FE(ta_ppo, arg_info_ta_ppo)
	PHP_FE(ta_roc, arg_info_ta_roc)
	PHP_FE(ta_rocp, arg_info_ta_rocp)
	PHP_FE(ta_rocr, arg_info_ta_rocr)
	PHP_FE(ta_rocr100, arg_info_ta_rocr100)
	PHP_FE(ta_rsi, arg_info_ta_rsi)
	PHP_FE(ta_sar, arg_info_ta_sar)
	PHP_FE(ta_sarext, arg_info_ta_sarext)
	PHP_FE(ta_sin, arg_info_ta_sin)
	PHP_FE(ta_sinh, arg_info_ta_sinh)
	PHP_FE(ta_sma, arg_info_ta_sma)
	PHP_FE(ta_sqrt, arg_info_ta_sqrt)
	PHP_FE(ta_stddev, arg_info_ta_stddev)
	PHP_FE(ta_stoch, arg_info_ta_stoch)
	PHP_FE(ta_stochf, arg_info_ta_stochf)
	PHP_FE(ta_stochrsi, arg_info_ta_stochrsi)
	PHP_FE(ta_sub, arg_info_ta_sub)
	PHP_FE(ta_sum, arg_info_ta_sum)
	PHP_FE(ta_t3, arg_info_ta_t3)
	PHP_FE(ta_tan, arg_info_ta_tan)
	PHP_FE(ta_tanh, arg_info_ta_tanh)
	PHP_FE(ta_tema, arg_info_ta_tema)
	PHP_FE(ta_trange, arg_info_ta_trange)
	PHP_FE(ta_trima, arg_info_ta_trima)
	PHP_FE(ta_trix, arg_info_ta_trix)
	PHP_FE(ta_tsf, arg_info_ta_tsf)
	PHP_FE(ta_typprice, arg_info_ta_typprice)
	PHP_FE(ta_ultosc, arg_info_ta_ultosc)
	PHP_FE(ta_var, arg_info_ta_var)
	PHP_FE(ta_wclprice, arg_info_ta_wclprice)
	PHP_FE(ta_willr, arg_info_ta_willr)
	PHP_FE(ta_wma, arg_info_ta_wma)
	PHP_FE_END
};
/* }}} */

/* {{{ ta_module_entry
 */
zend_module_entry ta_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
	STANDARD_MODULE_HEADER,
#endif
	"ta",
	ta_functions,
	PHP_MINIT(ta),
	PHP_MSHUTDOWN(ta),
	PHP_RINIT(ta),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(ta),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(ta),
#if ZEND_MODULE_API_NO >= 20010901
	"0.1", /* Replace with version number for your extension */
#endif
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_TA
ZEND_GET_MODULE(ta)
#endif

/* {{{ PHP_INI
 */
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("ta.real_precision", "3", PHP_INI_ALL, OnUpdateLong, real_precision, zend_ta_globals, ta_globals)
PHP_INI_END()
/* }}} */

/* {{{ php_ta_globals_ctor
 */
static void php_ta_globals_ctor(zend_ta_globals *ta_globals)
{
	ta_globals->real_precision = TA_DEFAULT_REAL_PRECISION;
}
/* }}} */

/* {{{ php_ta_globals_dtor
 */
static void php_ta_globals_dtor(zend_ta_globals *ta_globals)
{
	/* pass */
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(ta)
{
	ZEND_INIT_MODULE_GLOBALS(ta, php_ta_globals_ctor, php_ta_globals_dtor);

	REGISTER_INI_ENTRIES();

	REGISTER_LONG_CONSTANT("TA_MA_TYPE_SMA", TA_MAType_SMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_EMA", TA_MAType_EMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_WMA", TA_MAType_WMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_DEMA", TA_MAType_DEMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_TEMA", TA_MAType_TEMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_TRIMA", TA_MAType_TRIMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_KAMA", TA_MAType_KAMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_MAMA", TA_MAType_MAMA, CONST_CS | CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("TA_MA_TYPE_T3", TA_MAType_T3, CONST_CS | CONST_PERSISTENT);

	REGISTER_DOUBLE_CONSTANT("TA_REAL_MIN", TA_REAL_MIN, CONST_CS | CONST_PERSISTENT);
	REGISTER_DOUBLE_CONSTANT("TA_REAL_MAX", TA_REAL_MAX, CONST_CS | CONST_PERSISTENT);

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(ta)
{
	UNREGISTER_INI_ENTRIES();
#ifdef ZTS
	    ts_free_id(ta_globals_id);
#else
		php_ta_globals_dtor(&ta_globals TSRMLS_CC);
#endif

	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(ta)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(ta)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(ta)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "Technical Analysis Library Support", "enabled");
	php_info_print_table_header(2, "Version", TA_PHP_VERSION);
	php_info_print_table_header(2, "TA-Lib version", TA_GetVersionString());
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}
/* }}} */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
