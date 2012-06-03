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

#include "php.h"
#include "php_trader.h"

#include <ta_func.h>
#include <ta_common.h>

ZEND_EXTERN_MODULE_GLOBALS(trader)

/* {{{ proto array trader_stoch(array high, array low, array close [, int fastK_Period [, int slowK_Period [, int slowK_MAType [, int slowD_Period [, int slowD_MAType]]]]])
	Stochastic */
PHP_FUNCTION(trader_stoch)
{
	zval *zinHigh, *zinLow, *zinClose, *zoutSlowK;
	double *inHigh, *inLow, *inClose, *outSlowK, *outSlowD;
	int startIdx = 0, endIdx = 0, outBegIdx = 0, outNBElement = 0;
	long optInFastK_Period = 1, optInSlowK_Period = 1, optInSlowK_MAType = 0, optInSlowD_Period = 1, optInSlowD_MAType = 0;
	

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "aaa|lllll", &zinHigh, &zinLow, &zinClose, &optInFastK_Period, &optInSlowK_Period, &optInSlowK_MAType, &optInSlowD_Period, &optInSlowD_MAType) == FAILURE) {
		RETURN_FALSE
	}

	TRADER_CHECK_MA_TYPE(optInSlowK_MAType)
TRADER_CHECK_MA_TYPE(optInSlowD_MAType)
	TRADER_SET_BOUNDABLE(1, 100000, optInFastK_Period);
	TRADER_SET_BOUNDABLE(1, 100000, optInSlowK_Period);
	TRADER_SET_BOUNDABLE(1, 100000, optInSlowD_Period);	

	TRADER_SET_MIN_INT3(endIdx, zend_hash_num_elements(Z_ARRVAL_P(zinHigh)),
		zend_hash_num_elements(Z_ARRVAL_P(zinLow)),
		zend_hash_num_elements(Z_ARRVAL_P(zinClose)))
	endIdx--; /* it's <= in the ta-lib */
	

	outSlowK = emalloc(sizeof(double)*(endIdx+1));
	outSlowD = emalloc(sizeof(double)*(endIdx+1));
	TRADER_DBL_ZARR_TO_ARR(zinHigh, inHigh)
	TRADER_DBL_ZARR_TO_ARR(zinLow, inLow)
	TRADER_DBL_ZARR_TO_ARR(zinClose, inClose)

	/* XXX implement trader_get_last_error for non TA_SUCCESS returns */
	if (TA_STOCH(startIdx, endIdx, inHigh, inLow, inClose, (int)optInFastK_Period, (int)optInSlowK_Period, (int)optInSlowK_MAType, (int)optInSlowD_Period, (int)optInSlowD_MAType, &outBegIdx, &outNBElement, outSlowK, outSlowD) != TA_SUCCESS) {
		efree(inHigh);
		efree(inLow);
		efree(inClose);
		efree(outSlowK);
		efree(outSlowD);

		RETURN_FALSE
	}

	TRADER_DBL_ARR_TO_ZRET2(outSlowK, outSlowD, return_value, endIdx, outBegIdx, outNBElement)

	efree(inHigh);
	efree(inLow);
	efree(inClose);
	efree(outSlowK);
	efree(outSlowD);
}
/* }}} */

