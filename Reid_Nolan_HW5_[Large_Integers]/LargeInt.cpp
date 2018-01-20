#include "stdafx.h"
#include "LargeInt.h"
#include <string>

LargeInt::LargeInt()
{
	mInt = " ";
}

LargeInt::~LargeInt()
{
}

//setter
void LargeInt::setIntValue(std::string userInput)
{
	mInt = userInput;
}

//getter
std::string LargeInt::getIntValue() const
{
	return mInt;
}

//convert char to int
int LargeInt::charToInt(const char tempChar)
{
	switch (tempChar)
	{
	case '0':
		return 0;
		break;
	case '1':
		return 1;
		break;
	case '2':
		return 2;
		break;
	case '3':
		return 3;
		break;
	case '4':
		return 4;
		break;
	case '5':
		return 5;
		break;
	case '6':
		return 6;
		break;
	case '7':
		return 7;
		break;
	case '8':
		return 8;
		break;
	case '9':
		return 9;
		break;
	default:
		return 0;
	}
}