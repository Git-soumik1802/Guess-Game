#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits> 

using namespace std;

int main() {
    
    srand(static_cast<unsigned int>(time(nullptr)));

  
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;
    const int maxAttempts = 10;  
    bool hasGuessedCorrectly = false;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 100. Try to guess it." << endl;

    while (attempts < maxAttempts) {
        cout << "Attempt #" << attempts + 1 << ": Enter your guess: ";
        cin >> guess;

        if (cin.fail()) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the number (" << secretNumber << ") correctly!" << endl;
            hasGuessedCorrectly = true;
            break;
        }

        attempts++;
    }

    if (!hasGuessedCorrectly) {
        cout << "Sorry, you've run out of attempts. The correct number was " << secretNumber << "." << endl;
    }

    return 0;
}
