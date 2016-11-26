#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>
#include <stack>

#pragma warning(disable: 4996) 
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
const int Max_Len = 256;

typedef stack<string> Stack;

void Print(fstream& Text);

int LoadFileToStek(Stack & MyStack, string name, string road);

void Purge(Stack & MyStack);

void LinePrint(void);

void ListofFiles(void);