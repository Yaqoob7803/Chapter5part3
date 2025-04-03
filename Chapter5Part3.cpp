/*
File name: Chapter5Part3.cpp
Programmer: Yaqoob Nagi
Date: April 2025
Requirements: 
- Display two random numbers for addition.
- Wait for user input and validate it.
- Provide feedback on whether the answer is correct or incorrect.
- Allow the user to repeat the process.
- Modularize the code into at least three functions.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main () {
    srand(time(0));

    int num1 = rand() % 900 + 100;
    int num2 = rand() % 900 + 100;

    cout << "Solve the following addition problem:\n";
    cout << "  " << setw(5) << num1 << endl;
    cout << "+ " << setw(4) << num2 << endl;
    cout << "______" << endl;

    int correct_answer = num1 + num2;

    int user_answer;
    cout << "Enter your answer: " << endl;
    cin >> user_answer;

    if (user_answer == correct_answer) {
        cout << "You are correct!" << endl;
    } else {
        cout << "Your answer is not correct." << endl;
    }
    
    return 0;
}
