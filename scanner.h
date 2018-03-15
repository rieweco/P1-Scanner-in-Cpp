//scanner.h file
//
#ifndef SCANNER_H
#define SCANNER_H

#include <stdio.h>
#include <string>
#include "token.h"


using namespace std;


class Scanner
{
	//constructor
	Scanner();
		
	//destructor
	~Scanner();

	//function to read line in file and scan each character one at a time
	//this will compare the character read to the tokenID enum
	//function will return a Token Class of the scanned character
	Token readNextCharacter(string fileString, int line, int charIndex);
};



#endif
