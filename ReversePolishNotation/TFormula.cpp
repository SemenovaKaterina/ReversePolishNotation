#include "stdafx.h"
#include "TFormula.h"

TFormula::TFormula()
{
	Num = new TStack<int>;
}

int TFormula::Result(char* s, TVariable* v) //������ ��� ����: _-d_�_-�_�_+_*_-
{
	unsigned int pos = 0;
	int n = 0;
	int res = 0;
	s[strlen(s)] = ' ';
	while (pos < strlen(s))
	{
		char ch = s[pos++];
		if (ch == ' ') //���� ��� ������
		{
			if (n != 0) //���� ����� �����������
			{
				if (res == -1)//���� ����� �������������
					n = n * res;
				Num->Push(n); //����� ����� � ����
			}
			n = 0; res = 0;
			continue;
		}
		if (IsNumber(ch)) //���� ��� �����
		{
			if ((((int)s[pos - 2] > 47) && ((int)s[pos - 2] < 58)) || (((int)s[pos]>47) && ((int)s[pos] < 58)))
			{//���� ���������� ��� ����������� �����
				n = n * 10 + ((int)ch - 48);//�������� ������������ �����
			}
			else
			{
				int c = v->Search(ch);//���� �������� � ������� ����������
				if (res == -1)//���� ���������� �������������
					c = c*(res);
				res = 0;
				Num->Push(c);//����� �������� � ����
			}
		}
		else if (IsOperation(ch)) //���� ��� ��������
		{
			if ((ch == '-') && (IsNumber(s[pos]))) //���� ��� ������� �����				
				res = -1;
			else
				Num->Push(Operation(ch, Num->Pop(), Num->Pop())); //����� ��������� �������� � ����
		}
		else
			break;
	}
	res = Num->Pop(); //��������� �� ������� �����
	return res;
}

bool TFormula::IsNumber(char c) //��� �����?
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

bool TFormula::IsOperation(char c) //��� ��������?
{
	if ((c == '+') || (c == '-') || (c == '*') || (c == '/'))
		return true;
	return false;
}

int TFormula::Operation(char op, int p2, int p1) //���������� ��������
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
				 cout << "������ ������ �� 0!!\n";
				 res = 0; break;
			 } }
	case '-':res = p2 - p1; break;
	case '+':res = p1 + p2; break;
	}
	return res;
}
