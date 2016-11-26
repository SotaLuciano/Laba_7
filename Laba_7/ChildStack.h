#pragma once
#include "Header.h"
class ChildStack : private Stack
{
public:
	ChildStack();
	void mytop();
	void reverseStack(ChildStack & _stack);
	~ChildStack();
};

