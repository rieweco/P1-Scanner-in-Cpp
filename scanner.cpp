//scanner.cpp file
//
#include "scanner.h"
#include "removeWhiteSpaceAndNewLines.h"
#include <string>
#include <stdio.h>

using namespace std;




string table_row_values = {"BOF","identifier", "integer", "<",">","=",":","+","-","*","/","%",".","(",")",",","{","}",";",
			"[","]","EOF", "error", "comment"};

int table_rows = {0,1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,
			1019, 1020, -1, 2000};

int FSA_TABLE[3][24] = {
			{0,1,2,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,
			1019,1020,-1, 2000},
			{1000,1,1,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
			1000,1000,-1,1000},
			{1001,1001,2,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,
			1001,1001,-1,1001}
			};

int findTableCol(char next)
{
	switch next
	{
		case 'a': return 1;
			break;
		case 'A': return 1;
			break;
		case 'b': return 1;
			break;
		case 'B': return 1;
			break;
		case 'c': return 1;
			break;
		case 'C': return 1;
			break;
		case 'd': return 1;
			break;
		case 'D': return 1;
			break;
		case 'e': return 1;
			break;
		case 'E': return 1;
			break;
		case 'f': return 1;
			break;
		case 'F': return 1;
			break;
		case 'g': return 1;
			break;
		case 'G': return 1;
			break;
		case 'h': return 1;
			break;
		case 'H': return 1;
			break;
		case 'i': return 1;
			break;
		case 'I': return 1;
			break;
		case 'j': return 1;
			break;
		case 'J': return 1;
			break;
		case 'k': return 1;
			break;
		case 'K': return 1;
			break;
		case 'l': return 1;
			break;
		case 'L': return 1;
			break;
		case 'm': return 1;
			break;
		case 'M': return 1;
			break;
		case 'n': return 1;
			break;
		case 'N': return 1;
			break;
		case 'o': return 1;
			break;
		case 'O': return 1;
			break;
		case 'p': return 1;
			break;
		case 'P': return 1;
			break;
		case 'q': return 1;
			break;
		case 'Q': return 1;
			break;
		case 'r': return 1;
			break;
		case 'R': return 1;
			break;
		case 's': return 1;
			break;
		case 'S': return 1;
			break;
		case 't': return 1;
			break;
		case 'T': return 1;
			break;
		case 'u': return 1;
			break;
		case 'U': return 1;
			break;
		case 'v': return 1;
			break;
		case 'V': return 1;
			break;
		case 'w': return 1;
			break;
		case 'W': return 1;
			break;
		case 'x': return 1;
			break;
		case 'X': return 1;
			break;
		case 'y': return 1;
			break;
		case 'Y': return 1;
			break;
		case 'z': return 1;
			break;
		case 'Z': return 1;
			break;
		case '1': return 2;
			break;
		case '2': return 2;
			break;
		case '3': return 2;
			break;
		case '4': return 2;
			break;
		case '5': return 2;
			break;
		case '6': return 2;
			break;
		case '7': return 2;
			break;
		case '8': return 2;
			break;
		case '9': return 2;
			break;
		case '0': return 2;
			break;
		case '<': return 3;
			break;
		case '>': return 4;
			break;
		case '=': return 5;
			break;
		case ';': return 6;
			break;
		case '+': return 7;
			break;
		case '-': return 8;
			break;
		case '*': return 9;
			break;
		case '/': return 10;
			break;
		case '%': return 11;
			break;
		case '.': return 12;
			break;
		case '(': return 13;
			break;
		case ')': return 14;
			break;
		case ',': return 15;
			break;
		case '{': return 16;
			break;
		case '}': return 17;
			break;
		case ';': return 18;
			break;
		case '[': return 19;
			break;
		case ']': return 20;
			break;
		case '&': return 23;
			break;
		default: return 22;
	}
}


//function to get tokenID from string
TokenID getTokenIDFromString(string s)
{
	if(s == "start") {return keywordStart;}
	else if(s == "stop") {return keywordStop;}
	else if(s == "iter") {return keywordIter;}
	else if(s == "void") {return keywordVoid;}
	else if(s == "var") {return keywordVar;}
	else if(s == "return") {return keywordReturn;}
	else if(s == "read") {return keywordRead;}
	else if(s == "print") {return keywordPrint;}
	else if(s == "program") {return keywordProgram;}
	else if(s == "iff") {return keywordIff;}
	else if(s == "then") {return keywordThen;}
	else if(s == "let") {return keywordLet;}
	else return identifier;
}




//scanner class

Scanner::Scanner() = default;
Scanner::~Scanner() = default;

Token *Scanner::getToken(string &file, int index, int lineNumber)
{
	int currentState = 0;
	string readChars;
	
	//set newToken to endOfFile token before getting next char in case of EOF
	TokenID newToken = endOfFile;
	
	//set flag for reading multiple chars
	bool isToken = true;
	//set flag for being in comment section ie. reading '&'
	bool inComment = false;
	
	while(isToken)
	{
		char next = file[index];
		
		if(next && !inComment)
		{
			if(next != '&')
			{

				int column = findTableCol(next);
			
				currentState = FSA_TABLE[currentState][column];
			}
			else if(next == '&')
			{
				inComment = true;
				break;	
			}
			else
			{	
				cout << "Scanner Error: invalid character: " + next + " at line: " + lineNumber + ".\n";
			}
		}
		else if(next && inComment)
		{
			index++;
		}
		else
		{
		//eof has been reached	
		currentState = 1020;
		}

		//check for end of token
		if(currentState >= 0)
		{
			//keep reading, adding the read char to the string
			if(currentState < 1020 && currentState > 99)
			{
				readChars += next;
				index++;		
			}
			//advance but dont save char, we are in comment section
			else if(currentState == 2000)
			{
				index++;
			}
			//end has been reached, set isToken flag to exit while loop
			else
			{
				isToken = false;
			}
		}
		else
		{
			cout << "Scanner Error: invalid token: " + readChars + " at line: " + lineNumber + ".\n";
		}
	}


	//check token with identifier bank
	if(currentState == 1001)
	{
		newToken = integer;	
	}
	
	if(currentState == 1000)
	{
		newToken = getTokenIDFromString(readChars);
	}
	

	//set up new token for return
	Token *token = new Token(newToken, readChars, lineNumber);

	return token;
} 




























