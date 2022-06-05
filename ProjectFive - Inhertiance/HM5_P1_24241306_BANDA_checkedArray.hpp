
#ifndef CHECKED_HPP
#define CHECKED_HPP #include <exception>
#include <iostream>
#include <cassert>
#include <sstream>
#include <stdexcept>
#include "HM5_P1_24241306_BANDA_ArrayOutOfRange.hpp"
using namespace std;
template <typename T>
class CheckedArray
{
private:
    int size;
    T *array;

public:
    //default constructor
    CheckedArray(int size);
    //copy constructor
    CheckedArray(CheckedArray<T> &original);
    //destructor
    ~CheckedArray();
    //overloaded access operator
    T &operator[](int index);
    //copy assignment operator
    T &operator=(CheckedArray<T> &original);
    //get size function
    int getSize() const { return this->size; }
    //Array out of range class
    class ArrayOutOfRangeError
    {
    private:
        //error message member
        string errorMessage;

    public:
        //constructor
        ArrayOutOfRangeError(const string message) : errorMessage{message}
        {
        }
        //what function
        const string what() const noexcept
        {
            return this->errorMessage;
        }
    };
};
template <typename T>
//default constructor
CheckedArray<T>::CheckedArray(int size)
{
    this->size = size;
    this->array = new T[size];
}
template <typename T>
//copy constructor
CheckedArray<T>::CheckedArray(CheckedArray<T> &original)
{
    this->size = original.getSize();
    array = new T[this->size];
    for (int i = 0; i < this->size; i++)
    {
        this->array[i] = original.array[i];
    }
}
//assignment operator
template <typename T>
T &CheckedArray<T>::operator=(CheckedArray<T> &original)
{
    if (this != &original)
    {
        delete[] this->array;
        this->size = original.getSize();
        this->array = new T[this->size];
        for (int i = 0; i < size; i++)
        {
            this->array[i] = original.array[i];
        }
    }
    return *this;
}
template <typename T>
CheckedArray<T>::~CheckedArray()
{
    //cout << "destructor called" << endl;
    delete[] this->array;
}
template <typename T>
T &CheckedArray<T>::operator[](int index)
{
    //Throw Exceptions
    if (index<0 || index> size)
    {

        throw ArrayOutOfRangeError("ArrayOutOfRangeError: Accessed Invalid Index!");
        //throw ArrayOutOfRange("Invalid Index", index, this->size);
        //throw out_of_range("out_of_range: Accessed Invalid Index! ");
    }

    //return object at index
    return array[index];
}

#endif