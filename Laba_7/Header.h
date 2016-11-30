#pragma once
#include <sstream>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <iterator>
#include <windows.h>
#include <string>
#include <stack>

#pragma warning(disable: 4996) 
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

typedef stack<string> Stack;

void LoadFileToStek(Stack & MyStack, string name, string road);

void Purge(Stack & MyStack);

void LinePrint(void);

void ListofFiles(void);

void ReverseStack(Stack & _stack);