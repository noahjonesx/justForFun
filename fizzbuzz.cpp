#include <iostream> 
#include <limits> //allows 'numeric_limits' in clearCin function
using namespace std;
 //clear cin method - call to execute
 //clears error flag after invalid user input 
 // ( such as alphabetic characters or !@#$%^&* )
void clearCin() {
  cin.clear();
  //sets streamsize to clear MAX amount of invalid input characters
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
//main function
int main() {
    //takes user input for number used in algorithm
    int input;
    //enables user to select int y to continue playing,
    // or int n to exit game
    int retry;
    //user input to replay
    int y = 1;
    //user input to exit game
    int n = 2;
    //input of zero can be used to exit game
    while (input != 0) { 
    cout << "                                  " << endl;
    cout << "\nWelcome to FizzBuzz!" << endl;
    cout << "If your number is divisble by 3, BUZZ will be printed." << endl;
    cout << "If your number is divisible by 5, FIZZ will be printed." << endl;
    cout << "If your number is divisble by both 3 and 5, FIZZBUZZ will be printed!" << endl;
    cout << "End program by pressing zero.";
    cout << "Enter a number!" << endl;
    cout << "                                  " << endl;
    //prompt user for their number
    cin >> input;
        //enter while loop upon invalid input to get an acceptable value
            while (cin.fail()) {
                cout << "Please enter a valid number!";
                clearCin(); // calls clearCin method to clear invalid entry
                cin >> input; // remprompt for user input
            }
            //print fizz if number is divisible by 3
            if (((input % 3) == 0) && (input % 5 != 0)){
                //prevents fizz from being printed along with fizzbuzz
                if (((input % 3) == 0) && ((input % 5) == 0)) {
                    continue;
                }
                cout << "fizz" << endl;
            }
            //print buzz if number is divisble by 5
            if ((input % 5) == 0 && (input % 3 != 0)) {
                //prevents buzz from being printed along with fizzbuzz
                if (((input % 3) == 0) && ((input % 5) == 0)) {
                    continue;
                }
            cout << "buzz" << endl;
            }
            //print fizzbuzz! if number is divisble by both 3 and 5
            if (((input % 3) == 0) && (input % 5) == 0) {
                cout << "fizzbuzz!" << endl;
            }
            //if not is not divisble by either
            if (((input % 3) != 0) && ((input % 5) != 0)) {
                cout <<"fizzless, buzzless :(" << endl;
        }
        //after output is printed, ask user if they would like to replay
        cout << "Would you like to play again? (enter 1 for yes /2 for no)";
        //prompt user for entry of 1 or 2
        cin >> retry;
        //retry must be either 1 or 2. Cannot be greater or less than 1-2
            if (retry < 0 || retry > 2) {
                cout << "Invalid Input!" << endl;
                //Reprompt for user input
                cout << "Would you like to play again? (enter 1 for yes /2 for no)";
                cin >> retry;
            }
                if (retry == 1){
                //return to start of program
                    return main();
                }
                        else {
                        cout << "Goodbye!";
                        //exit game
                            exit(EXIT_SUCCESS);
                        }
            
    }
}
//Testing in Windows PowerShell
//Compiled using G++ installed on Windows 11 System
//
//Windows Powershell
// Copyright (C) Microsoft Corporation. All rights reserved.

// Install the latest PowerShell for new features and improvements! https://aka.ms/PSWindows

// PS C:\Users\noahx> cd downloads
// PS C:\Users\noahx\downloads> cd comp2710
// PS C:\Users\noahx\downloads\comp2710> cd test
// PS C:\Users\noahx\downloads\comp2710\test> g++ fizzbuzz.cpp -o "fzbz"
// PS C:\Users\noahx\downloads\comp2710\test> ./fzbz


// Welcome to FizzBuzz!
// If your number is divisble by 3, BUZZ will be printed.
// If your number is divisible by 5, FIZZ will be printed.
// If your number is divisble by both 3 and 5, FIZZBUZZ will be printed!
// End program by pressing zero.Enter a number!

// 1
// fizzless, buzzless :(
// Would you like to play again? (enter 1 for yes /2 for no)1


// Welcome to FizzBuzz!
// If your number is divisble by 3, BUZZ will be printed.
// If your number is divisible by 5, FIZZ will be printed.
// If your number is divisble by both 3 and 5, FIZZBUZZ will be printed!
// End program by pressing zero.Enter a number!

// 3
// fizz
// Would you like to play again? (enter 1 for yes /2 for no)1


// Welcome to FizzBuzz!
// If your number is divisble by 3, BUZZ will be printed.
// If your number is divisible by 5, FIZZ will be printed.
// If your number is divisble by both 3 and 5, FIZZBUZZ will be printed!
// End program by pressing zero.Enter a number!

// 5
// buzz
// Would you like to play again? (enter 1 for yes /2 for no)1


// Welcome to FizzBuzz!
// If your number is divisble by 3, BUZZ will be printed.
// If your number is divisible by 5, FIZZ will be printed.
// If your number is divisble by both 3 and 5, FIZZBUZZ will be printed!
// End program by pressing zero.Enter a number!

// 15
// fizz
// buzz
// fizzbuzz!
// Would you like to play again? (enter 1 for yes /2 for no)1


// Welcome to FizzBuzz!
// If your number is divisble by 3, BUZZ will be printed.
// If your number is divisible by 5, FIZZ will be printed.
// If your number is divisble by both 3 and 5, FIZZBUZZ will be printed!
// End program by pressing zero.Enter a number!

// xxx
// Please enter a valid number!
// Welcome to FizzBuzz!
// If your number is divisble by 3, BUZZ will be printed.
// If your number is divisible by 5, FIZZ will be printed.
// If your number is divisble by both 3 and 5, FIZZBUZZ will be printed!
// End program by pressing zero.Enter a number!

// 15
// fizz
// buzz
// fizzbuzz!
// Would you like to play again? (enter 1 for yes /2 for no)no
// Goodbye!
// PS C:\Users\noahx\downloads\comp2710\test>