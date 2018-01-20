// Reid_Nolan_HW5_[Large_Integers].cpp : Defines the entry point for the console application.
//C++ Application to return the sum of two large integers.

#include "stdafx.h"
#include "Menu.h"
#include "LargeInt.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
 
using namespace std;

int main()
{
	//display program header
	Menu::displayProgHeader();
	cout << endl;

	//loop until user opts to quit
	while (true)
	{		
		//declare and initialize const variables
		const string mNumberString = "1234567890";
		const int mNumOfRows = 3;
		
		//declare and initialize variables
		string userInput = "0";		
		string s1 = "";
		string s2 = "";
		string s3 = "";
		stringstream ss;
		int intLength1 = 0;
		int intLength2 = 0;
		int outputWidth = 0;
		int numOfCols = 0;		
		char tempChar = ' ';	

		//initialize class objects and set to "0"
		LargeInt userInt1, userInt2, cpuInt;
		userInt1.setIntValue(userInput);
		userInt2.setIntValue(userInput);
		cpuInt.setIntValue(userInput);		

		//loop through input prompt twice to get both values from user
		for (int i = 0; i < 2; i++)
		{			
			//set loop condition
			bool inputGood = false;
			while (!inputGood)
			{
				if (i == 0)
				{
					//prompt for 1st input
					Menu::displayInputPrompt1();
					//read in from console
					getline(cin, userInput);
				}
				else if (i == 1)
				{
					//prompt for 2nd input
					Menu::displayInputPrompt2();
					//read in from console
					getline(cin, userInput);
				}
				else
				{
					//do nothing
				}
				
				//Allow only numeric characters in input
				size_t found = userInput.find_first_not_of(mNumberString);
				if (found != std::string::npos)
				{
					//display error message for invalid input
					Menu::displayInvalidInput();
					cout << endl;
				}
				else if (userInput.length() == 0)
				{
					//display error message for no input
					Menu::displayNoInput();
					cout << endl;
				}
				else if (cin.fail())
				{
					//handle input failure
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');;
				}
				else
				{
					//set loop condition variable to true
					inputGood = true;
				}
			}

			//terminate if input is "0"
			Menu::exitIfZero(userInput);
			
			//reverse string to drop in array backwards
			reverse(userInput.begin(), userInput.end());
			if (i == 0)
			{
				//set value of 1st int
				userInt1.setIntValue(userInput);
				//set string length to variable for signed/unsigned mismatch
				intLength1 = userInput.length();
			}
			else if (i == 1)
			{
				//set value of 2nd int
				userInt2.setIntValue(userInput);
				//set string length to variable for signed/unsigned mismatch
				intLength2 = userInput.length();
			}
			else
			{
				//do nothing
			}
		}

		//set length for array(whichever is larger)
		if (intLength1 < intLength2)
		{
			numOfCols = intLength2 + 1;
		}
		else if (intLength1 >= intLength2)
		{
			numOfCols = intLength1 + 1;
		}
		else
		{
			//do nothing
		}
		
		//create 2-d dynamic array [numOfRows x numOfCols]
		int **largeIntArray = new int*[mNumOfRows];
		for (int i = 0; i < mNumOfRows; i++)
		{
			largeIntArray[i] = new int[numOfCols];
		}

		//initialize array elements to zero
		for (int i = 0; i < mNumOfRows; i++)
		{
			for (int j = 0; j < numOfCols; j++)
			{
				largeIntArray[i][j] = 0;
			}
		}
		
		//copy 1st string into array
		for (int i = 0; i < intLength1; i++)
		{				
			tempChar = userInt1.getIntValue()[i];
			largeIntArray[0][numOfCols - i - 1] = LargeInt::charToInt(tempChar);			
		}

		//copy 2nd string into array
		for (int i = 0; i < intLength2; i++)
		{
			tempChar = userInt2.getIntValue()[i];
			largeIntArray[1][numOfCols - i - 1] = LargeInt::charToInt(tempChar);
		}	
		
		//add 2-d array elements (column-by-column)
		for (int i = numOfCols - 1; i >= 0; i--)
		{
			largeIntArray[2][i] = largeIntArray[0][i] + largeIntArray[1][i];			
		}

		//carry over tens place for addition
		for (int i = numOfCols - 1; i >= 0; i--)
		{
			if (largeIntArray[2][i] > 9)
			{
				largeIntArray[2][i - 1] = largeIntArray[2][i] / 10 % 10 + largeIntArray[2][i - 1];
				largeIntArray[2][i] = largeIntArray[2][i] % 10;
			}
			else
			{
				//do nothing
			}
		}
		
		//insert elements of largeIntArray[2] into stringstream		
		for (int i = 0; i < numOfCols; i++)
		{
			ss << largeIntArray[2][i];
		}
		
		//set stringstream value to object
		cpuInt.setIntValue(ss.str());

		//copy LargeInt object values into strings
		s1 = userInt1.getIntValue();
		s2 = userInt2.getIntValue();			
		s3 = cpuInt.getIntValue();

		//reverse strings back to original
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());

		//remove leading zeroes from strings
		s1.erase(0, s1.find_first_not_of('0'));
		s2.erase(0, s2.find_first_not_of('0'));
		s3.erase(0, s3.find_first_not_of('0'));
		
		//set padding width for output		
		if (s1.length() > s2.length())
		{
			if (s1.length() > s3.length())
			{
				outputWidth = s1.length();
			}
			else
			{
				outputWidth = s3.length();
			}
		}
		else 
		{
			outputWidth = s2.length();
		}		
		
		//output string values
		cout << endl;
		cout << left << "Integer 1: " << setw(outputWidth) << right << s1 << endl;
		cout << left << "Integer 2: " << setw(outputWidth) << right << s2 << endl;
		cout << left << "      Sum: " << setw(outputWidth) << right << s3 << endl << endl;

		//deallocate dynamic memory
		for (int i = 0; i < mNumOfRows; i++)
		{
			delete[] largeIntArray[i];
		}
		delete[] largeIntArray;
	}
	return 0;
}