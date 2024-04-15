//   <This program is an exercise in recursion. Each function uses recursion in some
//   <fashion to manipulate a number that the user will enter that is > than 9.
//   <It shows if the digits are increasing in order. Returns digits reversed.
//   <Returns the sum of the digits. Returns the sums of squares of the numbers from
//   <0 to the number n. And it displays the number vertically.

#include <iostream>
#include <limits>

using namespace std;


void menu();//Displays the menu which calls all functions and controls flow
bool isIncreasing(int);//Shows if digits are increasing in order
int reversal(int, int);//Reverses order of digits
int sumDigits(int, int);//Sums up the digits
int sumSquares(int);//Sums up the squares of the digits
void displayVert(int);//Displays the numbers in a vertical manner

int main()
{
    menu();//call main menu

    return 0;
}

//*****************************************************************
// Displays the menu and options for user to pick. Validates the user
// input. Calls the appropriate functions.
//
// Parameters
// None
// return - void
//*******************************************************************
void menu()
{
    int choice;//holds the user option of 1 or 9
    int num;//holds the number selected > 9

    cout << "*** Welcome to My Program Using Recursions ***" << endl;
    cout << "\nThe function of this program is to " << endl;
    cout << "accept from the keyboard" << endl;
    cout << "a positive integer that is > 9." << endl;
    cout << "\nThe program then does the following  :" << endl;
    cout << "\n   1- Returns true is the digits of that integer n" << endl;
    cout << "      are in increasing order; otherwise, " << endl;
    cout << "      the function returns false." << endl;
    cout << "   2- Returns the numbers with the digits reversed." << endl;
    cout << "   3- Returns the sum of the digits of the integer." << endl;
    cout << "   4- Returns the sum of squares of the numbers from 0" << endl;
    cout << "      to the number n." << endl;
    cout << "   5- Displays the number vertically." << endl;

    do
    {
        cout << "\nSelect from the following menu" << endl;
        cout << "\n1.  Enter a positive integer >  9." << endl;
        cout << "9.  Terminate the program.    ";
        cin >> choice;
        while ( choice != 1 && choice != 9 || cin.fail())//if choice is not 1 or 9
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');//clear buffer
            cout << "\nInvalid Option" << endl;
            cout << "\nSelect from the following menu" << endl;
            cout << "\n1.  Enter a positive integer >  9." << endl;
            cout << "9.  Terminate the program.    ";
            cin >> choice;

        }

        if (choice == 1)
        {
            cout << "\n\nEnter a positive integer >  9.   ";
            cin >> num;
        }

        if (num <= 9 || cin.fail())//if num isn't greater than 9
        {
            cout << "\n\nInvalid Integer - Integer must be > 9" << endl << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

        }
        else if (choice != 9)//if choice isn't to quit
        {
            if (isIncreasing(num))//Explains the output to user and calls the functions.
                cout << "\nThe digits of " << num << " are in increasing order." << endl;
            else
                cout << "\nThe digits of " << num << " are not in increasing order." << endl;

            cout << "\nThe Original Digits are " << num << " ---   " << "Digits reversed = ";
            cout << reversal(num, 0) << endl;

            cout << "\nSum of digits of the number " << num << " is  =  " << sumDigits(num, 0) << endl;

            cout << "\nSum of squares from 0 to " << num << "  =  " << sumSquares(num) << endl;

            cout << "\n" << num << "  Displayed Vertically" << endl;

            displayVert(num);

            cout << endl;

        }




    }while (choice == 1);//while user wants to continue program
    cout << "\n\nGabriel Deluna - Tweak Programming Director" << endl;
    cout << "November - 2nd - 2020" << endl;
}


//*****************************************************************
// Determines if digits are in increasing order or not
//
// Parameters
// int num - The number to be evaluated
// return - bool - true if increasing, false if not
// return - isIncreasing(num / 10) - recursive call with number without
// last digit
//*******************************************************************
bool isIncreasing(int num)
{
    int last = num % 10;//gets the last digit
    int next = num % 100 / 10;//gets the digit next to last

    if (num < 10)//if number left is single digit then the number was increasing order
        return true;
    else if (last <= next)//if last digit is less than next, number is not increasing
        return false;
    else
        return isIncreasing(num / 10);//recursive call with number without last digit
}


//*****************************************************************
// Reverses the digit order in the number
//
// Parameters
// int num - number to be reversed, int sum - sum of the reversed numbers
// return - sum - the number thats in reversed order.
// return - reversal(num/10, sum) - recursive with number with last
// digit taken off and the reversed number.
//*******************************************************************
int reversal(int num, int sum)
{

    if (num == 0)//if num is zero return reversed number to menu
        return sum;
    else
    {
        sum = (sum * 10) + (num % 10); //shifts sum left and adds last digit of num
        return reversal(num / 10, sum);// recursive call with number with one less digit
        //and the reversed number so far
    }
}


//*****************************************************************
// Sums up the digits of the number
//
// Parameters
// int num - number to be summed up
// int sum - the sum of the digits
// return - sum - the sum of the digits
// return - sumDigits(num/10, sum) - recursive call with num with one less
// digit and the sum added so far
//*******************************************************************
int sumDigits(int num, int sum)
{
    if (num == 0)//end recursion when num = 0
        return sum;
    else
    {
        sum += num % 10;//adds last digit of num to sum
        return sumDigits(num /10, sum);//recursion with number with one less digit
        //and the sum so far
    }

}


//*****************************************************************
// Takes each digit from zero to N and sums the square
//
// Parameters
// int num - the number to be evaluated
// return - recursion that squares each number and subtracts one from num
//*******************************************************************
int sumSquares(int num)
{
    if (num == 0)
        return 0;
    else
        return num * num + sumSquares(num - 1);//recursion that squares
        //each number and subtracts one from num
}


//*****************************************************************
// Displays the digits in a vertical fashion
//
// Parameters
// int num - the number to be displayed vertically
// return - none
//*******************************************************************
void displayVert(int num)
{
    int last;

    if (num == 0)
        return;
    else
    {
        last = num % 10;//gets last digit of number
        displayVert(num / 10);//recursion with number with one less digit
        cout << last << endl;//As the recursion is looping back, prints
        //each digit that was stored in last

    }
}








