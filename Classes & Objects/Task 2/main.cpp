/*
 Task 2:
 Modify the header and the source files. Add a member function "void allocate(int s)" which allows you to change the
 size of the array. Make sure that memory is not leaked.
*/

#include <iostream>
#include "dynarr.cpp"
using namespace std;

int main()
{
    int size, input;
    dynarr d(5); // Object initialize of "dynarr" class

    cout<< "Enter the size of the array: ";
    cin >> size;   // Take and store input array size
    d.allocate(size);  // Allocate "size" sized array on "d" object

     cout<< "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)  // Take and store "size" number of input values to "d" object
    {
        cin >> input;
        d.setValue(i, input);
    }

    cout<< "Print the array that entered: ";
    for (int i = 0; i < size; i++)  // Print all the values stored on "d" object
    {
        cout << d.getValue(i) << " ";
    }
    cout << endl;

    return 0;
}
