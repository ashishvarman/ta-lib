/* TA-LIB Copyright (c) 1999-2004, Mario Fortier
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in
 *   the documentation and/or other materials provided with the
 *   distribution.
 *
 * - Neither name of author nor the names of its contributors
 *   may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef TA_DEFS_H
#define TA_DEFS_H

#include <limits.h>

/* Enumeration and macros used by C, C++ and managed C++ */

#if defined( _MANAGED )
  #define ENUM_BEGIN(x) __value enum x {
  #define ENUM_END(x) };
  
  #define STRUCT_BEGIN(x) __gc struct x {
  #define STRUCT_END(x) };
#else
  #define ENUM_BEGIN(x) typedef enum {
  #define ENUM_END(x) } x;

  #define STRUCT_BEGIN(x) typedef struct {
  #define STRUCT_END(x) } x;
#endif

/* Part of this file is generated by gen_code */

/* min/max value for a TA_Integer */
#define TA_INTEGER_MIN (INT_MIN+1)
#define TA_INTEGER_MAX (INT_MAX)

/* min/max value for a TA_Real 
 *
 * Use fix value making sense in the
 * context of TA-Lib (avoid to use DBL_MIN
 * and DBL_MAX standard macro because they
 * are troublesome with some compiler).
 */
#define TA_REAL_MIN (-3e+37)
#define TA_REAL_MAX (3e+37)

/* A value outside of the min/max range 
 * indicates an undefined or default value.
 */
#define TA_INTEGER_DEFAULT (INT_MIN)
#define TA_REAL_DEFAULT    (-4e+37)

