//Dalitso Banda CSC10300-CC1 HM2
#include <iostream>
#include <string>
#include <cmath>
#include <limits> //I only used this library to make sure input data type was valid

using namespace std;

int main()
{
    //source sytems
    enum Base
    {
        BINARY = 2,
        TERNARY = 3,
        QUATERNARY = 4,
        QUINARY = 5,
        SENARY = 6,
        SEPTENARY = 7,
        OCTAL = 8,
        NONARY = 9,
        DECIMAL = 10,
        HEXADECIMAL = 16
    };
    //target modes depending on the source system selected
    enum Mode
    {
        baseToDecimal = 1,
        decimalToBase = 2,
        hexToDecandOct = 3
    };
    //Program Engine -- while loop that runs until the user decides to quit
    while (true)
    {
        //display source system menu
        cout << "\n====================================="
             << "\n";
        cout << "Number System Conversion======================"
             << "\n";
        cout << "====================================="
             << "\n";
        cout << "CHOOSE YOUR SOURCE NUMBER SYSTEM:"
             << "\n";
        cout << "(2) BINARY\n"
             << "(3) TERNARY\n"
             << "(4) QUATERNARY\n"
             << "(5) QUINARY\n"
             << "(6) SENARY\n"
             << "(7) SEPTENARY\n"
             << "(8) OCTAL\n"
             << "(9) NONARY\n"
             << "(10) DECIMAL\n"
             << "(16) HEXADECIMAL\n"
             << "INPUT ANY OTHER VALUE TO EXIT THE PROGRAM"
             << "\n";
        //select the source
        int source{0};
        cin >> source;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        bool quit = false;
        //bool run = true;
        string inputList, targetList, sourceLabel, targetLabel;
        int targetMode{0};
        //make sure the input to the source was valid
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            source = 0;
        }
        //assign with a specific input list string, target list string and target mode depending on the source chosen
        switch (source)
        {
        case BINARY:
        case TERNARY:
        case QUATERNARY:
        case QUINARY:
        case SENARY:
        case SEPTENARY:
        case OCTAL:
        case NONARY:
            inputList = "Input  {2, 3, 4, 5, 6, 7, 8, 9}\n";
            targetList = "(10) DECIMAL\n";
            targetMode = baseToDecimal;
            break;
        case DECIMAL:
            inputList = "Input {10}\n";
            targetList = "(2) BINARY\n(3) TERNARY\n(4) QUATERNARY\n(5) QUINARY \n(6) SENARY\n(7) SEPTENARY\n(8) OCTAL\n(9 NONARY\n(16) HEXADECIMAL";
            targetMode = decimalToBase;
            break;
        case HEXADECIMAL:
            inputList = "Input  {16}\n";
            targetList = "(8) OCTAL\n(10) DECIMAL\n";
            targetMode = hexToDecandOct;
            break;
        default:
            //take user to quit menu if  the input for source is invalid
            quit = true;
            break;
        }
        if (quit == false)
        {
            //assign a source label depending on the cosen source input
            switch (source)
            {
            case BINARY:
                sourceLabel = "BINARY";
                break;
            case TERNARY:
                sourceLabel = "BINARY";
                break;
            case QUATERNARY:
                sourceLabel = "BINARY";
                break;
            case QUINARY:
                sourceLabel = "QUINARY";
                break;
            case SENARY:
                sourceLabel = "SENARY";
                break;
            case SEPTENARY:
                sourceLabel = " SEPTENARY";
                break;
            case OCTAL:
                sourceLabel = "OCTAL";
                break;
            case NONARY:
                sourceLabel = "NONARY";
                break;
            case DECIMAL:
                sourceLabel = "DECIMAL";
                break;
            case HEXADECIMAL:
                sourceLabel = "HEXADECIMAL";
                break;
            default:
                sourceLabel = "SOURCE X (NON VALID SOURCE)";
                break;
            }
            //Ask user to choose a target
            cout << "\n"
                 << inputList << "\n"
                 << "=====================================\n"
                 << "Source Number System : " << source << " =======================\n"
                 << "=====================================\n"
                 << "CHOOSE YOUR TARGET NUMBER SYSTEM:\n"
                 << targetList
                 << "\nINPUT ANY OTHER VALUE TO QUIT THE PROGRAM.\n"
                 << "====================================="
                 << "\n";
            int target;
            cin >> target;
            //make sure the input is valid (we expect an integer)
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                targetMode = 0;
            }
            //take user to quit menu if inappropriate target is selected relative to each target list
            if (targetMode == 0 || targetMode == baseToDecimal && target != DECIMAL || targetMode == decimalToBase && (target < BINARY || target > NONARY && target != HEXADECIMAL) || targetMode == hexToDecandOct && target != DECIMAL && target != OCTAL)
            {
                quit = true;
            }
            else
            {
                switch (target)
                {
                case BINARY:
                    targetLabel = "BINARY";
                    break;
                case TERNARY:
                    targetLabel = "TERNARY";
                    break;
                case QUATERNARY:
                    targetLabel = "QUATERNARY";
                    break;
                case QUINARY:
                    targetLabel = "QUINARY";
                    break;
                case SENARY:
                    targetLabel = "SENARY";
                    break;
                case SEPTENARY:
                    targetLabel = "SEPTENARY";
                    break;
                case OCTAL:
                    targetLabel = "OCTAL";
                    break;
                case NONARY:
                    targetLabel = "NONARY";
                    break;
                case DECIMAL:
                    targetLabel = "DECIMAL";
                    break;
                case HEXADECIMAL:
                    targetLabel = "HEXADECIMAL";
                    break;
                default:
                    targetLabel = "TARGET X (NON VALID TARGET)";
                    break;
                }
                //print out the converted number along with the chosen source and target
                cout << "\n=====================================\n"
                     << "Source Number System: " << source << ", Target Number System: " << target << "======\n"
                     << "=====================================\n"
                     << "INPUT YOUR NUMBER IN SOURCE BASE:\n";

                string sourceInput, converted = "";
                cin >> sourceInput;

                /*convert string input to integer form first to be easily used in calculations. 
                
                *Note that digit is of data type 'long long int' to purposely avoid overflow incase the input source value is very large.
                *Assume no floating point input              
                *combined with the validation loop to check if input is valid (*hex input) */
                long long int digit{0};
                int numAtChar, rem;
                bool valid;
                int count = 1; //counter variable to keep track of validation loop
                do
                {
                    valid = true;
                    for (int i{0}; i < sourceInput.length(); i++)
                    {
                        //handle hex characters,(A-F && a-f) *note: not case sensitive
                        sourceInput[i] = toupper(sourceInput[i]);
                        if (targetMode == hexToDecandOct && sourceInput[i] >= 'A' && sourceInput[i] <= 'F')
                        {
                            numAtChar = (sourceInput[i] - 'A') + 10;
                        }
                        //handle non hex characters (0-9)
                        else if (sourceInput[i] >= '0' && sourceInput[i] <= '9')
                        {

                            numAtChar = sourceInput[i] - '0';
                        }
                        else
                        {
                            /*validation loop really works for all entries but is really for hex input*/
                            count++;
                            cout << "NOT A VALID NUMBER! TRY AGAIN:\n"
                                 << sourceLabel << ": " << sourceInput << endl;
                            cin >> sourceInput;
                            valid = false;
                            break;
                        }
                        digit += numAtChar * pow(source, sourceInput.length() - i - 1);
                    }
                } while (valid == false && count != 5);
                if (count != 5)
                {
                    if (targetMode == baseToDecimal)
                    {
                        converted = to_string(digit);
                    }
                    else
                    {
                        /*Conversion Algorithm for integer to any base string*/
                        string reversed = "";
                        while (digit > 0)
                        {
                            //convert the digit to binary first if going from hex to octal
                            int base = (targetMode == hexToDecandOct && target == OCTAL) ? BINARY : target;
                            rem = digit % base;
                            //convert to hex if needed before adding to string
                            (rem < 10) ? reversed.push_back(rem + 48) : reversed.push_back(rem + 55);
                            digit /= base;
                        }

                        //hex to Octal via binary
                        if (targetMode == hexToDecandOct && target == OCTAL)
                        {
                            /*Add zeros accordingly to make string iterable every 3 steps
                            Note that the binary string is in reversed form */
                            while (reversed.length() % 3 != 0)
                            {
                                reversed.push_back('0');
                            }
                            //get octal number (0-7) every 3 binary digits and add it to string temp
                            string temp = "";
                            for (int num, j = 0; j < reversed.length(); j += 3)
                            {
                                num = (reversed[j] - 48) + (reversed[j + 1] - 48) * 2 + (reversed[j + 2] - 48) * 4;
                                temp.push_back(num + '0');
                            }

                            reversed = temp;
                        }
                        //unreverse the finished string
                        for (int i = reversed.length() - 1; i > -1; i--)
                        {
                            converted.push_back(reversed[i]);
                        }
                    }

                    cout << sourceLabel << ": " << sourceInput << "\n"
                         << targetLabel << ": " << converted << "\n";
                }
            }
        }

        if (quit)
        {
            //ask the user if they really want to quit
            cout << "\n=====================================\n"
                 << "Confirm Close =============================\n"
                 << "=====================================\n"
                 << "ARE YOU SURE YOU WANT TO QUIT THE PROGRAM?(Y/N)\n"
                 << "====================================="
                 << "\n";
            char ans;
            //make input is valid and check to exit or not
            cin >> ans;
            if (cin.fail() || ans != 'y')
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else
            {
                //exit the while loop for the program and the program ends
                cout << "\nBYE!\n"
                     << "====================================="
                     << "\n";
                break;
            }
        }
        //continue program if the user does not quit
        cout << "\nYOU WILL BE RETURNED TO THE MAIN MENU.\n"
             << "====================================="
             << "\n";
    }
    return 0;
}
