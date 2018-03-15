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
		case identifier: return "identifier";
		case keywordStart: return "keyword: Start";
		case keywordStop: return "keyword: Stop";
		case keywordIter: return "keyword: Iter";
		case keywordVoid: return "keyword: Void";
		case keywordVar: return "keyword: Var";
		case keywordReturn: return "keyword: Return";
		case keywordRead: return "keyword: Read";
		case keywordPrint: return "keyword: Print";
		case keywordProgram: return "keyword: Program";
		case keywordIff: return "keyword: Iff";
		case keywordThen: return "keyword: Then";
		case keywordLet: return "keyword: Let";
		case operatorEqual: return "operator: Equal";
		case operatorLess: return "operator: Less Than";
		case operatorGreater: return "operator: Greater Than";
		case operatorColon: return "operator: Colon";
		case operatorPlus: return "operator: Addition";
		case operatorMinus: return "operator: Subtraction";
		case operatorMultiply: return "operator: Multiplication";
		case operatorDivide: return "operator: Division";
		case operatorModulus: return "operator: Modulus";
		case delimPeriod: return "delimiter: Period";
		case delimLeftParenthesis: return "delimiter: Left Parenthesis";
		case delimRightParenthesis: return "delimiter: Right Parenthesis";
		case delimComma: return "delimiter: Comma";
		case delimLeftBrace: return "delimiter: Left Brace";
		case delimRightBrace: return "delimiter: Right Brace";
		case delimSemicolon: return "delimiter: Semi-Colon";
		case delimLeftBracket: return "delimiter: Left Bracket";
		case delimRightBracket: return "delimiter: Right Bracket";
		case integer: return "integer";
		case comment: return "comment";
		case endOfFile: return "end of file";
		default: return "****ERROR IN ENUMTOSTRING() FUNCTION! TOKENID NOT FOUND! ****";		
	}
}





































