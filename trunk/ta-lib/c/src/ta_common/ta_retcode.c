/* TA-LIB Copyright (c) 1999-2003, Mario Fortier
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

/* Important: This file is automatically generated by the utility gen_code.
 *            Any modification will be lost on next execution of gen_code.
 *
 * The goal of this file is to provide the functionality TA_SetRetCodeInfo.
 *
 * This function is a convenient way for the user to translate a TA_RetCode into
 * a human readable string.
 */
#include <ta_common.h>

typedef struct 
{
   TA_RetCode retCode;
   const char * const enumStr;
   const char * const infoStr;
} TA_InternalRetCodeInfo;

static TA_InternalRetCodeInfo retCodeInfoTable[] = {
         {0,"TA_SUCCESS","No error"},
         {1,"TA_LIB_NOT_INITIALIZE","TA_Initialize was not sucessfully called"},
         {2,"TA_BAD_PARAM","A parameter is out of range"},
         {3,"TA_ALLOC_ERR","Possibly out-of-memory"},
         {4,"TA_ACCESS_FAILED","File system access failed"},
         {5,"TA_NO_DATA_SOURCE","No data was added"},
         {6,"TA_SYMBOL_NOT_FOUND","Symbol not found in this category"},
         {7,"TA_CATEGORY_NOT_FOUND","Category not found in the data base"},
         {8,"TA_KEY_NOT_FOUND","No Info"},
         {9,"TA_INDEX_FILE_NOT_ACCESSIBLE","No Info"},
         {10,"TA_INDEX_NOT_VALID","No Info"},
         {11,"TA_INVALID_FIELD","No Info"},
         {12,"TA_INVALID_PATH","No Info"},
         {13,"TA_INTERNAL_ERR","No Info"},
         {14,"TA_FATAL_ERR","No Info"},
         {15,"TA_NO_NEW_DATA","No Info"},
         {16,"TA_NOT_SUPPORTED","No Info"},
         {17,"TA_END_OF_INDEX","No Info"},
         {18,"TA_ENOUGH_DATA","No Info"},
         {19,"TA_MISSING_FIELD","No Info"},
         {20,"TA_REDUNDANT_FIELD","No Info"},
         {21,"TA_INVALID_DATE","No Info"},
         {22,"TA_INVALID_PRICE","No Info"},
         {23,"TA_GROUP_NOT_FOUND","No Info"},
         {24,"TA_FUNC_NOT_FOUND","No Info"},
         {25,"TA_INVALID_HANDLE","No Info"},
         {26,"TA_INVALID_PARAM_HOLDER","No Info"},
         {27,"TA_INVALID_PARAM_HOLDER_TYPE","No Info"},
         {28,"TA_INVALID_PARAM_FUNCTION","No Info"},
         {29,"TA_INPUT_NOT_ALL_INITIALIZE","No Info"},
         {30,"TA_OUTPUT_NOT_ALL_INITIALIZE","No Info"},
         {31,"TA_OUT_OF_RANGE_START_INDEX","No Info"},
         {32,"TA_OUT_OF_RANGE_END_INDEX","No Info"},
         {33,"TA_BAD_OBJECT","No Info"},
         {34,"TA_MEM_LEAK","No Info"},
         {35,"TA_ADDR_NOT_FOUND","No Info"},
         {36,"TA_SOCKET_LIB_INIT_ERR","No Info"},
         {37,"TA_END_OF_STREAM","No Info"},
         {38,"TA_BAD_STREAM_CRC","No Info"},
         {39,"TA_UNSUPPORTED_STREAM_VERSION","No Info"},
         {40,"TA_BAD_STREAM_HEADER_CRC","No Info"},
         {41,"TA_BAD_STREAM_HEADER","No Info"},
         {42,"TA_BAD_STREAM_CONTENT","No Info"},
         {43,"TA_BAD_YAHOO_IDX_HDR","No Info"},
         {44,"TA_UNSUPORTED_YAHOO_IDX_VERSION","No Info"},
         {45,"TA_BAD_YAHOO_IDX_INDICATOR_AF","No Info"},
         {46,"TA_BAD_YAHOO_IDX_INDICATOR_EB","No Info"},
         {47,"TA_BAD_YAHOO_IDX_INDICATOR_F2","No Info"},
         {48,"TA_NO_INTERNET_CONNECTION","No Info"},
         {49,"TA_INTERNET_ACCESS_FAILED","No Info"},
         {50,"TA_INTERNET_OPEN_FAILED","No Info"},
         {51,"TA_INTERNET_NOT_OPEN_TRY_AGAIN","No Info"},
         {52,"TA_INTERNET_SERVER_CONNECT_FAILED","No Info"},
         {53,"TA_INTERNET_OPEN_REQUEST_FAILED","No Info"},
         {54,"TA_INTERNET_SEND_REQUEST_FAILED","No Info"},
         {55,"TA_INTERNET_READ_DATA_FAILED","No Info"},
         {56,"TA_UNSUPPORTED_COUNTRY","No Info"},
         {57,"TA_BAD_HTML_SYNTAX","No Info"},
         {58,"TA_PERIOD_NOT_AVAILABLE","No Info"},
         {59,"TA_FINISH_TABLE","No Info"},
         {60,"TA_INVALID_SECURITY_EXCHANGE","No Info"},
         {61,"TA_INVALID_SECURITY_SYMBOL","No Info"},
         {62,"TA_INVALID_SECURITY_COUNTRY","No Info"},
         {63,"TA_INVALID_SECURITY_TYPE","No Info"},
         {64,"TA_MISSING_DATE_OR_TIME_FIELD","No Info"},
         {65,"TA_OBJECT_NOT_EQUAL","No Info"},
         {66,"TA_INVALID_LIST_TYPE","No Info"},
         {67,"TA_YAHOO_IDX_EXPIRED","No Info"},
         {68,"TA_YAHOO_IDX_UNAVAILABLE_1","Local cache does not have a Yahoo! index"},
         {69,"TA_YAHOO_IDX_FAILED","No Info"},
         {70,"TA_LIBCURL_GLOBAL_INIT_FAILED","libCurl shared library missing?"},
         {71,"TA_LIBCURL_INIT_FAILED","libCurl shared library missing?"},
         {72,"TA_INSTRUMENT_ID_BAD","TA_Instrument not initialized."},
         {73,"TA_TRADE_LOG_NOT_INITIALIZED","TA_TradeLog corrupted or not initialized"},
         {74,"TA_BAD_TRADE_TYPE","No Info"},
         {75,"TA_BAD_START_DATE","No Info"},
         {76,"TA_BAD_END_DATE","No Info"},
         {77,"TA_INTERNET_SET_RX_TIMEOUT_FAILED","No Info"},
         {78,"TA_NO_TRADE_LOG","No Info"},
         {79,"TA_ENTRY_TRANSACTION_MISSING","No Info"},
         {80,"TA_INVALID_VALUE_ID","No Info"},
         {81,"TA_BAD_STARTING_CAPITAL","No Info"},
         {82,"TA_TRADELOG_ALREADY_ADDED","This TA_TradeLog is already added to this TA_PM."},
         {83,"TA_YAHOO_IDX_UNAVAILABLE_2","Possibly timeout of internet connection"},
         {84,"TA_YAHOO_IDX_UNAVAILABLE_3","Failed to find a Yahoo! index"},
         {85,"TA_NO_WEEKDAY_IN_DATE_RANGE","No Info"},
         {86,"TA_VALUE_NOT_APPLICABLE","This PM value is not applicable to these trades."},
         {87,"TA_DATA_GAP","Data source returned data with gaps"},
         {88,"TA_NOT_IMPLEMENTED","Feature not implemented"},
         {89,"TA_PM_REFERENCE_EXIST","Can not free a TA_TradeLog when added to a TA_PM"},
         {90,"TA_PRICE_BAR_CONTAINS_ZERO","A price of zero is invalid in a price bar"},
         {91,"TA_MISSING_CLOSE_PRICE_FIELD","Close must be provided with TA_REPLACE_ZERO_PRICE_BAR flag."},
         {92,"TA_UNSUPPORTED_REPLACE_ZERO_PRICE_BAR","TA_REPLACE_ZERO_PRICE_BAR flag is not supported for this data source."},
         {93,"TA_MISSING_INPUT_DIGITS","A digit was missing in one of the price bar field"},
         {94,"TA_DICT_TYPE_MISMATCH","Error with handling of dictionary"},
         {95,"TA_YAHOO_IDX_UNAVAILABLE_4","Failed to find a Yahoo! index"},
         {96,"TA_OBSOLETED_SYMBOL","This symbol is no longuer valid"},
         {97,"TA_BAD_QUERY","Query could not be executed or syntax error in query"},
         {98,"TA_UNSUPPORTED_DO_NOT_SPLIT_ADJUST","TA_DO_NOT_SPLIT_ADJUST flag is not supported by this data source"},
         {99,"TA_UNSUPPORTED_DO_NOT_VALUE_ADJUST","TA_DO_NOT_VALUE_ADJUST flag is not supported by this data source"},
         {100,"TA_MISSING_PRICE_FOR_ADJUSTMENT","At least one price field must be requested when doing price adjustment."},
         {101,"TA_INVALID_DATABASE_TYPE","location parameter does not refer to a supported database type."},
         {102,"TA_UNEXPECTED_SQL_TYPE","One of the field is not of the expected SQL type."},
         {103,"TA_UNEXPECTED_SQL_TYPE_FOR_OPEN","Open price field is not of the expected SQL type."},
         {104,"TA_UNEXPECTED_SQL_TYPE_FOR_HIGH","High price field is not of the expected SQL type."},
         {105,"TA_UNEXPECTED_SQL_TYPE_FOR_LOW","Low price field is not of the expected SQL type."},
         {106,"TA_UNEXPECTED_SQL_TYPE_FOR_CLOSE","Close price field is not of the expected SQL type."},
         {107,"TA_UNEXPECTED_SQL_TYPE_FOR_VOLUME","Volume field is not of the expected SQL type."},
         {108,"TA_UNEXPECTED_SQL_TYPE_FOR_OI","Open interest field is not of the expected SQL type."},
         {700,"TA_IP_NOSOCKETS","Sockets not supported"},
         {701,"TA_IP_BADHOST","Host not known"},
         {702,"TA_IP_BADSERVICE","Service or port not known"},
         {703,"TA_IP_BADPROTOCOL","Invalid protocol specified"},
         {704,"TA_IP_SOCKETERROR","Error creating socket"},
         {705,"TA_IP_CONNECTERROR","Error making connection"},
         {706,"TA_IP_BINDERROR","Error binding socket"},
         {707,"TA_IP_LISTENERROR","Error preparing to listen"},
         {708,"TA_IP_WRITE_ERROR","Error writing to socket"},
         {709,"TA_IP_READ_ERROR","Error reading from socket"},
         {710,"TA_IP_UNKNOWN_ERR","No Info"},
         {800,"TA_HTTP_NO_HEADER","HTTP header not found."},
         {801,"TA_HTTP_SC_301","Moved Permanently"},
         {802,"TA_HTTP_SC_302","Moved Temporarily"},
         {803,"TA_HTTP_SC_304","Not Modified"},
         {804,"TA_HTTP_SC_400","Bad Request"},
         {805,"TA_HTTP_SC_401","Unauthorized"},
         {806,"TA_HTTP_SC_403","Forbidden"},
         {807,"TA_HTTP_SC_404","Not Found"},
         {808,"TA_HTTP_SC_500","Internal Server Error"},
         {809,"TA_HTTP_SC_501","Not Implemented"},
         {810,"TA_HTTP_SC_502","Bad Gateway"},
         {811,"TA_HTTP_SC_503","Service Unavailable"},
         {812,"TA_HTTP_SC_UNKNOWN","Unknown error code."},
         {5000,"TA_INTERNAL_ERROR","Internal Error - Contact TA-Lib.org"},
         {0xFFFF,"TA_UNKNOWN_ERR","Unknown Error"}
};

