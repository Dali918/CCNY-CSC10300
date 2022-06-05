 #include <iostream>
#include <iomanip>
#include "HM4_P1_Banda_24241306_line.h"
//see non-class function definitions after main
void readFromFile(string file, vector<Line> &Lines);
bool parallel(const Line &lone, const Line &ltwo);
//testing helper functions
double calcSlope(Point a, Point b);
double calcSlope(double a, double b, double c, double d);
double calcLength(Point a, Point b);
double calcLength(double a, double b, double c, double d);

int main()
{
    string title;
    srand(777);
    cout << fixed << setprecision(3);
    double x, y;
    vector<Point> points;
    //Test Default Constructor
    {
        Line line;
        //test default constructor
        title = "Testing Default Constructor";
        cout << setfill('*') << setw(10 + title.length()) << title << setfill('*') << setw(10) << "" << endl;
        cout << setfill(' ');
        Point zero(0, 0);
        cout << "Expecting: P1: (0,-0) | P2: (0,0) | slope: 0 | length: 0 " << endl;
        assert(line.getPointOne() == zero && line.getPointTwo() == zero);
        cout << "Passed default constructor test" << endl;
        cout << left << setw(11) << "Actual: " << line << endl;
        cout << endl;
    }
    //test setter and getter
    {
        Point pone, ptwo;
        Line line;
        title = "Testing setter and getter";
        cout << setfill('*') << setw(10 + title.length()) << title << setfill('*') << setw(10) << "" << endl;
        cout << setfill(' ');
        //setPoints(double,double,double,double)
        cout << "----Testing setPoints(double,double,double,double) --> setPoints(100, 2.5, -8, -4)" << endl;
        line.setPoints(100, 2.5, -8, -4);
        assert(line.getPointOne().getX() == 100.0 && line.getPointTwo().getX() == -8.0);
        assert(line.getPointOne().getY() == 2.50 && line.getPointTwo().getY() == -4.0);
        cout << "Passed setPoints(100, 2.5, -8, -4)" << endl;
        cout << "Expecting: P1: (100,2.5)| P2: (-8,-4) | slope: 0.060 | length: 108.195" << endl;
        cout << left << setw(11) << "Actual: " << line << endl;
        cout << endl;
        //setPoints(Point,Point)
        cout << "----Testing setPoints(Point,Point) --> (-5,2.5), (1,3)" << endl;
        line.setPoints(Point{-5, 2.5}, Point{1, 3});
        pone.setCoord(-5, 2.5);
        ptwo.setCoord(1, 3);
        assert(line.getPointOne() == pone && line.getPointTwo() == ptwo);
        cout << "Passed setPoints(Point,Point) --> (-5,2.5), (1,3)" << endl;
        cout << "Expecting: P1: (-5,2.5)| P2: (1,3) | slope: 0.083 length: 6.021" << endl;
        cout << left << setw(11) << "Actual: " << line << endl;
        cout << endl;
        //setSlope(double)
        cout << "----Testing setSlope(double) --> set slope of the previous line to -5.567" << endl;
        line.setSlope(-5.567);
        assert(line.getSlope() == -5.567);
        cout << "Passed setSlope(-5.567) " << endl;
        cout << "Expecting: P1: (-5,2.5)| P2: (1,3) | slope: -5.567 | length: 6.021" << endl;
        cout << left << setw(11) << "Actual: " << line << endl;
        cout << endl;
        //setLength(double)
        cout << "----Testing setLength(double) --> set length of the previous line to 105.880" << endl;
        line.setLength(105.88);
        assert(line.getLength() == 105.88);
        cout << "Passed setLength(105.88)" << endl;
        cout << "Expecting: P1: (-5,2.5)| P2: (1,3) | slope: -5.567 | length: 105.880 " << endl;
        cout << left << setw(11) << "Actual: " << line << endl;
        cout << endl;
    }

    //Test Non - Default Constructors
    {
        //test copy constructor
        title = "Testing Copy Constructor and Assignment Operator";
        cout << setfill('*') << setw(10 + title.length()) << title << setfill('*') << setw(10) << "" << endl;
        cout << setfill(' ');
        //setPoints(double,double,double,double)
        Line line;
        cout << "----Testing Copy Constructor" << endl;
        line.setPoints(29.6, 20.5, -15, -14.8);
        cout << left << setw(14) << "Initial line: " << line << endl;
        cout << "Creating new line with copy constructor and initial line as argument" << endl;
        Line newLine(line);
        assert(line.getPointOne() == newLine.getPointOne() && line.getPointTwo() == newLine.getPointTwo());
        cout << "Passed copy constructor test: Line(line)" << endl;
        cout << "Expecting:" << endl;
        cout << "Initial line: P1: (29.6,20.5)| P2: (-15,-14.8) | slope: 0.791 | length: 56.879" << endl;
        cout << "New line:     P1: (29.6,20.5)| P2: (-15,-14.8) | slope: 0.791 | length: 56.879" << endl;
        cout << "Actual:" << endl;
        cout << left << setw(14) << "Initial line: " << line << endl;
        cout << left << setw(14) << "New line: " << newLine << endl;
        cout << endl;
    }
    {
        //test assignment operator
        Line line, newLine;
        cout << "----Testing Assignment Operator" << endl;
        line.setPoints(-15.81, -20.5, 0.56, 2.88);
        newLine.setPoints(0.612, -3, 5, 0);
        cout << "Initial lines:" << endl;
        cout << left << setw(10) << "first: " << line << endl;
        cout << left << setw(10) << "second: " << newLine << endl;
        cout << "Setting second = first using assignment operator" << endl;
        newLine = line;
        assert(line.getPointOne() == newLine.getPointOne() && line.getPointTwo() == newLine.getPointTwo());
        cout << "Passed assignment operator test: Line = Line" << endl;
        cout << "Expecting:" << endl;
        cout << "Initial line: P1: (-15.81, -20.5)| P2: ( 0.56, 2.88) | slope: 1.428 | length: 28.541" << endl;
        cout << "New line:     P1: (-15.81, -20.5)| P2: ( 0.56, 2.88) | slope: 1.428 | length: 28.541" << endl;
        cout << "Actual:" << endl;
        cout << left << setw(10) << "first: " << line << endl;
        cout << left << setw(10) << "second: " << newLine << endl;
        cout << endl;
    }

    //Test Parallel Function
    {
        title = "Testing Parallel function";
        cout << setfill('*') << setw(10 + title.length()) << title << setfill('*') << setw(10) << "" << endl;
        cout << setfill(' ');
        Line first, second;
        cout << "----Test bench lines have the same slope -->asserting parallel == TRUE" << endl;
        cout << "Initial lines:" << endl;
        //make lines
        first.setPoints(1, 1, 2, 2);
        second.setPoints(-4, -4, 8, 8);
        cout << left << setw(10) << "first: " << first << endl;
        cout << left << setw(10) << "second: " << second << endl;
        //determine if parallel, expecting true
        assert(parallel(first, second) == true);
        cout << "Passed first parallel test " << endl;
        //make lines
        first.setPoints(-2, 14, 1, -5.5);
        second.setPoints(0, 2.6, 2, -10.4);
        cout << "Initial lines:" << endl;
        cout << left << setw(10) << "first: " << first << endl;
        cout << left << setw(10) << "second: " << second << endl;
        //determine if parallel, expecting true
        assert(parallel(first, second) == true);
        cout << "Passed second parallel test " << endl;
        cout << endl;

        cout << "----Test bench lines have different slope --> asserting parallel == FALSE" << endl;
        cout << "Initial lines:" << endl;
        //make lines
        first.setPoints(-2, 17, 1, -4.6);
        second.setPoints(-2, 14, 5, 30.5);
        cout << left << setw(10) << "first: " << first << endl;
        cout << left << setw(10) << "second: " << second << endl;
        //determine if parallel, expecting false
        assert(parallel(first, second) == false);
        cout << "Passed third  parallel test " << endl;
        //make lines
        cout << "Checking if lines passing through the same points are parallel, asserting parallel == FALSE" << endl;
        first.setPoints(-2, 14, 1, -5.5);
        second.setPoints(-2, 14, 1, -5.5);
        cout << "Initial lines:" << endl;
        cout << left << setw(10) << "first: " << first << endl;
        cout << left << setw(10) << "second: " << second << endl;
        //determine if parallel, expecting false
        assert(parallel(first, second) == false);
        cout << "Passed fourth parallel test " << endl;
        cout << endl;
    }
    //Test Comparison Operators
    {
        title = "Testing Comparison Operators";
        cout << setfill('*') << setw(10 + title.length()) << title << setfill('*') << setw(10) << "" << endl;
        cout << setfill(' ');
        Line first(0, 1, 0.154, 0), second(0, 1, 0.154, 0), third(-6, -7, 8, 9), fourth(0.46, -0.008, 0.89, 3);
        cout << "----Test bench:" << endl;
        cout << left << setw(10) << "first: " << first << endl;
        cout << left << setw(10) << "second: " << second << endl;
        cout << left << setw(10) << "third: " << third << endl;
        cout << left << setw(10) << "fourth: " << fourth << endl;
        cout << endl;
        //testing <
        cout << "----Testing '<' operator" << endl;
        cout << "asserting first < second --> FALSE" << endl;
        assert(first < second == false);
        cout << "asserting first < fourth --> TRUE" << endl;
        assert(first < fourth == true);
        cout << "asserting third < second --> FALSE" << endl;
        assert(third < second == false);
        cout << "Passed '<' operator tests" << endl;
        cout << endl;

        //testing >
        cout << "----Testing '>' operator" << endl;
        cout << "asserting fourth > third--> FALSE" << endl;
        assert(fourth > third == false);
        cout << "asserting fourth > first --> TRUE" << endl;
        assert(fourth > first == true);
        cout << "asserting first > second --> FALSE" << endl;
        assert(first > second == false);
        cout << "Passed '>' operator tests" << endl;
        cout << endl;

        //testing ==
        cout << "----Testing '==' operator" << endl;
        cout << "asserting first == second --> TRUE" << endl;
        assert((first == second) == true);
        cout << "asserting first == fourth --> FALSE" << endl;
        assert((first == fourth) == false);
        cout << "asserting third == fourth --> FALSE" << endl;
        assert((third == fourth) == false);
        cout << "Passed '==' operator tests" << endl;
        cout << endl;
    }

    //Test file extraction
    {
        title = "Testing ReadFromFile and Sort";
        cout << setfill('*') << setw(10 + title.length()) << title << setfill('*') << setw(10) << "" << endl;
        cout << setfill(' ');
        cout << "NOTE: Added second text file 'LinesTwo.txt' to demonstrate sort is working" << endl;
        vector<Line> Lines, LinesTwo;
        cout << "---Testing File Exctraction" << endl;
        readFromFile("lines.txt", Lines);
        cout << "Parsed lines from lines.txt (unsorted):" << endl;
        //print parsed lines
        for (unsigned i = 0; i < Lines.size(); ++i)
        {
            cout << "line" << i + 1 << " | " << left << Lines.at(i) << endl;
        }
        cout << endl;
        //second text file
        readFromFile("linesTwo.txt", LinesTwo);
        cout << "Parsed lines from linesTwo.txt (unsorted):" << endl;
        //print parsed lines
        for (unsigned i = 0; i < LinesTwo.size(); ++i)
        {
            cout << "line" << i + 1 << " | " << left << LinesTwo.at(i) << endl;
        }
        cout << endl;

        //Test sort
        cout << "---Testing sort" << endl;
        //<alogirthm> :: sort
        sort(Lines.begin(), Lines.end());
        sort(LinesTwo.begin(), LinesTwo.end());

        cout << "Sorted lines from lines.txt(Ascending Order):" << endl;
        //print lines
        for (unsigned i = 0; i < Lines.size(); ++i)
        {
            cout << "line" << i + 1 << " | " << left << Lines.at(i) << endl;
        }
        cout << endl;
        cout << "Sorted lines from linesTwo.txt(Ascending Order):" << endl;
        //print lines
        for (unsigned i = 0; i < LinesTwo.size(); ++i)
        {
            cout << "line" << i + 1 << " | " << left << LinesTwo.at(i) << endl;
        }
        cout << endl;
    }
    //Test cin and cout overloading
    {
        title = "Testing cin and cout overloading";
        cout << setfill('*') << setw(10 + title.length()) << title << setfill('*') << setw(10) << "" << endl;
        cout << setfill(' ');
        cout << "Enter a line with the format  [(x1,y1,),(x2,y2)]" << endl;
        Line line;
        cin >> line;
        cout << "Printing with '<<' operator" << endl;
        cout << "Enterred line" << endl;
        cout << line;
    }

    return 0;
}

