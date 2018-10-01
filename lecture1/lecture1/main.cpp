//
//  Created by Curtis Gibson on 27/09/2018.
//  Copyright © 2018 Curtis Gibson. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void ageCheckCb();
void displayNameCb();
void randomNumber();

int main()
{
    // Excercise 1
    int iExcercise;
    
    cout << "Please select which excercise!\n";
    cout << "1 - Age check. \n2 - Print name. \n3 - Random Number Generator. \n";
    cin >> iExcercise;
    
    if (iExcercise == 1)
        ageCheckCb();
    else if (iExcercise == 2)
        displayNameCb();
    else if (iExcercise == 3)
        randomNumber();
}

// Excercise 1 Lecture 1
void ageCheckCb ()
{
    int iAge;
    bool bResult;
    
    cout << "Please enter your age!\n";
    cin >> iAge;
    
    if (iAge < 18 || iAge > 30)
    {
        bResult = 1;
        
        if (iAge < 18)
            cout << "At " << iAge << " you are too young. \n";
        else if (iAge > 30)
            cout << "At " << iAge << " you are too old. \n";
        
        ageCheckCb();
    }
    else
    {
        bResult = 0;
        cout << iAge << " is the right age. \n";
    }
}

// Excercise 2 Lecture 1
void displayNameCb ()
{
    string sName;
    
    cout << "Please enter your name.\n";
    cin >> sName;
    cout << "Hello " << sName;
}

// Excercise 3 Lecture 1
void randomNumber ()
{
    // Initialize system’s pseudo-random number generator.
    srand(time(nullptr));
    
    int n = 50, guess, iGuessNum = 0;
    int secret = rand()%n + 1;
    
    cout << "Guess a number between 1 and " << n << ": ";
    cin >> guess;
    
    // Incorrect guess
    while (guess != secret)
    {
        iGuessNum++;
        
        if (guess < secret)
            cout << "Wrong! Guess was too low. Guess again: ";
        else
            cout << "Wrong! Guess was too high. Guess again: ";
        
        cin >> guess;
    }
    
    // Success
    cout << "Correct! You guessed in " << iGuessNum << " attempts! \n";
}
