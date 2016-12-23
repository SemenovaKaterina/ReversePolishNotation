#pragma once
#include "TStack.h"
#include "TVariable.h"

class TFormula
{
	TStack<int> *Num; //стек значений
public:
	TFormula();
	int Result(char*, TVariable*); //Решение ОПЗ
	bool IsNumber(char); //Это число?
	bool IsOperation(char); //Это операция?
	int Operation(char, int p2, int p1); //Выполнение операции
};
