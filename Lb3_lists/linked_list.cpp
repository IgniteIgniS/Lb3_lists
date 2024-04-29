#include "linked_list.h"
#include <iostream>

linked_list::linked_list()
{
	size = 0;
	head = nullptr;
}

linked_list::~linked_list()
{
	clear();
}

void linked_list::unshift(double value)
{
	head = new Node(value, head);
	size++;
}

void linked_list::showlist()
{
	Node* current = head;
	while (current != nullptr)
	{
		std::cout << current->value << std::endl;
		current = current->pNext;
	}
}

void linked_list::push(double value)
{
	if (head == nullptr)
	{
		head = new Node(value);
	}
	else
	{
		Node* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(value);

	}
	size++;
}

void linked_list::insert(int index, double value)
{
	if (index < 0 || index > size) 
	{
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (index == 0)
	{
		unshift(value);
	}
	else
	{
		Node* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node* newNode = new Node(value, previous->pNext);
		previous->pNext = newNode;
		size++;
	}
}

void linked_list::remove(int index)
{
	if (index < 0 || index > size) {
		std::cout << "Invalid index" << std::endl;
		return;
	}
	if (index == 0)
	{
		Node* temp = head;
		head = head->pNext;
		delete temp;
		size--;
	}
	else
	{
		Node* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}

int linked_list::getsize()
{
	return this->size;
}

void linked_list::clear()
{
	while (size)
	{
		Node* temp = head;
		head = head->pNext;
		delete temp;
		size--;
	}
}

linked_list::linked_list(const linked_list& other)
{
	size = other.size;
	if (other.head == nullptr) 
	{
		head = nullptr;
	}
	else 
	{
		head = new Node(other.head->value);
		Node* current = head;
		Node* otherCurrent = other.head->pNext;
		while (otherCurrent != nullptr) 
		{
			current->pNext = new Node(otherCurrent->value);
			current = current->pNext;
			otherCurrent = otherCurrent->pNext;
		}
	}
}

double& linked_list::operator[](int index)
{
	int counter = 0;
	Node* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->value;
		}
		current = current->pNext;
		counter++;
	}
}

linked_list& linked_list::operator=(const linked_list& other)
{
	if (this != &other) // проверка на самоприсваивание
	{
		clear(); // очистка текущего списка

		size = other.size;
		if (other.head == nullptr)
		{
			head = nullptr;
		}
		else
		{
			head = new Node(other.head->value);
			Node* current = head;
			Node* otherCurrent = other.head->pNext;
			while (otherCurrent != nullptr)
			{
				current->pNext = new Node(otherCurrent->value);
				current = current->pNext;
				otherCurrent = otherCurrent->pNext;
			}
		}
	}
	return *this;
}


