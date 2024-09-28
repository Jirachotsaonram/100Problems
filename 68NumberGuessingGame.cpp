#include <iostream>
#include <cstdlib>  // สำหรับ rand() และ srand()
#include <ctime>    // สำหรับ time()
using namespace std;

void show_instructions() {
    cout << "\nWelcome to the Number Guessing Game!" << endl;
    cout << "1. The system will randomly select a number between 1 and 100." << endl;
    cout << "2. Your task is to guess the number!" << endl;
    cout << "3. After each guess, you will be informed if your guess is too high, too low, or correct." << endl;
    cout << "4. Keep guessing until you find the correct number." << endl;
    cout << "5. The game will show you the number of attempts you took to guess the correct number." << endl;
    cout << "Good luck!\n" << endl;
}

void start_new_game() {
    // สุ่มตัวเลขระหว่าง 1 ถึง 100
    srand(time(0));
    int random_number = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "\nA new game has started! Try to guess the number (between 1 and 100): " << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > random_number) {
            cout << "Too high! Try again." << endl;
        } else if (guess < random_number) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Correct! You've guessed the number in " << attempts << " attempts." << endl;
        }
    } while (guess != random_number);
}

void display_menu() {
    int choice;
    do {
        cout << "\nMenu Options:" << endl;
        cout << "1. Start New Game" << endl;
        cout << "2. Show Instructions" << endl;
        cout << "3. Exit" << endl;
        cout << "Please select an option: ";
        cin >> choice;

        switch (choice) {
        case 1:
            start_new_game();
            break;
        case 2:
            show_instructions();
            break;
        case 3:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please select again." << endl;
        }
    } while (choice != 3);
}

int main() {
    display_menu();
    return 0;
}
