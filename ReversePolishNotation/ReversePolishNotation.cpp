// ReversePolishNotation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TStack.h"
#include "TFormula.h"
#include "TPolish.h"
#include <iostream>
#include <string>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	char Num[80]; //Получаем выражение
	setlocale(LC_CTYPE, "Rus");
	TVariable* Variable; //Таблица переменных????????
	Variable = new TVariable();
	cout << "Введите выражение (0 - выход):\n";
	cin >> Num;
	while (Num[0] != '0')
	{
		//Конвертируем выражение в ОПЗ
		TPolish* Convertor;
		Convertor = new TPolish();
		char Polish[80]; //Строка в ОПЗ
		for (int i = 0; i < 80; i++)
			Polish[i] = ' ';
		Convertor->ConvertToPolish(Num, Polish);
		if (Polish == "") //Результат конвертации неудачный
			cout << "результат конвертации неудачный";
		else if (Polish == "непарные скобки") //Непарные скобки
			cout << "непарные скобки";
		else //Выводим результат
		{
			cout << "ОПЗ: ";
			cout << Polish << "\n"; //вывод ОПЗ
			TFormula* Calculator;
			Calculator = new TFormula();
			int res = Calculator->Result(Polish, Variable);
			if (Num[1] == '=')
				Variable->Get(Num[0], res);
			cout << res << "\n";
		}
		cin >> Num;
	}
	return 0;
}