ENUM_BEGIN(TA_RetCode)
    /****** TA-LIB Error Code *****/
    /*   0 */  TA_SUCCESS,            /* No error */
    /*   1 */  TA_LIB_NOT_INITIALIZE, /* TA_Initialize was not sucessfully called */
    /*   2 */  TA_BAD_PARAM,          /* A parameter is out of range */
    /*   3 */  TA_ALLOC_ERR,          /* Possibly out-of-memory */
    /*   4 */  TA_ACCESS_FAILED,      /* File system access failed */
    /*   5 */  TA_NO_DATA_SOURCE,     /* No data was added */
    /*   6 */  TA_SYMBOL_NOT_FOUND,   /* Symbol not found in this category */
    /*   7 */  TA_CATEGORY_NOT_FOUND, /* Category not found in the data base */
    /*   8 */  TA_KEY_NOT_FOUND,
    /*   9 */  TA_INDEX_FILE_NOT_ACCESSIBLE,
    /*  10 */  TA_INDEX_NOT_VALID,
    /*  11 */  TA_INVALID_FIELD,
    /*  12 */  TA_INVALID_PATH,
    /*  13 */  TA_INTERNAL_ERR,
    /*  14 */  TA_FATAL_ERR,
    /*  15 */  TA_NO_NEW_DATA,
    /*  16 */  TA_NOT_SUPPORTED,
    /*  17 */  TA_END_OF_INDEX,
    /*  18 */  TA_ENOUGH_DATA,
    /*  19 */  TA_MISSING_FIELD,
    /*  20 */  TA_REDUNDANT_FIELD,
    /*  21 */  TA_INVALID_DATE,
    /*  22 */  TA_INVALID_PRICE,
    /*  23 */  TA_GROUP_NOT_FOUND,
    /*  24 */  TA_FUNC_NOT_FOUND,
    /*  25 */  TA_INVALID_HANDLE,
    /*  26 */  TA_INVALID_PARAM_HOLDER,
    /*  27 */  TA_INVALID_PARAM_HOLDER_TYPE,
    /*  28 */  TA_INVALID_PARAM_FUNCTION,
    /*  29 */  TA_INPUT_NOT_ALL_INITIALIZE,
    /*  30 */  TA_OUTPUT_NOT_ALL_INITIALIZE,
    /*  31 */  TA_OUT_OF_RANGE_START_INDEX,
    /*  32 */  TA_OUT_OF_RANGE_END_INDEX,
    /*  33 */  TA_BAD_OBJECT,
    /*  34 */  TA_MEM_LEAK,
    /*  35 */  TA_ADDR_NOT_FOUND,
    /*  36 */  TA_SOCKET_LIB_INIT_ERR,
    /*  37 */  TA_END_OF_STREAM,
    /*  38 */  TA_BAD_STREAM_CRC,
    /*  39 */  TA_UNSUPPORTED_STREAM_VERSION,
    /*  40 */  TA_BAD_STREAM_HEADER_CRC,
    /*  41 */  TA_BAD_STREAM_HEADER,
    /*  42 */  TA_BAD_STREAM_CONTENT,
    /*  43 */  TA_BAD_YAHOO_IDX_HDR,
    /*  44 */  TA_UNSUPORTED_YAHOO_IDX_VERSION,
    /*  45 */  TA_BAD_YAHOO_IDX_INDICATOR_AF,
    /*  46 */  TA_BAD_YAHOO_IDX_INDICATOR_EB,
    /*  47 */  TA_BAD_YAHOO_IDX_INDICATOR_F2,
    /*  48 */  TA_NO_INTERNET_CONNECTION,
    /*  49 */  TA_INTERNET_ACCESS_FAILED,
    /*  50 */  TA_INTERNET_OPEN_FAILED,
    /*  51 */  TA_INTERNET_NOT_OPEN_TRY_AGAIN,
    /*  52 */  TA_INTERNET_SERVER_CONNECT_FAILED,
    /*  53 */  TA_INTERNET_OPEN_REQUEST_FAILED,
    /*  54 */  TA_INTERNET_SEND_REQUEST_FAILED,
    /*  55 */  TA_INTERNET_READ_DATA_FAILED,
    /*  56 */  TA_UNSUPPORTED_COUNTRY,
    /*  57 */  TA_BAD_HTML_SYNTAX,
    /*  58 */  TA_PERIOD_NOT_AVAILABLE,
    /*  59 */  TA_FINISH_TABLE,
    /*  60 */  TA_INVALID_SECURITY_EXCHANGE,
    /*  61 */  TA_INVALID_SECURITY_SYMBOL,
    /*  62 */  TA_INVALID_SECURITY_COUNTRY,
    /*  63 */  TA_INVALID_SECURITY_TYPE,
    /*  64 */  TA_MISSING_DATE_OR_TIME_FIELD,
    /*  65 */  TA_OBJECT_NOT_EQUAL,
    /*  66 */  TA_INVALID_LIST_TYPE,
    /*  67 */  TA_YAHOO_IDX_EXPIRED,
    /*  68 */  TA_YAHOO_IDX_UNAVAILABLE_1, /* Local cache does not have a Yahoo! index */
    /*  69 */  TA_YAHOO_IDX_FAILED,
    /*  70 */  TA_LIBCURL_GLOBAL_INIT_FAILED, /* libCurl shared library missing? */
    /*  71 */  TA_LIBCURL_INIT_FAILED,        /* libCurl shared library missing? */
    /*  72 */  TA_INSTRUMENT_ID_BAD,          /* TA_Instrument not initialized. */
    /*  73 */  TA_TRADE_LOG_NOT_INITIALIZED,  /* TA_TradeLog corrupted or not initialized */
    /*  74 */  TA_BAD_TRADE_TYPE,
    /*  75 */  TA_BAD_START_DATE,
    /*  76 */  TA_BAD_END_DATE,
    /*  77 */  TA_INTERNET_SET_RX_TIMEOUT_FAILED,
    /*  78 */  TA_NO_TRADE_LOG,
    /*  79 */  TA_ENTRY_TRANSACTION_MISSING,
    /*  80 */  TA_INVALID_VALUE_ID,
    /*  81 */  TA_BAD_STARTING_CAPITAL,
    /*  82 */  TA_TRADELOG_ALREADY_ADDED,  /* This TA_TradeLog is already added to this TA_PM. */
    /*  83 */  TA_YAHOO_IDX_UNAVAILABLE_2, /* Possibly timeout of internet connection */
    /*  84 */  TA_YAHOO_IDX_UNAVAILABLE_3, /* Failed to find a Yahoo! index */
    /*  85 */  TA_NO_WEEKDAY_IN_DATE_RANGE,
    /*  86 */  TA_VALUE_NOT_APPLICABLE,            /* This PM value is not applicable to these trades. */
    /*  87 */  TA_DATA_GAP,                        /* Data source returned data with gaps */
    /*  88 */  TA_NOT_IMPLEMENTED,                 /* Feature not implemented */
    /*  89 */  TA_PM_REFERENCE_EXIST,              /* Can not free a TA_TradeLog when added to a TA_PM */
    /*  90 */  TA_PRICE_BAR_CONTAINS_ZERO,         /* A price of zero is invalid in a price bar */
    /*  91 */  TA_MISSING_CLOSE_PRICE_FIELD,       /* Close must be provided with TA_REPLACE_ZERO_PRICE_BAR flag. */
    /*  92 */  TA_UNSUPPORTED_REPLACE_ZERO_PRICE_BAR, /* TA_REPLACE_ZERO_PRICE_BAR flag is not supported for this data source. */
    /*  93 */  TA_MISSING_INPUT_DIGITS,            /* A digit was missing in one of the price bar field */
    /*  94 */  TA_DICT_TYPE_MISMATCH,              /* Error with handling of dictionary */
    /*  95 */  TA_YAHOO_IDX_UNAVAILABLE_4,         /* Failed to find a Yahoo! index */
    /*  96 */  TA_OBSOLETED_SYMBOL,                /* This symbol is no longuer valid */
    /*  97 */  TA_BAD_QUERY,                       /* Query could not be executed or syntax error in query */
    /*  98 */  TA_UNSUPPORTED_DO_NOT_SPLIT_ADJUST, /* TA_DO_NOT_SPLIT_ADJUST flag is not supported by this data source */
    /*  99 */  TA_UNSUPPORTED_DO_NOT_VALUE_ADJUST, /* TA_DO_NOT_VALUE_ADJUST flag is not supported by this data source */
    /* 100 */  TA_MISSING_PRICE_FOR_ADJUSTMENT,    /* At least one price field must be requested when doing price adjustment. */
    /* 101 */  TA_INVALID_DATABASE_TYPE,           /* location parameter does not refer to a supported database type. */
    /* 102 */  TA_UNEXPECTED_SQL_TYPE,             /* One of the field is not of the expected SQL type. */
    /* 103 */  TA_UNEXPECTED_SQL_TYPE_FOR_OPEN,    /* Open price field is not of the expected SQL type. */
    /* 104 */  TA_UNEXPECTED_SQL_TYPE_FOR_HIGH,    /* High price field is not of the expected SQL type. */
    /* 105 */  TA_UNEXPECTED_SQL_TYPE_FOR_LOW,     /* Low price field is not of the expected SQL type. */
    /* 106 */  TA_UNEXPECTED_SQL_TYPE_FOR_CLOSE,   /* Close price field is not of the expected SQL type. */
    /* 107 */  TA_UNEXPECTED_SQL_TYPE_FOR_VOLUME,  /* Volume field is not of the expected SQL type. */
    /* 108 */  TA_UNEXPECTED_SQL_TYPE_FOR_OI,      /* Open interest field is not of the expected SQL type. */

    /****** IP Error Code *****/
    /* 700 */  TA_IP_NOSOCKETS = 700,  /* Sockets not supported      */
    /* 701 */  TA_IP_BADHOST,          /* Host not known             */
    /* 702 */  TA_IP_BADSERVICE,       /* Service or port not known  */
    /* 703 */  TA_IP_BADPROTOCOL,      /* Invalid protocol specified */
    /* 704 */  TA_IP_SOCKETERROR,      /* Error creating socket      */
    /* 705 */  TA_IP_CONNECTERROR,     /* Error making connection    */
    /* 706 */  TA_IP_BINDERROR,        /* Error binding socket       */
    /* 707 */  TA_IP_LISTENERROR,      /* Error preparing to listen  */
    /* 708 */  TA_IP_WRITE_ERROR,      /* Error writing to socket    */
    /* 709 */  TA_IP_READ_ERROR,       /* Error reading from socket  */
    /* 710 */  TA_IP_UNKNOWN_ERR,

    /****** HTTP Error Code (RFC1945) *****/
    /* 800 */  TA_HTTP_NO_HEADER = 800, /* HTTP header not found.     */
    /* 801 */  TA_HTTP_SC_301,          /* Moved Permanently          */
    /* 802 */  TA_HTTP_SC_302,          /* Moved Temporarily          */
    /* 803 */  TA_HTTP_SC_304,          /* Not Modified               */
    /* 804 */  TA_HTTP_SC_400,          /* Bad Request                */
    /* 805 */  TA_HTTP_SC_401,          /* Unauthorized               */
    /* 806 */  TA_HTTP_SC_403,          /* Forbidden                  */
    /* 807 */  TA_HTTP_SC_404,          /* Not Found                  */
    /* 808 */  TA_HTTP_SC_500,          /* Internal Server Error      */
    /* 809 */  TA_HTTP_SC_501,          /* Not Implemented            */
    /* 810 */  TA_HTTP_SC_502,          /* Bad Gateway                */
    /* 811 */  TA_HTTP_SC_503,          /* Service Unavailable        */
    /* 812 */  TA_HTTP_SC_UNKNOWN,      /* Unknown error code.        */ 

    /****** CSI Error Code *****/
    /* 900 */  TA_CSI_UNABLE_OPEN_QMASTER_FILE = 900, /* QMaster file unaccessible */
    /* 901 */  TA_CSI_QMASTER_READ_ERROR,             /* QMaster file read error */
    /* 902 */  TA_CSI_QMASTER_BAD_PERIOD,             /* QMaster has invalid period */
    /* 903 */  TA_CSI_QMASTER_INVALID_STOCKCOM_FIELD, /* QMaster has invalid Stock/Commodity field */
    /* 904 */  TA_CSI_QMASTER_INVALID_DELETED_FIELD,  /* QMaster has invalid Deleted field */
    /* 905 */  TA_CSI_QMASTER_INVALID_PUTCALL_FIELD,  /* QMaster has invalid Put/Call field */
    /* 906 */  TA_CSI_UNABLE_OPEN_QMASTER2_FILE,      /* QMaster2 file unaccessible */
    /* 907 */  TA_CSI_QMASTER2_READ_ERROR,            /* QMaster2 file read error */
    /* 908 */  TA_CSI_QMASTER2_BAD_PERIOD,            /* QMaster2 has invalid period */
    /* 909 */  TA_CSI_QMASTER2_INVALID_STOCKCOM_FIELD,/* QMaster2 has invalid Stock/Commodity field */
    /* 910 */  TA_CSI_QMASTER2_INVALID_DELETED_FIELD, /* QMaster2 has invalid Deleted field */
    /* 911 */  TA_CSI_UNKNOWN_QMASTER_VERSION,        /* Unknown QMaster file version */
    /* 912 */  TA_CSI_DATA_FILE_HEADER_READ_ERROR,    /* Read failure on CSI data file header */
    /* 913 */  TA_CSI_DATA_FILE_READ_ERROR,           /* Read failure on CSI data file */
    /* 914 */  TA_CSI_DATA_FILE_HEADER_READ_ERROR_2,  /* Read failure on CSI data file header (Version 2) */
    /* 915 */  TA_CSI_DATA_FILE_READ_ERROR_2,         /* Read failure on CSI data file (Version 2) */
    /* 916 */  TA_CSI_UNKNOWN_DATA_FILE_VERSION,      /* Unknown data file version */
    /* 917 */  TA_CSI_DATA_FILE_MISSING,              /* No CSI data file file found */
    /* 918 */  TA_CSI_DATA_FILE_ACCESS_FAILED,        /* Unable to open CSI data file */
    /* 919 */  TA_CSI_MASTER_FILE_NOT_FOUND,          /* 'master' file not found */
    /* 920 */  TA_CSI_MASTER_FILE_ACCESS_FAILED,      /* Unable to open 'master' file */
    /* 921 */  TA_CSI_MASTER_BAD_PERIOD,              /* Bad period in 'master' file */
    /* 922 */  TA_CSI_MISSING_CSIM_DATA_FILE,         /* Missing CSIM data file */
    /* 923 */  TA_CSI_FAIL_TO_OPEN_CSIM_DATA_FILE,    /* Unable to open CSIM data file */
    /* 924 */  TA_CSI_READ_FAIL_CSIM_HEADER_FILE,     /* Read failure on CSIM data file header */
    /* 925 */  TA_CSI_READ_FAIL_CSIM_DATA_FILE,       /* Read failure on CSIM data file */
    /* 926 */  TA_CSI_HEADER_READ_FAILED_CSIM,        /* Failed to read CSIM header file */
    /* 927 */  TA_CSI_UNABLE_FIND_QMASTER_FILE,       /* No QMaster or QMaster2 files found */

    /****** TA-LIB Internal Error Code *****/

    /* 5000 */ TA_INTERNAL_ERROR = 5000, /* Internal Error - Contact TA-Lib.org */

    /****** TA-Lib Contributors: See ta_trace.h for the TA_INTERNAL_ERROR macro *****/

    TA_UNKNOWN_ERR = 0xFFFF
