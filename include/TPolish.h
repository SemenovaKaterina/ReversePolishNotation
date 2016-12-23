#pragma once
#include "TStack.h"
#include <iostream>
#include <string>
using namespace std;

class TPolish
{
	TStack<char> *St; //Стек операций
public:
	TPolish(); 
	char* ConvertToPolish(char*, char*); //Конвертирование в ОПЗ
	bool IsNumber(char); //Это переменная?
	bool IsOperation(char); //Это операция?
	int Priority(char); //Приоритет операции
};

