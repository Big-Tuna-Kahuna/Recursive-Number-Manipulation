# Recursive-Number-Manipulation
 Program is designed to demonstrate various recursive functions on an integer input greater than 9. It includes functionalities such as checking if the digits of the number are in increasing order, reversing the digits, summing the digits, calculating the sum of squares from 0 to the number, and displaying the number vertically.

Features
Check Digit Order: Determines if the digits of the entered integer are in increasing order.
Reverse Digits: Reverses the order of the digits of the number.
Sum of Digits: Calculates the sum of the digits of the entered integer.
Sum of Squares: Computes the sum of the squares of all integers from 0 to the entered number.
Display Vertically: Displays the digits of the number in a vertical sequence.

Requirements
C++11 compatible compiler
Standard libraries: iostream, limits

Compilation Command
g++ -o recursion_program recursion_program.cpp -std=c++11

Running the Program
Execute the compiled program from the command line:
./recursion_program

User Input
The user will be prompted to enter an integer greater than 9. If the input is not valid, the user will be asked to enter the number again.

Output
The program outputs:
Whether the digits of the number are in increasing order.
The number with digits reversed.
The sum of the digits of the number.
The sum of squares from 0 to the number.
The number displayed vertically.

Code Functions
isIncreasing(int num): Recursively checks if digits are in increasing order.
reversal(int num, int sum): Recursively reverses the digits of the number.
sumDigits(int num, int sum): Recursively sums the digits of the number.
sumSquares(int num): Recursively calculates the sum of the squares of the numbers from 0 to n.
displayVert(int num): Recursively displays the number vertically.

Menu-driven Interface
The program uses a simple menu-driven interface to guide the user through its functionalities, making it user-friendly and interactive.
