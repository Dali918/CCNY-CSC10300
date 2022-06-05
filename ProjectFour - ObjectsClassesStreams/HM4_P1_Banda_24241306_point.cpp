#include "HM4_P1_Banda_24241306_point.h"
#include <sstream>

string Point::print() const
{
    ostringstream out;

    out << "x,y: "
        << "(" << getX() << "," << getY() << ")";

    return out.str();
}
ostream &operator<<(ostream &out, const Point &right) {
    out<<right.print();
    return out;
}
void Point::operator++()
{
    this->setX(this->getX() + 1);
    this->setY(this->getY() + 1);
}
void Point::operator++(int)
{
    this->setX(this->getX() + 1);
    this->setY(this->getY() + 1);
}
void Point::operator--()
{
    this->setX(this->getX() - 1);
    this->setY(this->getY() - 1);
}
void Point::operator--(int)
{
    this->setX(this->getX() - 1);
    this->setY(this->getY() - 1);
}