#include "List.h"
#include <iostream>

using namespace std;


template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}


template<typename T>
size_t List<T>::getSize() 
{
	return this->size;
}


template<typename T>
T& List<T>::operator[](size_t index) 
{
	size_t counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index)
		{
			return current->data;
		}
		current = current->ptrNext;
		counter++;
	}
}


template<typename T>
void List<T>::pushFront(T data)
{
	head = new Node<T>(data, head);
	size++;
}


template<typename T>
void List<T>::pushBack(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->ptrNext != nullptr)
		{
			current = current->ptrNext;
		}
		current->ptrNext = new Node<T>(data);
	}
	this->size++;
}


template<typename T>
void List<T>::popFront()
{
	Node<T>* temp = head;

	head = head->ptrNext;

	delete temp;

	size--;
}


template<typename T>
void List<T>::insert(T data, size_t index)
{
	if (index == 0)
	{
		pushFront(data);
	} 
	else
	{
		Node<T>* previous = this->head;
		for (size_t i = 0; i < index - 1; i++)
		{
			previous = previous->ptrNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->ptrNext);
		previous->ptrNext = newNode;
		size++;
	}
}


template<typename T>
void List<T>::earase(size_t index)
{
	if (index == 0)
	{
		popFront();
	}
	else 
	{
		Node<T>* previous = this->head;
		for (size_t i = 0; i < index - 1; i++)
		{
			previous = previous->ptrNext;
		}
		Node<T>* toEarase = previous->ptrNext;

		previous->ptrNext = toEarase->ptrNext;

		delete toEarase;

		size--;
	}
	
}


template<typename T>
long List<T>::lFind(T data)
{
	if (head == nullptr)
	{
		return -1;
	}
	else
	{
		Node<T>* current = this->head;
		long counter = 0;
		while (current != nullptr)
		{
			counter++;
			if (current->data == data)
			{
				return counter;
			}
			current = current->ptrNext;
		}
		return -1;
	}
}