#include "HM5_P2_24241306_BANDA_Stack.hpp"
#include <iostream>
#include <iomanip>
#include <cassert>
using namespace std;

int main()
{
    //Testing Constructor and empty
    string title;
    title = "TESTING CONSTRUCTORS AND MEMBER FUNCTION 'EMPTY'";
    cout << setfill('*') << setw(10 + title.length()) << title << setfill('*') << setw(10) << "" << endl;
    cout << setfill(' ');
    cout << "---Test Bench: int stack created with default constructor (numbers) and value intialized string stack (words)" << endl;
    cout << "---Expecting numbers-->empty == true && words-->empty == false" << endl;
    Stack<double> numbers;
    Stack<string> wordList("hello world");
    cout << "numbers-->empty returned : " << std::boolalpha << numbers.empty() << endl;
    cout << "words-->empty returned : " << std::boolalpha << wordList.empty() << endl;
    cout << endl;

    Stack<string> words;
    title = "TESTING PUSH, TOP, SIZE";
    cout << setfill('*') << setw(10 + title.length()) << title << setfill('*') << setw(10) << "" << endl;
    cout << setfill(' ');
    //current test bench
    cout << "--Test Bench 1: -56, 77, 9, 0.6464, 2, 9.888" << endl;
    double array[]{-56, 77, 9, 0.6464, 2, 9.888};
    cout << "--Testing push, top, and size" << endl;
    for (auto i = 0; i < sizeof(array) / sizeof(array[0]); i++)
    {
        //test push
        cout << "Pushing " << array[i] << endl;
        numbers.push(array[i]);
        //test size
        cout << "Expecting new size: " << i + 1 << endl;
        cout << "size: " << numbers.size() << endl;
        assert(numbers.size() == i + 1);
        //test top
        cout << "Expecting top: " << array[i] << endl;
        cout << "Top: " << numbers.top() << endl;
        assert(numbers.top() == array[i]);
        cout << endl;
    }

    //second test bench
    cout << "--Test Bench 2: hello, apple, steve jobs, artificial intelligence, dalitso" << endl;
    string stringArray[]{"hello", "apple", "steve jobs", "artificial intelligence", "dalitso"};
    cout << "--Testing push, top, and size" << endl;
    for (auto i = 0; i < sizeof(stringArray) / sizeof(stringArray[0]); i++)
    {
        //test push
        cout << "Pushing " << stringArray[i] << endl;
        words.push(stringArray[i]);
        //test size
        cout << "Expecting new size: " << i + 1 << endl;
        cout << "size: " << words.size() << endl;
        assert(words.size() == i + 1);
        //test top
        cout << "Expecting top: " << stringArray[i] << endl;
        cout << "Top: " << words.top() << endl;
        assert(words.top() == stringArray[i]);
        cout << endl;
    }
    cout << "PASSED PUSH, TOP, SIZE TEST" << endl;
    //TEST POP
    title = "TESTING POP";
    cout << setfill('*') << setw(10 + title.length()) << title << setfill('*') << setw(10) << "" << endl;
    cout << setfill(' ');
    //current test bench
    int len = sizeof(stringArray) / sizeof(stringArray[0]);
    cout << "--Testing pop with current word stack: dalitso, artificial intelligence, steve jobs, apple, hello" << endl;
    for (auto i = len - 1; i >= 0; i--)
    {
        //pop
        cout << "Popping " << stringArray[i] << endl;
        words.pop();
        //test pop using size comparison
        cout << "Expecting new size: " << i << endl;
        cout << "size after pop: " << words.size() << endl;
        assert(words.size() == i);
        //test pop using top comparison (if not empty)
        if (!words.empty())
        {
            cout << "Expecting new top: " << stringArray[i - 1] << endl;
            cout << "Top: " << words.top() << endl;
            assert(words.top() == stringArray[i - 1]);
            cout << endl;
        }
    }

    cout << endl;
    cout << "--Testing pop with empty stack" << endl;
    cout << "expecting: 'stack is empty!' exception" << endl;
    //test empty stack with pop
    try
    {
        words.pop();
    }
    catch (std::runtime_error &error)
    {
        cout << error.what() << endl;
        cout << endl;
    }
    //test empty stack with top
    cout << "--Testing top with empty stack" << endl;
    cout << "expecting: 'stack is empty!' exception " << endl;
    try
    {
        words.top();
    }
    catch (std::runtime_error &error)
    {
        cout << error.what() << endl;
        cout << endl;
    }
    cout << "PASSED POP TEST" << endl;
    return 0;
}