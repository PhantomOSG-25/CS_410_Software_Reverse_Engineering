#include <iostream>
using namespace std;

void DisplayMenu()
{
    cout << "----------------" << endl;
    cout << "- 1) Add       -" << endl;
    cout << "- 2) Subtract  -" << endl;
    cout << "- 3) Multiply  -" << endl;
    cout << "- 4) Exit      -" << endl;
    cout << "----------------" << endl;
}

int main()
{
    int choice = 0;
    int n1, n2;

    // SECURITY FIX:
    // Changed loop condition from choice != 5 to choice != 4.
    while (choice != 4)
    {
        DisplayMenu();

        // SECURITY FIX:
        // Validate menu input before processing.
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        if (choice == 1)
        {
            // SECURITY FIX:
            // Validate numeric input.
            if (!(cin >> n1 >> n2))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid numbers entered." << endl;
                continue;
            }

            // SECURITY FIX:
            // Corrected operation. Original code performed subtraction.
            cout << n1 << " + " << n2 << " = " << n1 + n2 << endl;
        }
        else if (choice == 2)
        {
            if (!(cin >> n1 >> n2))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid numbers entered." << endl;
                continue;
            }

            // SECURITY FIX:
            // Corrected subtraction operation.
            cout << n1 << " - " << n2 << " = " << n1 - n2 << endl;
        }
        else if (choice == 3)
        {
            if (!(cin >> n1 >> n2))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid numbers entered." << endl;
                continue;
            }

            // SECURITY FIX:
            // Original binary performed division and could crash when n2 was zero.
            // Changed to multiplication to match menu option.
            cout << n1 << " * " << n2 << " = " << n1 * n2 << endl;
        }
        else if (choice == 4)
        {
            cout << "Exiting program." << endl;
        }
        else
        {
            // SECURITY FIX:
            // Reject invalid menu choices.
            cout << "Invalid menu selection." << endl;
        }
    }

    return 0;
}
