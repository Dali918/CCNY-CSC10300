//Dalitso Banda CSC10300 CC1
#include "HM3_Banda_24241306_Header.h"

/*****************TEST FUNCTIONS****************************/

/**********************TESTING FOR N=3*******************************************/

void testPrint()
{
    //test is passed if the output is the same
    cout << "Testing print\n";
    double array[3][3] = {{1, 3, 1}, {4, 6, -7}, {6, 1, 3}};
    string output = "1\t3\t1\n4\t6\t-7\n6\t1\t3\n";
    cout << "Output should be:\n";
    cout << output << endl;
    cout << "Output is:\n";
    print(array);
    cout << endl;
}
void testareEqual()
{
    cout << "Testing areEqual\n";

    //array One and array Two are equal
    double arrayOne[3][3] = {{0.5, 3, 1}, {4, 6, -7}, {-256, 1.62, 19467}};
    double arrayTwo[3][3] = {{0.5, 3, 1}, {4, 6, -7}, {-256, 1.62, 19467}};

    //array three and array four not equal
    double arrayThree[3][3] = {{0.5, 3, 1}, {4, 6, 9}, {-256, 1.62, 19467}};
    double arrayFour[3][3] = {{0.5, 3, 34}, {4, 6, -7}, {-256, 2, 19467}};

    //test is passed if array one ==array two evalutes to true
    assert(areEqual(arrayOne, arrayTwo) == true);
    //test is passed if array three==array four evalutes to true
    assert(areEqual(arrayThree, arrayFour) == false);

    cout << "passed equal array test" << endl;
    cout << endl;
}

void testIsIdentity()
{
    cout << "Testing isIdentity function\n";
    //create 3 x 3 identity matrix
    double identity[3][3] = {0};
    double notIdentity[3][3] = {{1, 0, 0}, {0.5, 0, 1}, {0, 0, 1}};
    for (int i = 0; i < 3; i++)
    {
        identity[i][i] = 1;
    }

    cout << "identity matrix of size 3 x 3\n"
         << endl;
    print(identity);
    cout << endl;
    //test is passed if isIdentity(identity) evalutes to true
    assert(isIdentity(identity));
    //test is passed if isIdentity(notIdentity) evaluates to false
    assert(isIdentity(notIdentity) == false);
    cout << "passed isIdentity test" << endl;
    cout << endl;
}

void testisEven()
{
    cout << "Testing isEven with values: 5, 2, 60, 2.5, -30, -6.5\n";
    //Note that decimal values are neither even nor odd thus but isEven evaluates them to false
    vector<double> numbers = {5, 2, 60, 93, -30, -5};
    assert(isEven(numbers.at(0)) == false);
    assert(isEven(numbers.at(1)) == true);
    assert(isEven(numbers.at(2)) == true);
    assert(isEven(numbers.at(3)) == false);
    assert(isEven(numbers.at(4)) == true);
    assert(isEven(numbers.at(5)) == false);
    //test is passed if all assert statements are passed
    cout << "passed isEven test" << endl;
    cout << endl;
}

void testEvenAndOdd()
{
    cout << "Testing countevenAndOdd\n";
    double arrayOne[3][3] = {{5, 2, 6}, {-56, 7, 2}, {-256, 1, 194}};
    double arrayTwo[3][3] = {{4, 2, 6}, {-57, 7, 9}, {-253, 1, 194}};
    int even, odd;
    evenAndOdd(arrayOne, even, odd);
    cout << "Array is:\n5\t2\t6\n-56\t7\t2\n-256\t1\t194\n";
    cout << "Expected even,odd: 6,3\n";
    cout << "Actual even,odd: " << even << "," << odd << "\n";
    //test will pass if the assert expressions evaluates to true
    assert(even == 6 && odd == 3);
    evenAndOdd(arrayTwo, even, odd);
    cout << "Array is:\n4\t2\t6\n-57\t7\t9\n-253\t1\t194\n";
    cout << "Expected even,odd: 4,5\n";
    cout << "Actual even,odd: " << even << "," << odd << "\n";
    assert(even == 4 && odd == 5);
    cout << "Passed evenOdd test" << endl;
    cout << endl;
}



