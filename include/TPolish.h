#pragma once
#include "TStack.h"
#include <iostream>
#include <string>
using namespace std;

class TPolish
{
	TStack<char> *St; //���� ��������
public:
	TPolish(); 
	char* ConvertToPolish(char*, char*); //��������������� � ���
	bool IsNumber(char); //��� ����������?
	bool IsOperation(char); //��� ��������?
	int Priority(char); //��������� ��������
};

