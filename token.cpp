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
				break;
		case keywordStart: return "keywordtk: Start";
				break;
		case keywordStop: return "keywordtk: Stop";
				break;
		case keywordIter: return "keywordtk: Iter";
				break;
		case keywordVoid: return "keywordtk: Void";
				break;
		case keywordVar: return "keywordtk: Var";
				break;
		case keywordReturn: return "keywordtk: Return";
				break;
		case keywordRead: return "keywordtk: Read";
				break;
		case keywordPrint: return "keywordtk: Print";
				break;
		case keywordProgram: return "keywordtk: Program";
				break;
		case keywordIff: return "keywordtk: Iff";
				break;
		case keywordThen: return "keywordtk: Then";
				break;
		case keywordLet: return "keywordtk: Let";
				break;
		case operatorEqual: return "operatortk: Equal";
				break;
		case operatorLess: return "operatortk: Less Than";
				break;
		case operatorGreater: return "operatortk: Greater Than";
				break;
		case operatorColon: return "operatortk: Colon";
				break;
		case operatorPlus: return "operatortk: Addition";
				break;
		case operatorMinus: return "operatortk: Subtraction";
				break;
		case operatorMultiply: return "operatortk: Multiplication";
				break;
		case operatorDivide: return "operatortk: Division";
				break;
		case operatorModulus: return "operatortk: Modulus";
				break;
		case delimPeriod: return "delimitertk: Period";
				break;
		case delimLeftParenthesis: return "delimitertk: Left Parenthesis";
				break;
		case delimRightParenthesis: return "delimitertk: Right Parenthesis";
				break;
		case delimComma: return "delimitertk: Comma";
				break;
		case delimLeftBrace: return "delimitertk: Left Brace";
				break;
		case delimRightBrace: return "delimitertk: Right Brace";
				break;
		case delimSemicolon: return "delimitertk: Semi-Colon";
				break;
		case delimLeftBracket: return "delimitertk: Left Bracket";
				break;
		case delimRightBracket: return "delimitertk: Right Bracket";
				break;
		case integer: return "integertk";
				break;
		case comment: return "commenttk";
				break;
		case endOfFile: return "EOFtk";
				break;
		default: return "****ERROR IN ENUMTOSTRING() FUNCTION! TOKENID NOT FOUND! ****";		
	}
}




































