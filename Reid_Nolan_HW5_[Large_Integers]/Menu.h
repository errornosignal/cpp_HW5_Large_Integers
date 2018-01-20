#pragma once
#include <iostream>
#include <string>

class Menu
{

private:

public:
	Menu();
	~Menu();

	static void displayProgHeader();
	static void displayInputPrompt1();
	static void displayInputPrompt2();
	static void exitIfZero(std::string userInput);
	static void displayInvalidInput();
	static void displayNoInput();
};