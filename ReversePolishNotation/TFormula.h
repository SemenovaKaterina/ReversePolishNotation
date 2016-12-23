#pragma once
#include "TStack.h"
#include "TVariable.h"

class TFormula
{
	TStack<int> *Num; //���� ��������
public:
	TFormula();
	int Result(char*, TVariable*); //������� ���
	bool IsNumber(char); //��� �����?
	bool IsOperation(char); //��� ��������?
	int Operation(char, int p2, int p1); //���������� ��������
};
