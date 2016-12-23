#include "stdafx.h"
#include "TVariable.h"

TVariable::TVariable()
{//Создаём стеки
	Var = new TStack<char>;
	Num = new TStack<int>;
}

void TVariable::Get(char c, int n)
{//Добавить новую переменную
	Var->Push(c);
	Num->Push(n);
}

int TVariable::Search(char c) //Найти значение переменной
{
	int res = (int)c;
	if ((res > 47) && (res < 58)) //0...9
	{ //Если это число
		res -= 48;
		return res;
	}
	int num = Var->Search(c); //Ищем номер переменной
	res = Num->Get(num); //Получаем значение переменной
	return res;
}