#define NB_RET_CODE_INFO (sizeof(retCodeInfoTable)/sizeof(TA_InternalRetCodeInfo))

void TA_SetRetCodeInfo( TA_RetCode theRetCode, TA_RetCodeInfo *retCodeInfo )
{
   unsigned int i;
   
   /* Trap internal error code */
   if( (theRetCode >= 5000) && (theRetCode <= 5999) )
   {
      retCodeInfo->enumStr = "TA_INTERNAL_ERROR";
      retCodeInfo->infoStr = "Unexpected Internal Error - Contact TA-Lib.org";
      return;
   }
   
   /* Check among all the error code defined in ta_common.h */
   for( i=0; i < (NB_RET_CODE_INFO-1); i++ )
   {
      if( theRetCode == retCodeInfoTable[i].retCode )
      {
         /* Error code found. */
         retCodeInfo->enumStr = retCodeInfoTable[i].enumStr;
         retCodeInfo->infoStr = retCodeInfoTable[i].infoStr;
         return;
      }
   }

   /* Error code not found. */

   /* "TA_UNKNOWN_ERR" is ALWAYS the last entry in the table. */
   retCodeInfo->enumStr = retCodeInfoTable[i].enumStr;
   retCodeInfo->infoStr = retCodeInfoTable[i].infoStr;
}

/***************/
/* End of File */
/***************/

