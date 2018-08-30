/**Evaluates prefix expressions of operands less than 10 
@file PrefixEval.h*/
#ifndef _PREFIX_EVAL
#define _PREFIX_EVAL

#include "pch.h"
#include <string>

class PrefixEval
{
private :
	const char operators[4] = { '+','-','*','/' };
	bool isOperator(char ch);

public:
	PrefixEval();
	int endPre(std::string strExp, int first);
	bool isPrefix(std::string strExp);
	float evaluatePrefix(std::string strExp);
	

	
};
#endif // !_PREFIx_EVAL
