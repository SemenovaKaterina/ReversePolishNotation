#include "stdafx.h"
#include "TPolish.h"

TPolish::TPolish()
{
	St = new TStack<char>;
}

char* TPolish::ConvertToPolish(char* s, char*res) //Конвертирование в ОПЗ
{
	unsigned int pos = 0;
	int r = 0;
	if (s[1] == '=')//Если а = ...
		pos = 2;
	unsigned int end = strlen(s);
	if (s[end - 1] == '=')//Если ... =
		end--;
	while (pos < end)
	{
		char ch = s[pos++];
		if ((ch == ' ') || (ch == '\t')) //Если это пробел или tab
			continue;
		if (IsNumber(ch)) //Если это число
			res[r++] = ch; //Записываем в строку результата
		else
		if (IsOperation(ch)) //Если это операция
		{
			res[r++] = ' ';
			if ((ch == '-') && (s[pos - 2] == '(')) //Если это унарный минус
			{
				res[r++] = ch; //Записываем в строку результата
				continue;
			}
			int pr = Priority(ch); //Получаем её приоритет
			if (St->IsEmpty()) //Если стек пуст
				St->Push(ch); //Кладём в стек
			else //В стеке что-то есть
			{
				if (Priority(St->Look()) < pr) //Если на вершине стека операция меньшего приоритета
					St->Push(ch);
				else //На вершине стека операция >= приоритета
				{
					do
					{
						if (Priority(St->Look()) >= pr)
						{
							res[r++] = St->Pop(); //Записываем в строку результата
							res[r++] = ' ';
							break;
						}
						res[r++] = St->Pop(); //Записываем в строку результата
						res[r++] = ' ';
					} while (!St->IsEmpty()); //Пока не опустеет или операция на вершине имеет меньший приоритет
					St->Push(ch);
				}
			}
		}
		else if (ch == '(') //Если это открывающаяся скобка, кладём в стек
			St->Push(ch);
		else if (ch == ')') //Если это закрывающая скобка
		{
			bool i = true;
			while (!St->IsEmpty()) //Пока стек не опустеет
			{
				if (St->Look() != '(') //Если на вершине стека не открывающаяся скобка
				{
					res[r++] = ' ';
					res[r++] = St->Pop();
				}
				else
				{
					i = false;
					break;
				}
			}
			if (i)
			{
				strcpy_s(res, 80, "unmatched brackets");
				return res; //Непарные скобки
			}
			St->Pop(); //Вынимаем открывающую скобку		
		}
		else //Если это неверное выражение
		{
			strcpy_s(res, 80, "");
			return res; //Возвращаем пустую строку
		}
	}
	while (!St->IsEmpty())
	{
		if (St->Look() == '(') //Если на вершине стека открывающаяся скобка
		{
			strcpy_s(res, 80, "unmatched brackets");
			return res; //Непарные скобки
		}
		res[r++] = ' ';
		res[r++] = St->Pop(); //Записываем в строку результата
	}
	res[r++] = '\0';
	return res; //Возвращаем ОПЗ
}

bool TPolish::IsNumber(char c) //Это число?
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

bool TPolish::IsOperation(char c) //Это операция?
{
	if ((c == '+') || (c == '-') || (c == '*') || (c == '/'))
		return true;
	return false;
}

int TPolish::Priority(char c) //Приоритет операции
{
	int Prt;
	switch (c)
	{
	case'*':
	case'/':Prt = 3; break;
	case'+':
	case'-':Prt = 2; break;
	case'(':Prt = 1; break;
	}
	return Prt;
}
