// PrefixEvaluation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include "PrefixEval.h"

int main()
{
	PrefixEval prefixEval = PrefixEval();
	bool keepGoing = true;
	while (keepGoing)
	{
		char userInput;

		std::string strExp = "";

		std::cout << std::endl << "Enter prefix string to be evaluated: ";
		std::cin >> strExp;
		std::cout << std::endl << "the answer is : " << prefixEval.evaluatePrefix(strExp);

		std::cout << std::endl << std::endl << "evaluate another expression (y or n): ";
		std::cin >> userInput;
		if (tolower(userInput) != 'y')
			keepGoing = false;
	}
    

}

