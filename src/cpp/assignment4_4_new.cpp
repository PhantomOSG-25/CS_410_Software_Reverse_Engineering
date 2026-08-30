#include <iostream>
using namespace std;

int main()
{
    long binaryNumber;
    long hexValue = 0;
    long base = 1;
    long remainder;

    cout << "Enter the binary number: " << endl;
    cin >> binaryNumber;

    while (binaryNumber > 0)
    {
        remainder = binaryNumber % 10;
        hexValue = hexValue + (remainder * base);
        base = base * 2;
        binaryNumber = binaryNumber / 10;
    }

    cout << "\nEquivalent hexadecimal value: " << hexValue << endl;

    return 0;
}
