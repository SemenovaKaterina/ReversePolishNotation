#pragma once
#include "TStack.h"
class TVariable
{
	TStack<char> *Var; //стек переменных
	TStack<int> *Num; //стек значений
public:
	TVariable();
	void Get(char c, int n); //ƒобавить новую переменную
	int Search(char); //Ќайти значение переменной
};

