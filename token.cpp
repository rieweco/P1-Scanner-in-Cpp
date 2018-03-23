//token.cpp file
//
#include <token.h>
#include "removeWhiteSpaceAndNewLines.h"

using namespace std;

//Token Class functions
Token::Token(TokenID id, string instance, int line)
{
	tokenID = id;
	tokenInstance = instance;
	lineNumber = line;
}

//compiler will generate the destructor
Token::~Token() = default;

//get functions
TokenID Token::getTokenID()
{
	return tokenID;
}

string Token::getTokenInstance()
{
	return tokenInstance;
}

int Token::getLineNumber()
{
	return lineNumber;
}

//printTokenInfo function
string Token::printTokenInfo()
{
	string output;
	output = "TokenID: " + enumToString(getTokenID()) + " TokenInstance: " + getTokenInstance() + " Line#: " + getLineNumber();
	
	return output;
}

//enumToString function
string enumToString(TokenID token)
{
	switch token
	{
		case identifier: return "IDtk";
		case keywordStart: return "keywordtk: Start";
		case keywordStop: return "keywordtk: Stop";
		case keywordIter: return "keywordtk: Iter";
		case keywordVoid: return "keywordtk: Void";
		case keywordVar: return "keywordtk: Var";
		case keywordReturn: return "keywordtk: Return";
		case keywordRead: return "keywordtk: Read";
		case keywordPrint: return "keywordtk: Print";
		case keywordProgram: return "keywordtk: Program";
		case keywordIff: return "keywordtk: Iff";
		case keywordThen: return "keywordtk: Then";
		case keywordLet: return "keywordtk: Let";
		case operatorEqual: return "operatortk: Equal";
		case operatorLess: return "operatortk: Less Than";
		case operatorGreater: return "operatortk: Greater Than";
		case operatorColon: return "operatortk: Colon";
		case operatorPlus: return "operatortk: Addition";
		case operatorMinus: return "operatortk: Subtraction";
		case operatorMultiply: return "operatortk: Multiplication";
		case operatorDivide: return "operatortk: Division";
		case operatorModulus: return "operatortk: Modulus";
		case delimPeriod: return "delimitertk: Period";
		case delimLeftParenthesis: return "delimitertk: Left Parenthesis";
		case delimRightParenthesis: return "delimitertk: Right Parenthesis";
		case delimComma: return "delimitertk: Comma";
		case delimLeftBrace: return "delimitertk: Left Brace";
		case delimRightBrace: return "delimitertk: Right Brace";
		case delimSemicolon: return "delimitertk: Semi-Colon";
		case delimLeftBracket: return "delimitertk: Left Bracket";
		case delimRightBracket: return "delimitertk: Right Bracket";
		case integer: return "integertk";
		case comment: return "commenttk";
		case endOfFile: return "EOFtk";
		default: return "****ERROR IN ENUMTOSTRING() FUNCTION! TOKENID NOT FOUND! ****";		
	}
}

int enumToInt(TokenID token)
{
	switch token
	{
		case identifier: return 1000;
		case integer: return 1001;
		case endOfFile: return 
	}
}



































