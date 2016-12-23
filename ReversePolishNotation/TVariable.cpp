#include "stdafx.h"
#include "TVariable.h"

TVariable::TVariable()
{//������ �����
	Var = new TStack<char>;
	Num = new TStack<int>;
}

void TVariable::Get(char c, int n)
{//�������� ����� ����������
	Var->Push(c);
	Num->Push(n);
}

int TVariable::Search(char c) //����� �������� ����������
{
	int res = (int)c;
	if ((res > 47) && (res < 58)) //0...9
	{ //���� ��� �����
		res -= 48;
		return res;
	}
	int num = Var->Search(c); //���� ����� ����������
	res = Num->Get(num); //�������� �������� ����������
	return res;
}