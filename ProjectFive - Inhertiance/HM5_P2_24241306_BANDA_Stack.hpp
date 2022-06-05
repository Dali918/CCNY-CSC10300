#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
class Stack
{
public:
    //default constructor
    Stack() {}
    //constructor with input
    Stack(const T &newtop);
    //empty
    bool empty();
    //stack size
    int size();
    //stack top
    T &top();
    //insert at top
    void push(const T &newTop);
    //remove at top
    void pop();

private:
    string stackUnderflow = "exception: stack is empty!";
    vector<T> innerVector;
};
//FUNCTION DEFINTIONS

//Stack constructor
template <typename T>
Stack<T>::Stack(const T &newTop)
{
    this->push(newTop);
}
template <typename T>
//check if stack empty
bool Stack<T>::empty()
{
    return (this->size() == 0);
}
//return stack size
template <typename T>
int Stack<T>::size()
{
    return this->innerVector.size();
}
//return stack top if stack is not empty
template <typename T>
T &Stack<T>::top()
{

    if (this->empty())
        throw runtime_error(this->stackUnderflow);

    return this->innerVector.back();
}
//add new item to stack
template <typename T>
void Stack<T>::push(const T &newTop)
{
    this->innerVector.push_back(newTop);
}
//remove current top if stack is not empty
template <typename T>
void Stack<T>::pop()
{

    if (this->empty())
        throw runtime_error(this->stackUnderflow);

    this->innerVector.pop_back();
}

#endif