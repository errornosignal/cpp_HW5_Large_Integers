#include "stdafx.h"
#include "Menu.h"
#include <iostream>

using namespace std;

Menu::Menu()
{
}

Menu::~Menu()
{
}

//display program header
void Menu::displayProgHeader()
{
	cout << "Reid_Nolan_HW5_[Large_Integers]" << endl;
	cout << "C++ Application to return the sum of two large integers." << endl;
	cout << "Enter '0' at anytime to quit." << endl;
}

//display input prompt 1
void Menu::displayInputPrompt1()
{
	cout << "Enter 1st positive integer: ";
}

//display input prompt 1
void Menu::displayInputPrompt2()
{
	cout << "Enter 2nd positive integer: ";
}

void Menu::exitIfZero(string userInput)
{
	//program exit condition
	if (userInput == "0")
	{
		cout << "exiting program...";
		exit(1);
	}
	else
	{
		//do nothing
	}
}

void Menu::displayInvalidInput()
{
	//display error message for invalid input
	cout << "Error! Invalid input." << endl;
}

void Menu::displayNoInput()
{
	//display error message for no input
	cout << "Error! No input." << endl;
}