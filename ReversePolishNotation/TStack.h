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
	bool IsEmpty(); //контроль на полноту
	void Push(const T x); //поместить элемент
	T Pop(); //извлечь элемент
	T Look(); // получить значение первого элемента
	int Search(T); //найти элемент и вернуть его позицию
	T Get(int n); //получить n-ый элемент
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
void TStack<T>::Push(const T x) //поместить элемент
{
	memory.InsertHead(new Item<T>(x, NULL));
}

template<typename T>
T TStack<T>::Pop() //извлечь элемент
{
	return memory.ClrHead();
}

template<typename T>
T TStack<T>::Look() //извлечь элемент
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
{//найти элемент и вернуть его позицию
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
{//получить n-ый элемент
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