double calcSlope(Point a, Point b) { return (a - b).getY() / (a - b).getX(); }
double calcSlope(double a, double b, double c, double d) { return ((b - d) / (a - c)); }
double calcLength(Point a, Point b) { return sqrt(pow((a - b).getY(), 2) + pow((a - b).getX(), 2)); }
double calcLength(double a, double b, double c, double d) { return sqrt(pow(a - c, 2) + pow(b - d, 2)); }

//determine parallel lines
bool parallel(const Line &lone, const Line &ltwo)
{
    return (lone.slope == ltwo.slope) && (lone.getPointOne() != ltwo.getPointOne()) && (lone.getPointTwo() != ltwo.getPointTwo());
}

void readFromFile(string file, vector<Line> &Lines)
{
    string dummy;
    char dummyChar;
    ifstream fileStream;
    //open file
    fileStream.open(file);
    //check if file is open
    if (!fileStream.is_open())
    {
        cout << "Could not open the file" << endl;
        return;
    }
    //parse the first two file lines
    fileStream >> dummy;
    fileStream >> dummyChar;
    if (fileStream.fail() | dummy != "lines:" | dummyChar != '{')
    {
        cout << "extraction error!" << endl;
        return;
    }
    //extraction variables
    Point pone, ptwo;
    Line current;
    char colon, commaOne, commaTwo, commmaThree, leftBracketOne, leftBracketTwo, rightBracketOne, rightBracketTwo;
    string dummystring, remainderString;
    double xOne, yOne, xTwo, yTwo;
    string line;
    int lineNumber = 1;
    while (!fileStream.eof())
    {
        fileStream >> line;
        if (!fileStream.fail())
        {
            if (line == "}")
            {
                break;
            }
            //parse from the colon ':'
            size_t i = line.find(':');
            assert(i != std::string::npos);
            line = line.substr(i, line.length() - i);
            istringstream in(line);
            //parse the line
            in >> colon >> leftBracketOne >> xOne >> commaOne >> yOne >> rightBracketOne >>
                commaTwo >> leftBracketTwo >> xTwo >> commmaThree >> yTwo >> rightBracketTwo >> remainderString;
            //determine parsing success
            if (in.fail())
            {
                cout << " stream failed, line: " << lineNumber << endl;
                fileStream.close();
                return;
            }
            //add to vector  if parsing line was successful
            else if (colon == ':' && leftBracketOne == '[' && leftBracketTwo == '[' && rightBracketOne == ']' && rightBracketTwo == ']' && commaOne == ',' && commaTwo == ',' && commmaThree == ',')
            {
                pone.setX(xOne);
                pone.setY(yOne);
                ptwo.setX(xTwo);
                ptwo.setY(yTwo);
                current.setPointOne(pone);
                current.setPointTwo(ptwo);
                Lines.push_back(current);
            }
            //quit if parsing failed
            else
            {
                cout << "parsing failed, line: " << lineNumber << endl;
                fileStream.close();
                return;
            }
        }
        lineNumber++;
    }

    //parsing from file done
    cout << "Exctraction successful" << endl;
    fileStream.close();
}

