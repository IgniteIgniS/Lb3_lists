#include "doublelinked_list.h"
#include <iostream>
doublelinked_list::doublelinked_list()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

doublelinked_list::~doublelinked_list()
{
	clear();
}

void doublelinked_list::unshift(double value)
{
    Node* newNode = new Node(value);
    if (head == nullptr) 
    {
        tail = head = newNode;
    }
    else 
    {
        newNode->pNext = head;
        head->pPrev = newNode;
        head = newNode;
    }
	size++;
}

void doublelinked_list::showlist()
{
	Node* current = head;
	while (current != nullptr)
	{
		std::cout << current->value << std::endl;
		current = current->pNext;
	}
}

void doublelinked_list::push(double value)
{
    Node* newNode = new Node(value);
    if (head == nullptr) 
    {
        head = tail = newNode;
    }
    else 
    {
        tail->pNext = newNode;
        newNode->pPrev = tail;
        tail = newNode;
    }
    size++;
}

void doublelinked_list::remove(int index)
{
    if (index < 0 || index >= size) 
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    if (head == nullptr)
    {
        std::cout << "head nullptr" << std::endl;
        return;
    }
    else 
    {
        Node* current;
        if (index < size / 2) 
        {
            current = head;
            for (int i = 0; i < index; i++) 
            {
                current = current->pNext;
            }
        }
        else 
        {
            current = tail;
            for (int i = size - 1; i > index; i--) 
            {
                current = current->pPrev;
            }
        }

        if (current->pNext != nullptr) 
        {
            current->pNext->pPrev = current->pPrev;
        }
        else 
        {
            tail = current->pPrev;
        }

        if (current->pPrev != nullptr) 
        {
            current->pPrev->pNext = current->pNext;
        }
        else 
        {
            head = current->pNext;
        }

        delete current;
        size--;
    }
   
}

void doublelinked_list::insert(int index, double value)
{
    if (index < 0 || index > size) {
        std::cout << "Invalid index" << std::endl;
        return;
    }

    Node* newNode = new Node(value);
    if (index == 0) {
        unshift(value);
    }
    else if (index == size) {
        push(value);
    }
    else {
        Node* current;
        if (index < size / 2) {
            current = head;
            for (int i = 0; i < index; i++) {
                current = current->pNext;
            }
        }
        else {
            current = tail;
            for (int i = size - 1; i > index; i--) {
                current = current->pPrev;
            }
        }
        newNode->pNext = current;
        newNode->pPrev = current->pPrev;
        current->pPrev->pNext = newNode;
        current->pPrev = newNode;
        size++;
    }
}

int doublelinked_list::getsize()
{
	return this->size;
}

void doublelinked_list::clear()
{
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->pNext;
        delete temp;
    }
    tail = nullptr;
    size = 0;
}

doublelinked_list::doublelinked_list(const doublelinked_list& other)
{
    head = nullptr;
    tail = nullptr;
    size = 0;
    Node* temp = other.head;
    while (temp != nullptr) 
    {
        push(temp->value);
        temp = temp->pNext;
    }
}

double& doublelinked_list::operator[](int index)
{
    if (index < 0 || index >= size) {
        std::cout << "Invalid index" << std::endl;
        exit(1);
    }

    Node* current;
    if (index < size / 2) {
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->pNext;
        }
    } else {
        current = tail;
        for (int i = size - 1; i > index; i--) {
            current = current->pPrev;
        }
    }

    return current->value;
}

doublelinked_list& doublelinked_list::operator=(const doublelinked_list& other)
{
    if (this != &other) 
    {
        clear();
        Node* temp = other.head;
        while (temp != nullptr) 
        {
            push(temp->value);
            temp = temp->pNext;
        }
    }
    return *this;
}
