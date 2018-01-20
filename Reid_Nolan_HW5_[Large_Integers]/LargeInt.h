#pragma once
#include <iostream>
#include <string>

class LargeInt
{
private:
	std::string mInt;

public:
	LargeInt();
	~LargeInt();	
	
	//setter
	void setIntValue(std::string userInput);

	//getter
	std::string getIntValue() const;

	//char to int conversion
	static int charToInt(const char tempChar);
};