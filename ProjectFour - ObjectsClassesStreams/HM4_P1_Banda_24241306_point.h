#ifndef POINT_H
#define POINT_H
using namespace std;
#include <iostream>
#include <utility>

class Point
{
    double x, y;

public:
    Point() : x(0), y(0) {}
    Point(double inputx, double inputy) : x(inputx), y(inputy) {}
    double getX() const { return x; };
    double getY() const { return y; };
    void setX(double input) { x = input; };
    void setY(double input) { y = input; };
    void setCoord(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    string print() const;

    //prefix
    void operator++();
    void operator--();
    //post fix
    void operator++(int);
    void operator--(int);

    //point and point +
    friend Point operator+(const Point &left, const Point &right) { return Point(left.getX() + right.getX(), left.getY() + right.getY()); }
    //point and point -
    friend Point operator-(const Point &left, const Point &right) { return Point(left.getX() - right.getX(), left.getY() - right.getY()); }
    //pair and point +
    friend Point operator+(const Point &left, const pair<double, double> &right) { return Point(left.getX() + right.first, left.getY() + right.second); }
    friend Point operator+(const pair<double, double> &left, const Point &right) { return Point(right.getX() + left.first, right.getY() + left.second); }
    //pair and point -
    friend Point operator-(const Point &left, const pair<double, double> &right) { return Point(left.getX() - right.first, left.getY() - right.second); }
    friend Point operator-(const pair<double, double> &left, const Point &right) { return Point(left.first - right.getX(), left.second - right.getY()); }

    //point and point *
    friend Point operator*(const Point &left, const Point &right) { return Point(left.getX() * right.getX(), left.getY() * right.getY()); }
    //pair and point *
    friend Point operator*(const Point &left, const pair<double, double> &right) { return Point(left.getX() - right.first, left.getY() * right.second); }
    friend Point operator*(const pair<double, double> &left, const Point &right) { return Point(left.first - right.getX(), left.second * right.getY()); }
    //point and point
    friend Point operator/(const Point &left, const Point &right) { return Point(left.getX() / right.getX(), left.getY() / right.getY()); }
    //pair and point /
    friend Point operator/(const Point &left, const pair<double, double> &right) { return Point(left.getX() / right.first, left.getY() / right.second); }
    friend Point operator/(const pair<double, double> &left, const Point &right) { return Point(left.first / right.getX(), left.second / right.getY()); }

    //operator!= can be implemented as !(operator==)
    //operator> can be implemented as operator< with the order of the parameters flipped
    //operator>= can be implemented as !(operator<)
    //operator<= can be implemented as !(operator>)
    //point and point ==
    friend bool operator==(const Point &left, const Point &right) { return left.getX() == right.getX() && left.getY() == right.getY(); }
    //point and point !=
    friend bool operator!=(const Point &left, const Point &right) { return !(left == right); }
    //point and point >
    friend bool operator>(const Point &left, const Point &right) { return left.getX() > right.getX() && left.getY() > right.getY(); }
    //point and point<
    friend bool operator<(const Point &left, const Point &right) { return right > left; }
    //point and point<=
    friend bool operator<=(const Point &left, const Point &right) { return !(left > right); }
    //point and point>=
    friend bool operator>=(const Point &left, const Point &right) { return !(left < right); }
    //pair and point ==
    friend bool operator==(const Point &left, const pair<double, double> &right) { return left.getX() == right.first && left.getY() + right.second; }
    friend bool operator==(const pair<double, double> &left, const Point &right) { return left.first == right.getX() && left.second == right.getY(); }
    //pair and point !=
    friend bool operator!=(const Point &left, const pair<double, double> &right) { return !(left == right); }
    friend bool operator!=(pair<double, double> &left, Point &right) { return !(left == right); }
    //pair and point >
    friend bool operator>(const Point &left, const pair<double, double> &right) { return left.getX() > right.first && left.getY() > right.second; }
    friend bool operator>(const pair<double, double> &left, const Point &right) { return left.first > right.getX() && left.second > right.getY(); }
    //pair and point <
    friend bool operator<(const Point &left, const pair<double, double> &right) { return right > left; }
    friend bool operator<(const pair<double, double> &left, const Point &right) { return right > left; }
    //pair and point <=
    friend bool operator<=(const Point &left, const pair<double, double> &right) { return !(left > right); }
    friend bool operator<=(const pair<double, double> &left, const Point &right) { return !(left > right); }
    //pair and point >=
    friend bool operator>=(const Point &left, const pair<double, double> &right) { return !(left < right); }
    friend bool operator>=(const pair<double, double> &left, const Point &right) { return !(left < right); }
    friend ostream &operator<<(ostream &out, const Point &right);
};

#endif