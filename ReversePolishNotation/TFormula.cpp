#include "stdafx.h"
#include "TFormula.h"

TFormula::TFormula()
{
	Num = new TStack<int>;
}

int TFormula::Result(char* s, TVariable* v) //Решаем ОПЗ типа: _-d_с_-а_в_+_*_-
{
	unsigned int pos = 0;
	int n = 0;
	int res = 0;
	s[strlen(s)] = ' ';
	while (pos < strlen(s))
	{
		char ch = s[pos++];
		if (ch == ' ') //Если это пробел
		{
			if (n != 0) //Если число закончилось
			{
				if (res == -1)//Если число отрицательное
					n = n * res;
				Num->Push(n); //Кладём число в стек
			}
			n = 0; res = 0;
			continue;
		}
		if (IsNumber(ch)) //Если это число
		{
			if ((((int)s[pos - 2] > 47) && ((int)s[pos - 2] < 58)) || (((int)s[pos]>47) && ((int)s[pos] < 58)))
			{//Если предыдущая или последующая цифра
				n = n * 10 + ((int)ch - 48);//Получаем многозначное число
			}
			else
			{
				int c = v->Search(ch);//Ищем значение в таблице переменных
				if (res == -1)//Если переменная отрицательная
					c = c*(res);
				res = 0;
				Num->Push(c);//Кладём значение в стек
			}
		}
		else if (IsOperation(ch)) //Если это операция
		{
			if ((ch == '-') && (IsNumber(s[pos]))) //Если это унарный минус				
				res = -1;
			else
				Num->Push(Operation(ch, Num->Pop(), Num->Pop())); //Кладём результат операции в стек
		}
		else
			break;
	}
	res = Num->Pop(); //Результат на вершине стека
	return res;
}

bool TFormula::IsNumber(char c) //Это число?
{
	int chis = (int)c;
	if ((chis > 47) && (chis < 58))//0...9
		return true;
	if ((chis > 64) && (chis < 91))//A...Z
		return true;
	if ((chis > 96) && (chis < 123))//a...z
		return true;
	return false;
}

bool TFormula::IsOperation(char c) //Это операция?
{
	if ((c == '+') || (c == '-') || (c == '*') || (c == '/'))
		return true;
	return false;
}

int TFormula::Operation(char op, int p2, int p1) //Выполнение операции
{
	int res;
	switch (op)
	{
	case '*':res = p1 * p2; break;
	case '/':{if (p1 != 0)
	{
				 res = p2 / p1; break;
	}
			 else
			 {
				 cout << "нельзя делить на 0!!\n";
				 res = 0; break;
			 } }
	case '-':res = p2 - p1; break;
	case '+':res = p1 + p2; break;
	}
	return res;
}