//overloaded input operator
istream &operator>>(istream &in, Line &line)
{
    //[(x1,y1),(x2,y2)]
    Point pone, ptwo;
    Line current;
    char squareBracketOne, commaOne, commaTwo, commmaThree, leftBracketOne, leftBracketTwo, rightBracketOne, rightBracketTwo, squareBracketTwo;
    double xOne, yOne, xTwo, yTwo,xThree,yThree;
    cout << "parsing line with '>>' operator" << endl;
    //parse the line
    in >> squareBracketOne >> leftBracketOne >> xOne >> commaOne >> yOne >> rightBracketOne >>
        commaTwo >> leftBracketTwo >> xTwo >> commmaThree >> yTwo >> rightBracketTwo >> squareBracketTwo;

    //update vector if parsing line was successful
    if (!in.fail() && squareBracketOne == '[' && leftBracketOne == '(' && leftBracketTwo == '(' && rightBracketOne == ')' && rightBracketTwo == ')' && commaOne == ',' && commaTwo == ',' && commmaThree == ',' && squareBracketTwo == ']')
    {
        pone.setX(xOne);
        pone.setY(yOne);
        ptwo.setX(xTwo);
        ptwo.setY(yTwo);
        cout << "calculating parsed line length and slope" << endl;
        line.setPointOne(pone);
        line.setPointTwo(ptwo);
        cout << "parsing using '>>' success" << endl;
    }
    else
    {
        cout << "parsing failed in '>>' operator " << endl;
    }

    return in;
}

//overloaded output operator
ostream &operator<<(ostream &out, const Line &line)
{
    out << "[(" << line.getPointOne().getX() << ", " << line.getPointOne().getY() << ") , (" << line.getPointTwo().getX() << ", " << line.getPointTwo().getY() << ")]";
    out << left << setw(8) << "| slope:" << setw(7) << line.getSlope() << left << setw(11) << "| length:" << setw(7) << line.getLength();
    out << right << setfill(' ') << "";
    // out << left << setw(4) << "P1:" << setw(15) << line.getPointOne().print() << left << setw(6) << "| P2:" << line.getPointTwo().print();
    // out << left << setw(8) << "| slope:" << setw(7) << line.getSlope() << left << setw(11) << "| length:" << setw(7) << line.getLength();
    // out << right << setfill(' ') << "";
    return out;
}