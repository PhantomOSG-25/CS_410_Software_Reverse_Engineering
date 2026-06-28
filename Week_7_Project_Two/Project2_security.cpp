#include <iostream>
#include <string>
using namespace std;

string username;

// SECURITY VULNERABILITY:
// Hardcoded password stored directly in source code.
// In a real system, this should be replaced with secure password storage.
string password = "123";

int choice;
int changechoice;
int newservice;
int answer;

string name1 = "Bob Jones";
string name2 = "Sarah Davis";
string name3 = "Amy Friendly";
string name4 = "Johnny Smith";
string name5 = "Carol Spears";

int num1 = 1;
int num2 = 2;
int num3 = 1;
int num4 = 1;
int num5 = 2;

int CheckUserPermissionAccess()
{
    cout << "Enter your username: " << endl;
    cin >> username;

    cout << "Enter your password: " << endl;

    // SECURITY VULNERABILITY:
    // Password is entered and compared as plaintext.
    cin >> password;

    if (password.compare("123") == 0)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

void DisplayInfo()
{
    cout << "  Client's Name    Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
    cout << "1. " << name1 << " selected option " << num1 << endl;
    cout << "2. " << name2 << " selected option " << num2 << endl;
    cout << "3. " << name3 << " selected option " << num3 << endl;
    cout << "4. " << name4 << " selected option " << num4 << endl;
    cout << "5. " << name5 << " selected option " << num5 << endl;
}

void ChangeCustomerChoice()
{
    cout << "Enter the number of the client that you wish to change" << endl;

    // SECURITY VULNERABILITY:
    // Original code did not validate the customer number.
    cin >> changechoice;

    // SECURITY FIX:
    // Verifies that the selected customer number is within the valid range.
    if (changechoice < 1 || changechoice > 5)
    {
        cout << "Invalid customer number." << endl;
        return;
    }

    cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << endl;

    // SECURITY VULNERABILITY:
    // Original code did not validate the service selection.
    cin >> newservice;

    // SECURITY FIX:
    // Only allows approved service choices.
    if (newservice != 1 && newservice != 2)
    {
        cout << "Invalid service selection." << endl;
        return;
    }

    if (changechoice == 1)
    {
        num1 = newservice;
    }
    else if (changechoice == 2)
    {
        num2 = newservice;
    }
    else if (changechoice == 3)
    {
        num3 = newservice;
    }
    else if (changechoice == 4)
    {
        num4 = newservice;
    }
    else if (changechoice == 5)
    {
        num5 = newservice;
    }
}

int main()
{
    cout << "Created by Michael Wood" << endl;
    cout << "Hello! Welcome to our Investment Company" << endl;

    answer = CheckUserPermissionAccess();

    // SECURITY VULNERABILITY:
    // Original code allowed unlimited login attempts.

    // SECURITY FIX:
    // Limits failed login attempts to help reduce brute-force attacks.
    int loginAttempts = 0;

    while (answer != 1 && loginAttempts < 3)
    {
        cout << "Invalid Password. Please try again" << endl;
        loginAttempts++;
        answer = CheckUserPermissionAccess();
    }

    if (answer != 1)
    {
        cout << "Maximum login attempts exceeded." << endl;
        return 0;
    }

    do
    {
        cout << "What would you like to do?" << endl;
        cout << "DISPLAY the client list (enter 1)" << endl;
        cout << "CHANGE a client's choice (enter 2)" << endl;
        cout << "Exit the program.. (enter 3)" << endl;

        // SECURITY VULNERABILITY:
        // Original code did not validate menu input.

        // SECURITY FIX:
        // Validates that the menu input is numeric before processing.
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid menu selection." << endl;
            continue;
        }

        cout << "You chose " << choice << endl;

        if (choice == 1)
        {
            // SECURITY VULNERABILITY:
            // Customer information is displayed without role-based authorization.
            DisplayInfo();
        }
        else if (choice == 2)
        {
            // SECURITY VULNERABILITY:
            // Any authenticated user can attempt to change customer service choices.
            ChangeCustomerChoice();
        }
        else if (choice != 3)
        {
            // SECURITY FIX:
            // Handles invalid numeric menu choices.
            cout << "Invalid menu selection." << endl;
        }

    } while (choice != 3);

    return 0;
}