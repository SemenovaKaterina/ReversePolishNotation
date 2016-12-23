#pragma once
#include "TList.h"

using namespace std;

template <typename T>
class TStack
{
	TList<T> memory;
public:
	TStack();
	~TStack();
	void Clr();
	bool IsEmpty(); //�������� �� �������
	void Push(const T x); //��������� �������
	T Pop(); //������� �������
	T Look(); // �������� �������� ������� ��������
	int Search(T); //����� ������� � ������� ��� �������
	T Get(int n); //�������� n-�� �������
};


template<typename T>
TStack<T>::TStack()
{}

template<typename T>
TStack<T>::~TStack()
{}

template <typename T>
bool TStack<T>::IsEmpty()
{
	return memory.IsEmpty();
}

template<typename T>
void TStack<T>::Push(const T x) //��������� �������
{
	memory.InsertHead(new Item<T>(x, NULL));
}

template<typename T>
T TStack<T>::Pop() //������� �������
{
	return memory.ClrHead();
}

template<typename T>
T TStack<T>::Look() //������� �������
{
	return memory.ViewFirst();
}

template <typename T>
void TStack<T>::Clr()
{
	while (memory.IsEmpty())
		memory.ClrHead();
}

template<typename T>
int TStack<T>::Search(T x)
{//����� ������� � ������� ��� �������
	Item<T>* k = memory.first; int i = 0;
	while (k)
	{
		if (k->Data == x)
			break;
		i++;
		k = k->next;
	}
	return i;
}

template<typename T>
T TStack<T>::Get(int n)
{//�������� n-�� �������
	Item<T>* k = memory.first; int i = 0;
	while (k)
	{
		if (i == n)
			return k->Data;
		i++;
		k = k->next;
	}
	return NULL;
}
