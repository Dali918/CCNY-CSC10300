#ifndef ARRAY_OUT_OF_RANGE
#define ARRAY_OUT_OF_RANGE
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

class ArrayOutOfRange : public out_of_range
{
protected:
    //protected members, only accessible in subclasses 
    int illegalIndex, size;

public:
    //constructor
    explicit ArrayOutOfRange(const string &message, const int index, const int size) : out_of_range{message},
                                                                                       illegalIndex{index},
                                                                                       size{size}
    {
    }
    //overloaded what function
    const char *what() const noexcept
    {
        ostringstream out;
        //get exception message
        out << out_of_range::what();
        //complete exception message
        string message = out.str() + " (illegal Index: " + to_string(this->illegalIndex) + ", array size: " + to_string(this->size) + ")";
        return message.c_str();
    }
};

#endif