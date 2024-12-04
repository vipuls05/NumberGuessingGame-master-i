//
//  main.cpp
//  NumberGuessingGame
//
//  Created by Mean Machine #2 on 8/4/17.
//  Copyright © 2017 MeanMachine. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

const int IGNORE_CHARS = 256;

/* Function declaration */
void playGame();
bool playAgain();
bool isGameOver(int secretNumber, int guess, int numberOfTries);
int getGuess(int numberOfTries);
int setSecretNumber();
void displayResult(int secretNumber, int numberOfTries);
void checkTemp(int d);
int getUpperBound();


int main() {
    
    do
    {
         playGame();
        
    } while(playAgain());
    
   
    return 0;
}


/* Function implementations */
void playGame()
{
    /*
      1. Set the secretNumber - set it to a known value for now
      2. Set the numberOfTries => ceil (log2(range))
    */
    
    int UPPER_BOUND = getUpperBound();
    int secretNumber = rand() % UPPER_BOUND + 1;
    int numberOfTries = ceil( log2(UPPER_BOUND) );
    int guess = 0;
    
    cout << "\nSecret number is between 0 - " << UPPER_BOUND << endl;
    
    do
    {
        /*
            1. get guess from player with appropriate checks with user input and numberOf tries
            2. compare with secretNumber -> compareGuess()
        */
        
        guess = getGuess(numberOfTries);
        
        if(guess != secretNumber)
        {
            int d = guess - secretNumber;
            numberOfTries--;
            
            if(d > 0)
            {
                cout << "\nOh no! Your guess was too high. " << endl;
                checkTemp(d);
                
            } else {
                cout << "\nOh shoot! You guessed too low. " << endl;
                checkTemp(d);
            }
            
        }
        
    } while(isGameOver(secretNumber, guess, numberOfTries));
    
    displayResult(secretNumber, numberOfTries);
    
}

int getGuess(int numberOfTries)
{
    
    int guess;
    bool failure;
    
    do
    {
        failure = false;
        cout << "\nEnter your guess (Number of tries: " << numberOfTries << " ): " << endl;
        cin >> guess;
        
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE_CHARS, '\n');
            cout << "ERROR! Invalid Input. Please try again!" << endl;
            failure = true;
        }
        
    } while(failure);
    
    return guess;
}

bool playAgain()
{
    char input;
    bool failure;
    
    do {
        failure = false;
        cout << "\nDo you want to play again? y/n? " << endl;
        cin >> input;
        
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE_CHARS, '\n');
            cout << "\nERROR! Invalid input. Try again. " << endl;
            failure = true;
        }
        
        
    } while(failure);
    
    return input == 'y';
    
}

bool isGameOver(int secretNumber, int guess, int numberOfTries)
{
    return !(secretNumber == guess || numberOfTries <= 0);
    
}

void displayResult(int secretNumber, int numberOfTries)
{
    if(numberOfTries > 0)
    {
        cout << "\nWoo-hoo! You got it. It was: " << secretNumber << endl;
    } else {
        cout << "\nWomp womp. You lost...It was: " << secretNumber << endl;
    }
    
}

void checkTemp(int d)
{
    d = abs(d);
    if(d <= 5) {
        cout << "\nBut... HOT!!" << endl;
        return;
    } else if (d > 5 && d <= 10) {
        cout << "\nBut....You are getting warmer!. " << endl;
        return;
    } else if (d > 10 && d <= 20) {
        cout << "\nBut...You're getting warm" << endl;
        return;
    } else {
        cout << "\nBut...You're cold. " << endl;
    }
}

int getUpperBound() {
    
    int upBound;
    bool failure;
    
    do {
        failure = false;
        cout << "\nEnter upper-bound: " << endl;
        cin >> upBound;
        
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(IGNORE_CHARS, '\n');
            cout << "\nERROR! Invalid input. Try again. " << endl;
            failure = true;
        }
        
        
    } while(failure);

    return upBound;
    
}