ENUM_END(TA_RetCode)

ENUM_BEGIN( TA_Compatibility )
    TA_COMPATIBILITY_DEFAULT,
    TA_COMPATIBILITY_METASTOCK
ENUM_END( TA_Compatibility )

/**** START GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/

#if defined( _MANAGED )
__value enum TA_MAType
#else
typedef enum
#endif
{
   TA_MAType_SMA       =0,
   TA_MAType_EMA       =1,
   TA_MAType_WMA       =2,
   TA_MAType_DEMA      =3,
   TA_MAType_TEMA      =4,
   TA_MAType_TRIMA     =5,
   TA_MAType_KAMA      =6,
   TA_MAType_MAMA      =7,
   TA_MAType_T3        =8
#if defined( _MANAGED )
};
#else
} TA_MAType;
#endif

#if defined( _MANAGED )
__value enum TA_FuncUnstId
#else
typedef enum
#endif
{
    /* 000 */  TA_FUNC_UNST_EMA,
    /* 001 */  TA_FUNC_UNST_HT_TRENDLINE,
    /* 002 */  TA_FUNC_UNST_KAMA,
    /* 003 */  TA_FUNC_UNST_MAMA,
    /* 004 */  TA_FUNC_UNST_T3,
    /* 005 */  TA_FUNC_UNST_ATR,
    /* 006 */  TA_FUNC_UNST_ADX,
    /* 007 */  TA_FUNC_UNST_ADXR,
    /* 008 */  TA_FUNC_UNST_DX,
    /* 009 */  TA_FUNC_UNST_MFI,
    /* 010 */  TA_FUNC_UNST_MINUS_DI,
    /* 011 */  TA_FUNC_UNST_MINUS_DM,
    /* 012 */  TA_FUNC_UNST_PLUS_DI,
    /* 013 */  TA_FUNC_UNST_PLUS_DM,
    /* 014 */  TA_FUNC_UNST_RSI,
    /* 015 */  TA_FUNC_UNST_STOCHRSI,
    /* 016 */  TA_FUNC_UNST_HT_DCPERIOD,
    /* 017 */  TA_FUNC_UNST_HT_DCPHASE,
    /* 018 */  TA_FUNC_UNST_HT_PHASOR,
    /* 019 */  TA_FUNC_UNST_HT_SINE,
    /* 020 */  TA_FUNC_UNST_HT_TRENDMODE,
               TA_FUNC_UNST_ALL,
               TA_FUNC_UNST_NONE=-1
#if defined( _MANAGED )
};
#else
} TA_FuncUnstId;
#endif
/**** END GENCODE SECTION 1 - DO NOT DELETE THIS LINE ****/

/* The TA_RangeType enum specifies the types of range that can be considered 
 * when to compare a part of a candle to other candles
 */

ENUM_BEGIN( TA_RangeType )
   TA_RangeType_RealBody,
   TA_RangeType_HighLow,
   TA_RangeType_Shadows
ENUM_END( TA_RangeType )

/* The TA_CandleSettingType enum specifies which kind of setting to consider;
 * the settings are based on the parts of the candle and the common words
 * indicating the length (short, long, very long)
 */
ENUM_BEGIN( TA_CandleSettingType )
    TA_BodyLong,
    TA_BodyVeryLong,
    TA_BodyShort,
    TA_BodyDoji,
    TA_ShadowLong,
    TA_ShadowVeryLong,
    TA_ShadowShort,
    TA_ShadowVeryShort,
    TA_AllCandleSettings
ENUM_END( TA_CandleSettingType )

#endif


