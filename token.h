//token.h file
#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>
#include <string>

using namespace std;

//token enum for identifying available tokens used for the scanner
enum TokenID
{
	identifier, // max 8 chars, begin with lowercase letter, followed by letters/digits
	keywordStart, // start
	keywordStop, // stop
	keywordIter, // iter
	keywordVoid, // void
	keywordVar, // var
	keywordReturn, // return
	keywordRead, // read
	keywordPrint, // print
	keywordProgram, // program
	keywordIff, // iff
	keywordThen, // then
	keywordLet,  // let
	operatorEqual, // =
	operatorLess, // <
	operatorGreater, // >
	operatorColon, // :
	operatorPlus, // +
	operatorMinus, // -
	operatorMultiply, // *
	operatorDivide, // /
	operatorModulus, // %
	delimPeriod, // .
	delimLeftParenthesis, // (
	delimRightParenthesis, // )
	delimComma, // ,
	delimLeftBrace, // {
	delimRightBrace, // }
	delimSemicolon, // ;
	delimLeftBracket, // [
	delimRightBracket, // ]
	integer, //max 8 chars, any seq of decimal digits
	comment, // & used for comments
	endOfFile //eof
	
};




#endif
