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


//Token Class to hold tokenID, tokenInstance, and lineNumber
//the public functions will be to retrieve each variable
class Token
{
private:
	TokenID tokenID;
	string tokenInstance;
	int lineNumber;

public:
	//constructor
	Token(TokenID tokenID, string tokenInstance, int lineNumber);
	
	//destructor
	~Token();

	//get functions
	TokenID getTokenID();
	string getTokenInstance();
	int getLineNumber();

	//print function
	string printTokenInfo();		
};


//function to create a string to represent the tokenID enum
//this string will be used in the printTokenInfo() function in Token Class
string enumToString(TokenID token);


#endif















