#ifndef LINE_H
#define LINE_H
#include "HM4_P1_Banda_24241306_point.h"
#include "cmath"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

class Line
{

public:
    //Define a null-constructor that initializes numeric variables with zero and
    //allocate dynamic memory for points and initialize them to [0,0] as well.
    Line();
    //Overload a constructor that allocates memory for points, initilize them
    //with given arguments, and calculate the slope and length
    Line(Point pone, Point ptwo);
    Line(double xOne, double yOne, double xTwo, double yTwo);
    //Implement destructor, copy constructor and copy assignment operator.
    ~Line();
    Line(const Line &lineInput);
    Line &operator=(const Line &lineInput);
    //Define setter and getter functions.
    void setSlope(double slopeInput) { this->slope = slopeInput; }
    double getSlope() const { return this->slope; }
    void setLength(double lengthInput) { this->length = lengthInput; }
    double getLength() const { return this->length; }
    //with Point argument
    void setPointOne(Point pone);
    Point getPointOne() const { return (*p1); }
    void setPointTwo(Point ptwo);
    Point getPointTwo() const { return (*p2); }
    //with two point arguments
    void setPoints(Point pone, Point ptwo);
    //with four double arguments
    void setPoints(double xOne, double yOne, double xTwo, double yTwo);
    //update line, when a new point(s) is added
    void update();
    //slope calculator
    double slopeCalculator() const;
    //length calculator
    double lengthCalculator() const;
    //(f) Create a function called ”parallel” that takes too Line objects, returns
    //true when given lines are parallel and returns false otherwise.
    friend bool parallel(const Line &lone, const Line &ltwo);
    //(g) Overload the less than (<) and greater than (>) and equality (==) operators (compare the length).
    friend bool operator<(const Line &lone, const Line &ltwo) { return lone.length < ltwo.length; }
    friend bool operator>(const Line &lone, const Line &ltwo) { return lone.length > ltwo.length; }
    friend bool operator==(const Line &lone, const Line &ltwo) { return lone.length == ltwo.length; }
    //added <= , >= , !=
    friend bool operator!=(const Line &lone, const Line &ltwo) { return !(lone == ltwo); }
    friend bool operator>=(const Line &lone, const Line &ltwo) { return !(lone < ltwo); }
    friend bool operator<=(const Line &lone, const Line &ltwo) { return !(lone > ltwo); }
    // Extend the functionality of cin and cout for this class.
    friend istream &operator>>(istream &in, Line &line);
    friend ostream &operator<<(ostream &out, const Line &line);

private:
    //Define private data members p1 and p2 as pointer to Point objects
    //(the one we had in lectures), slope and length as double variables.
    Point *p1;
    Point *p2;
    double slope, length;
};

#endif
