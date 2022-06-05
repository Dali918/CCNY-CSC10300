#include "HM4_P1_Banda_24241306_line.h"
//default constructor
Line::Line()
{
    this->slope = 0;
    this->length = 0;
    this->p1 = new Point(0, 0);
    this->p2 = new Point(0, 0);
}
//overloaded constructors
Line::Line(Point pone, Point ptwo)
{
    this->p1 = new Point{pone};
    this->p2 = new Point{ptwo};
    this->slope = slopeCalculator();
    this->length = lengthCalculator();
}
Line::Line(double xOne, double yOne, double xTwo, double yTwo)
{
    this->p1 = new Point{xOne, yOne};
    this->p2 = new Point{xTwo, yTwo};
    this->slope = slopeCalculator();
    this->length = lengthCalculator();
}
//destructor
Line::~Line()
{
    this->slope = 0;
    this->slope = 0;
    delete this->p1;
    delete this->p2;
}
//copy constructor
Line::Line(const Line &lineInput)
{
    this->p1 = new Point(lineInput.getPointOne());
    this->p2 = new Point(lineInput.getPointTwo());
    this->slope = lineInput.slope;
    this->length = lineInput.length;
}
//overloaded assignment operator
Line &Line::operator=(const Line &lineInput)
{
    //check self assignment
    if (this != &lineInput)
    {
        //deep copy
        delete this->p1;
        delete this->p2;
        p1 = new Point(lineInput.getPointOne());
        p2 = new Point(lineInput.getPointTwo());
        this->slope = lineInput.slope;
        this->length = lineInput.length;
    }

    return *this;
}
//calculate slope
double Line::slopeCalculator() const
{
    assert((*p1).getX() - (*p2).getX() != 0);
    double denom = ((*p1) - (*p2)).getX();
    double numer = ((*p1) - (*p2)).getY();
    return (numer / denom);
}
//calculate length
double Line::lengthCalculator() const
{
    double xdelta = ((*p1) - (*p2)).getY();
    double ydelta = ((*p1) - (*p2)).getX();
    return sqrt(pow(xdelta, 2) + pow(ydelta, 2));
}

//update slope and length
void Line::update()
{
    this->setSlope(slopeCalculator());
    this->setLength(lengthCalculator());
}
//set points and udate line
void Line::setPointOne(Point pone)
{
    *p1 = pone;
    update();
}

void Line::setPointTwo(Point ptwo)
{
    *p2 = ptwo;
    update();
}
void Line::setPoints(Point pone, Point ptwo)
{
    *p1 = pone;
    *p2 = ptwo;
    update();
}
void Line::setPoints(double xOne, double yOne, double xTwo, double yTwo)
{
    *p1 = Point{xOne, yOne};
    *p2 = Point{xTwo, yTwo};
    update();
}