/*************************TESTING FOR N=4*******************************************/
/*
void testSumOfColumns()
{
    cout << "Testing sumOfColumns\n";
    cout << "Initial matrix:\n";
    cout << "5\t2\t6\t3\n-56\t7\t2.56\t0\n-256\t1\t194\t4\n2\t0\t 1\t1\n";
    cout << "Expected sums:\n";
    cout << "-305\t10\t203.56\t8\n";
    double arrayOne[4][4] = {{5, 2, 6, 3}, {-56, 7, 2.56, 0}, {-256, 1, 194, 4}, {2, 0, 1, 1}};
    vector<double> testSum = {-305, 10, 203.56, 8};
    vector<double> sum = sumOfColumns(arrayOne);

    cout << "Actual sums:\n";
    for (unsigned i = 0; i < 4; i++)
    {
        //test passes if expected sum elements == computed sum elements
        assert(testSum.at(i) == sum.at(i));
        cout << sum.at(i) << "\t";
    }
    cout << endl;
    cout << "Passed sum of columns test" << endl;
    cout << endl;
}
void testSumOfRows()
{
    cout << "Testing sumOfRows\n";
    cout << "Initial matrix:\n";
    cout << "5\t2\t6\t3\n-56\t7\t2.56\t0\n-256\t1\t194\t4\n2\t0\t 1\t1\n";
    cout << "Expected sums:\n";
    cout << "16\t-46.44\t57\t4\n";
    double arrayOne[4][4] = {{5, 2, 6, 3}, {-56, 7, 2.56, 0}, {-256, 1, 194, 4}, {2, 0, 1, 1}};
    double testSum[4] = {16, -46.44, -57, 4};
    double *sum = sumOfRows(arrayOne);

    cout << "Actual sums:\n";
    for (int i = 0; i < 4; i++)
    {

        //test passes if expected sum elements == computed sum elements
        assert(testSum[i] == sum[i]);
        cout << sum[i] << "\t";
    }
    cout << endl;
    cout << "Passed sum of rows test" << endl;

    cout << endl;
}

void testSort()
{

    cout << "Testing sortRowsortColumn\n";
    cout << "Initial matrix:\n";
    cout << "0.1\t0\t90\t-2.5\n60\t2.5\t5\t-30\n956\t-1.78\t5\t4\n1\t2\t3\t4\n";
    double array[4][4] = {{0.1, 0, 90, -2.5}, {60, 2.5, 5, -30}, {956, -1.78, 5, 4}, {1, 2, 3, 4}};
    double sorted[4][4] = {{-30, 0, 0.1, 4}, {-2.5, 2, 3, 60}, {-1.78, 2.5, 5, 90}, {1, 4, 5, 956}};
    sortByRowAndColumn(array);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            //test passes if expected sorted array elements == function sorted matrix elements
            assert(array[i][j] == sorted[i][j]);
        }
    }

    cout << "Expected sorted matrix:\n";
    cout << "-30\t0\t0.1\t4\n-2.5\t2\t3\t60\n-1.78\t2.5\t5\t90\n1\t4\t5\t956\n";
    cout << "Actual sorted matrix:\n";
    print(array);

    cout << "Passed sorting by row and column" << endl;
    cout << endl;
}*/

int main()
{
    double A[N][N];
    double B[N][N];

    cout << "Enter " << N * N << " values in array A" << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << "Enter " << N * N << " values in array B" << endl;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> B[i][j];
        }
    }

    cout << "For A you entered" << endl;
    print(A);
    cout << "For B you entered:" << endl;
    print(B);
    cout << endl;

    //TODO: To use unit Testing for N=3, comment out test function defintions for N=4 above and function calls below.Set N=3 in header file

    cout << "*****************UNIT TESTING FOR N=3********************" << endl;
    testPrint();
    testareEqual();
    testIsIdentity();
    testisEven();
    testEvenAndOdd();

    //TODO: To use unit Testing for N=4, comment out test function defintion for N=3 above and function calls below.Set N=4 in header file
    /*cout << "*****************UNIT TESTING FOR N=4********************" << endl;
    testSumOfColumns();
    testSumOfRows();
    testSort();*/

    return 0;
}