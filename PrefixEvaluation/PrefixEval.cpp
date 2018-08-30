/**@file PrefixEval.cpp*/
#include "pch.h"
#include "PrefixEval.h"

PrefixEval::PrefixEval()
{
}//end default constructor

/**Finds the end of a prefix expression if one exists
@pre The substring of strExp from the index first through the end
of the string contains no blanks
@post returns the index of the last character in the prefix expression that begins
at index first of strEXp, or -1 if no such prefix expression exists*/
int PrefixEval::endPre(std::string& strExp, int first)
{
	int last = strExp.length() - 1;
	if (first < 0 || first > last)
		return -1;
	char ch = strExp[first];
	if (isdigit(ch))
		return first; //index of last ch in a simple prefix expression
	else if (isOperator(ch))
	{
		//find the end of the first expression
		int endPos = (strExp, first + 1); //point x
		//if the end of the first prefix condition was found, find the end
		//of the second prefix position
		if (endPos > -1)
		{
			
			return endPre(strExp, endPos+1); //point y
		}
		else
			return -1;
	}
	else 
		return -1;
}//end endPre


/**sees whether an expressoin is a prefix expression
@pre strExp contains a string with no blank characters
@post returns true if the expression is in prefix form, otherwise false*/
bool PrefixEval::isPrefix(std::string& strExp)
{
	char lastChar = endPre(strExp, 0);
	return ((lastChar >= 0) && (lastChar == strExp.length() - 1));

}//end isPrefix
/**returns the value of the give prefix expression
@pre strExp is a string containing a valid prefix expression(operands must be less than 10)
with no blanks
@post strExp is evaluated as a prefix expression
@return the float value of the evalution of the prefix expression*/
float PrefixEval::evaluatePrefix(std::string strExp)
{
	int strLength = strExp.length();
	if (strLength == 1)
		return stoi(strExp);
	else
	{
		char op = strExp[0]; //strExp begins with an operator

		//find the end of the first prefix expression- will be the first operand
		int endFirst = endPre(strExp, 1);

		//recursively evaluate this first prefix expression
		float operand1 = evaluatePrefix(strExp.substr(1, endFirst));

		//recursively evaluate the second prefix expression - will be second operand
		int endSecond = strLength - endFirst + 1;
		float operand2 = evaluatePrefix(strExp.substr(endFirst + 1, endSecond));

		//evaluate the prifix expression
		switch (op)
		{
		case '+':
			return operand1 + operand2;
			break;
		case'-':
			return operand1 + operand2;
		case'*':
			return operand1 * operand2;
			break;
		case'/':
			return operand1 / operand2;
			break;
		}

	}

}//end evaluatePrefix

bool PrefixEval::isOperator(char& ch)
{
	int size = sizeof(operators) / sizeof(operators[0]);
	for (int i = 0; i < size;i++)
	{
		if (ch == operators[i])
			return true;
	}
	return false;
}