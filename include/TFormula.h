#pragma once
#include "TStack.h"
class TFormula
{
	TStack<int> *Num; //стек значений
public:
	TFormula();
	int Result(char*); //Решение ОПЗ
	bool IsNumber(char); //Это число?
	bool IsOperation(char); //Это операция?
	int Operation(char, int p2, int p1); //Выполнение операции
};
