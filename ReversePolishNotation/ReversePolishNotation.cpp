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
	char Num[80]; //�������� ���������
	setlocale(LC_CTYPE, "Rus");
	TVariable* Variable; //������� ����������????????
	Variable = new TVariable();
	cout << "������� ��������� (0 - �����):\n";
	cin >> Num;
	while (Num[0] != '0')
	{
		//������������ ��������� � ���
		TPolish* Convertor;
		Convertor = new TPolish();
		char Polish[80]; //������ � ���
		for (int i = 0; i < 80; i++)
			Polish[i] = ' ';
		Convertor->ConvertToPolish(Num, Polish);
		if (Polish == "") //��������� ����������� ���������
			cout << "��������� ����������� ���������";
		else if (Polish == "�������� ������") //�������� ������
			cout << "�������� ������";
		else //������� ���������
		{
			cout << "���: ";
			cout << Polish << "\n"; //����� ���
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

