#pragma once
#include "TStack.h"
class TVariable
{
	TStack<char> *Var; //���� ����������
	TStack<int> *Num; //���� ��������
public:
	TVariable();
	void Get(char c, int n); //�������� ����� ����������
	int Search(char); //����� �������� ����������
};

