#pragma once
#include "Container.h"

class linked_list : public Container
{
public:
    linked_list();
    ~linked_list();

    void unshift(double value)override;
    void showlist()override;
    void push(double value)override;
    void insert(int index, double value)override;
    void remove(int index)override;
    int getsize()override;
    void clear()override;

    linked_list(const linked_list &other);
    double& operator[](int index);
    linked_list& operator=(const linked_list& other);

private:
    class Node
    {
    public:
        double value;
        Node* pNext;
        Node(double value, Node* pNext = nullptr)
        {
            this->value = value;
            this->pNext = pNext;
        }
    };

    int size;
    Node* head;
};

