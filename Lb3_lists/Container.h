#pragma once
class Container
{
public:
    virtual void push(double value) = 0; //to end
    virtual void unshift(double value) = 0; // to beginning
    virtual void remove(int index) = 0;
    virtual void insert(int index, double value) = 0;
    virtual void showlist() = 0;
    virtual int getsize() = 0;
    virtual void clear() = 0;
    virtual ~Container() {}
};

