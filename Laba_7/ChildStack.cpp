#include "ChildStack.h"



ChildStack::ChildStack() : stack()
{
}

void ChildStack::mytop()
{
	this->top();
	this->pop();
}

void ChildStack::reverseStack(ChildStack & _stack)
{
	string item;
	ChildStack tmpStack;

	while (_stack.empty() == false)
	{
		item = _stack.top();
		_stack.pop();
		tmpStack.push(item);
	}
	_stack = tmpStack;
}

ChildStack::~ChildStack()
{
}
