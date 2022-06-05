
#include "HM5_P1_24241306_BANDA_checkedArray.hpp"
#include "HM5_P1_24241306_BANDA_ArrayOutOfRange.hpp"
#include <iostream>
#include <string>
#include <iomanip>

int main()
{
    string title = "TESTING CHECKED ARRAY ACCESS";
    cout << setfill('*') << setw(10 + title.length()) << title << setfill('*') << setw(10) << "" << endl;
    cout << setfill(' ');
    //checked array sizes
    const int len = 5;
    //Test benches
    double doubleTestBench[len]{0.5, 1, 1.5, 2, 2.5};
    int intTestBench[len]{10, 20, 30, 40, 50};
    string stringTestBench[len]{"audi", "bmw", "toyota", "lexus", "benz"};

    //make checked arrays  of size len
    CheckedArray<double> doubleArray(5);
    CheckedArray<int> intArray(5);
    CheckedArray<string> stringArray(5);
    cout << "---Testing Construction of checked arrays with size parameter" << endl;
    assert(doubleArray.getSize() == len);
    assert(intArray.getSize() == len);
    assert(stringArray.getSize() == len);
    cout << "Passed construction with size parameter test" << endl;
    cout << "double checkedArray size: " << doubleArray.getSize() << "| ";
    cout << "int checkedArray size: " << intArray.getSize() << "| ";
    cout << "string checkedArray size: " << stringArray.getSize();
    cout << endl;
    //print test benches
    cout << "---Current test benches:" << endl;
    cout << "doubles: ";
    for (int i = 0; i < len; i++)
    {
        cout << doubleTestBench[i] << " ";
    }
    cout << endl;
    cout << "ints: ";
    for (int i = 0; i < len; i++)
    {
        cout << intTestBench[i] << " ";
    }
    cout << endl;
    cout << "strings: ";
    for (int i = 0; i < len; i++)
    {
        cout << stringTestBench[i] << " ";
    }
    cout << endl;
    cout << endl;
    //fill checked arrays
    cout << "---Filling  checked arrays with test bench values (types: double, string, and int)" << endl;
    for (int i = 0; i < len; i++)
    {
        doubleArray[i] = doubleTestBench[i];
        intArray[i] = intTestBench[i];
        stringArray[i] = stringTestBench[i];
        //assert filling worked
        assert(doubleArray[i] == doubleTestBench[i]);
        assert(intArray[i] == intTestBench[i]);
        assert(stringArray[i] == stringTestBench[i]);
    }
    cout << "Passed array filling test with proper indexes" << endl;
    cout << "---Filled Checked Arrays:" << endl;
    //print filled checked arrays
    cout << "doubles: ";
    for (int i = 0; i < len; i++)
    {
        cout << doubleArray[i] << " ";
    }
    cout << endl;
    cout << "ints: ";
    for (int i = 0; i < len; i++)
    {
        cout << intArray[i] << " ";
    }
    cout << endl;
    cout << "strings: ";
    for (int i = 0; i < len; i++)
    {
        cout << stringArray[i] << " ";
    }
    cout << endl;
    cout << endl;

    //test exception handling
    title = "TESTING CHECKED ARRAY ACCESS EXCEPTION HANDLING";
    cout << setfill('*') << setw(10 + title.length()) << title << setfill('*') << setw(10) << "" << endl;
    cout << setfill(' ');

    int invalidIndex = -3;
    string exceptionSetting = "ArrayOutofRange";
    cout << "Testing: " << exceptionSetting << "\nInvalid index used: " << invalidIndex << endl;
    try
    {
        //try invalid access
        cout << stringArray[invalidIndex] << endl;
    }
    //ArrayOutOfRangeError catch blocks
    catch (CheckedArray<double>::ArrayOutOfRangeError &error)
    {

        cout << error.what() << endl;
    }
    catch (CheckedArray<int>::ArrayOutOfRangeError &error)
    {

        cout << error.what() << endl;
    }
    catch (CheckedArray<string>::ArrayOutOfRangeError &error)
    {

        cout << error.what() << endl;
    }
    //ArrayOutOfRange catch block
    catch (ArrayOutOfRange &error)
    {
        cout << "ArrayOutofRange:" << endl;
        cout << error.what() << endl;
    }
    //out_of_range catch block
    catch (out_of_range &error)
    {
        cout << error.what() << endl;
    }

    return 0;
}
