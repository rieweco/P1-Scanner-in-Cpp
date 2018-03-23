//scanner.cpp file
//
#include "scanner.h"
#include "removeWhiteSpaceAndNewLines.h"
#include <string>
#include <stdio.h>

using namespace std;




string table_row_values = {"BOF","identifier", "integer", "<",">",":","+","-","*","/","%",".","(",")",",","{","}",";","[","]",
			 "EOF"};

int table_rows = {0,1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,
			1019};

int FSA_TABLE[3][20] = {
			{0,1,2,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,
			1019},
			{1000,1,1,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,1000,
			1000},
			{1001,1001,2,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,1001,
			1001}
			};


Scanner::Scanner() = default;
Scanner::~Scanner() = default;

Token *Scanner::getToken(string &file, int index, int lineNumber)
{
	int currentState = 0;
	 
} 


