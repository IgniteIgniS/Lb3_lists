#pragma once
#include "Container.h"

class doublelinked_list : public Container
{
	
public:
    doublelinked_list();
    ~doublelinked_list();

    void unshift(double value)override;
    void showlist()override;
    
    
    void push(double value)override; //to end
    void remove(int index)override;
    void insert(int index, double value)override;
    int getsize()override;
    void clear()override;

    doublelinked_list(const doublelinked_list& other);
    double& operator[](int index);
    doublelinked_list& operator=(const doublelinked_list& other);

private:
    class Node
    {
    public:
        double value;
        Node* pNext;
        Node* pPrev;
        Node(double value, Node* pNext = nullptr, Node* pPrev = nullptr)
        {
            this->value = value;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }
    };

    int size;
    Node* head;
    Node* tail;
};

