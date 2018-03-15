//removeWhiteSpaceAndNewLines.cpp
//
#include "removeWhiteSpaceAndNewLines.h"

using namespace std;

//function to remove white spaces ' ' and new lines '\n'
string removeWhiteSpaceAndNewLines(string inputString)
{
	string newString;
	int inputStringSize = inputString.length();
	int i = 0;
	//loop through inputString, adding each char to newString
	//if the char in the loop is ' ' or '\n' do not add to newString
	for(i; i < inputStringSize; i++)
	{
		if(inputString[i] != ' ' && != '\n')
		{
			newString += inputString[i];
		}
	}

	//return newString with all chars except ' ' and '\n'
	return newString;
}
