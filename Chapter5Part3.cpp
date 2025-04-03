/*
File Name: Chapter5Part3.cpp
Programmer: Yaqoob Nagi
Date: April 2025
Requirements:
- Display a menu allowing the user to select an addition, subtraction, multiplication, or division problem.
- The final menu option should allow the user to quit.
- After solving a problem, the menu should be displayed again.
- Validate user input to ensure it is within the menu options.
- The program should have at least three functions (modules) and should be repeatable.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Function to display the menu and get user choice
int displayMenu() {
    int choice;
    cout << "\nMath Tutor Menu" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Quit" << endl;
    cout << "Enter your choice: ";
    while (!(cin >> choice) || choice < 1 || choice > 5) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid choice. Please enter a number between 1 and 5: ";
    }
    return choice;
}

// Function to generate two random numbers
void generateNumbers(int &num1, int &num2) {
    num1 = rand() % 900 + 100; // Generate a three-digit number
    num2 = rand() % 900 + 100;
}

// Function to get the user's answer with input validation
int getAnswer() {
    int answer;
    while (true) {
        cout << "Enter your answer: ";
        if (cin >> answer) {
            return answer;
        } else {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number.\n";
        }
    }
}

// Function to check the user's answer and provide feedback
void checkAnswer(int num1, int num2, int userAnswer, char operation) {
    int correctAnswer;
    switch (operation) {
        case '+': correctAnswer = num1 + num2; break;
        case '-': correctAnswer = num1 - num2; break;
        case '*': correctAnswer = num1 * num2; break;
        case '/': 
            correctAnswer = num1 / num2; 
            break;
        default: return;
    }
    
    if (userAnswer == correctAnswer) {
        cout << "Correct! Well done!\n";
    } else {
        cout << "Incorrect. The correct answer is: " << correctAnswer << "\n";
    }
}

int main() {
    srand(time(0));
    int choice;
    do {
        choice = displayMenu();
        if (choice == 5) break; // Quit option

        int num1, num2;
        generateNumbers(num1, num2);
        char operation;

        switch (choice) {
            case 1: operation = '+'; break;
            case 2: operation = '-'; break;
            case 3: operation = '*'; break;
            case 4: operation = '/'; 
                    num2 = (num2 == 0) ? 1 : num2; // Avoid division by zero
                    break;
        }

        cout << "Solve the following problem:\n";
        cout << "  " << setw(5) << num1 << endl;
        cout << operation << " " << setw(4) << num2 << endl;
        cout << "______" << endl;

        int userAnswer = getAnswer();
        checkAnswer(num1, num2, userAnswer, operation);

    } while (choice != 5);
    
    cout << "Thank you for using the Math Tutor program!\n";
    return 0;
}
