#include <iostream>
#include "dynarr.cpp"
using namespace std;

int main()
{
    int input, size=5;
    dynArr<int> dint(size);  // Object initialize of "dynArr" class with arguments

    cout<< "Input the 5 size array: ";
    for (int i=0; i<size; i++)  // Take and store "size" number of input values to "dint" object
    {
        cin >> input;
        dint.setValue(i, input);
    }

    cout<< "Array that Input: ";
    for (int i=0; i<size; i++) // Print the values stored on "dint" object
    {
        cout << dint.getValue(i) << " ";
    }
    cout << endl;

    return 0;
}
