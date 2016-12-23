#pragma once
#include "TList.h"

using namespace std;

template <typename T>
class TStack
{
	TList<T> memory;
public:
	TStack();//конструктор по умолчанию
	~TStack();
	void Clr();
	bool IsEmpty();//контроль на полноту
	void Push(const T x);//поместить элемент
	T Pop();//извлечь элемент
	T Look(); // get the value of the first element 
};


template<typename T>
TStack<T>::TStack() /*: memory(TList<T>())*/
{}

template<typename T>
TStack<T>::~TStack()
{

}



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

