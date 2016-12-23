#include "stdafx.h"
#include "TPolish.h"

TPolish::TPolish()
{
	St = new TStack<char>;
}

char* TPolish::ConvertToPolish(char* s, char*res) //��������������� � ���
{
	unsigned int pos = 0;
	int r = 0;
	if (s[1] == '=')//���� � = ...
		pos = 2;
	unsigned int end = strlen(s);
	if (s[end - 1] == '=')//���� ... =
		end--;
	while (pos < end)
	{
		char ch = s[pos++];
		if ((ch == ' ') || (ch == '\t')) //���� ��� ������ ��� tab
			continue;
		if (IsNumber(ch)) //���� ��� �����
			res[r++] = ch; //���������� � ������ ����������
		else
		if (IsOperation(ch)) //���� ��� ��������
		{
			res[r++] = ' ';
			if ((ch == '-') && (s[pos - 2] == '(')) //���� ��� ������� �����
			{
				res[r++] = ch; //���������� � ������ ����������
				continue;
			}
			int pr = Priority(ch); //�������� � ���������
			if (St->IsEmpty()) //���� ���� ����
				St->Push(ch); //����� � ����
			else //� ����� ���-�� ����
			{
				if (Priority(St->Look()) < pr) //���� �� ������� ����� �������� �������� ����������
					St->Push(ch);
				else //�� ������� ����� �������� >= ����������
				{
					do
					{
						if (Priority(St->Look()) >= pr)
						{
							res[r++] = St->Pop(); //���������� � ������ ����������
							res[r++] = ' ';
							break;
						}
						res[r++] = St->Pop(); //���������� � ������ ����������
						res[r++] = ' ';
					} while (!St->IsEmpty()); //���� �� �������� ��� �������� �� ������� ����� ������� ���������
					St->Push(ch);
				}
			}
		}
		else if (ch == '(') //���� ��� ������������� ������, ����� � ����
			St->Push(ch);
		else if (ch == ')') //���� ��� ����������� ������
		{
			bool i = true;
			while (!St->IsEmpty()) //���� ���� �� ��������
			{
				if (St->Look() != '(') //���� �� ������� ����� �� ������������� ������
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
				return res; //�������� ������
			}
			St->Pop(); //�������� ����������� ������		
		}
		else //���� ��� �������� ���������
		{
			strcpy_s(res, 80, "");
			return res; //���������� ������ ������
		}
	}
	while (!St->IsEmpty())
	{
		if (St->Look() == '(') //���� �� ������� ����� ������������� ������
		{
			strcpy_s(res, 80, "unmatched brackets");
			return res; //�������� ������
		}
		res[r++] = ' ';
		res[r++] = St->Pop(); //���������� � ������ ����������
	}
	res[r++] = '\0';
	return res; //���������� ���
}

bool TPolish::IsNumber(char c) //��� �����?
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

bool TPolish::IsOperation(char c) //��� ��������?
{
	if ((c == '+') || (c == '-') || (c == '*') || (c == '/'))
		return true;
	return false;
}

int TPolish::Priority(char c) //��������� ��������
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
