#include <iostream>
#include <limits>
using namespace std;

int gameCreditsMinutes = 0;

void clearBadInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void showMenu()
{
    cout << "\n=== Study Quest ===\n"
         << "1) Complete Study Quest (+30 min)\n"
         << "2) Check Game Time Credits\n"
         << "3) Spend 30 min to Play (placeholder)\n"
         << "4) Exit\n"
         << "Choose: ";
}

void completeQuest()
{
    cout << "\nQuest complete! +30 minutes earned.\n";
    gameCreditsMinutes += 30;
}

void checkCredits()
{
    cout << "\nGame Time Credits: " << gameCreditsMinutes << " minutes\n";
}

void playGame()
{
    if (gameCreditsMinutes >= 30)
    {
        cout << "\nPlay started (placeholder). -30 minutes.\n";
        gameCreditsMinutes -= 30;
    }
    else
    {
        cout << "\nNot enough credits. Complete a quest first.\n";
    }
}

int main()
{
    while (true)
    {
        showMenu();

        int choice;
        if (!(cin >> choice))
        {
            cout << "\nPlease enter a number.\n";
            clearBadInput();
            continue;
        }

        switch (choice)
        {
        case 1: completeQuest(); break;
        case 2: checkCredits(); break;
        case 3: playGame(); break;
        case 4: cout << "Goodbye!\n"; return 0;
        default: cout << "Invalid option.\n"; break;
        }
    }
}