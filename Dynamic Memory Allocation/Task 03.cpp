/*
 Task 3:
 Using the "new" operator, allocate a two dimensional integer array. The number of rows and columns are going to be
 provided by the user as input. However, in this task, all of the rows are not the same size (the array is uneven).
 The user will specify how many elements the individual rows will have. Assign values to the array elements by taking
 user inputs and then print the values. Finally, de-allocate the array using the "delete" operator.
*/

#include <iostream>
using namespace std;

int main()
{
    int row, column;
    cout << "Enter rows and columns elements: ";
    cin >> row >> column;  // Take inputs and store row and column size

    int colArray[row];  // Initialize colArray to store different column size in row
    int **ptr = new int *[row];  // Allocating a pointer array to be used to store "row" array addresses

    cout << "Elements inputs for row: ";
    for (int i = 0; i < row; i++)
        {
        cin >> column;    // Taking and storing the inputs of specified row size
        ptr[i] = new int[column];   // Dynamically allocate array size for each row
        colArray[i] = column;  // Store different column size
    }

    cout << "Input your 2D matrix: ";
    for (int i=0; i<row; i++)  // Take input and save it's addresses on the arrays
        {
        for (int j=0; j<colArray[i]; j++)
        {
            cin >> ptr[i][j];
        }
    }

    cout << "Print the Final Matrix: " << endl;
    for (int i = 0; i < row; i++)  // Print each values of the arrays
        {
        for (int j=0; j<colArray[i]; j++)
        {
            cout << ptr[i][j] << " ";
        }
        cout << endl;
    }

    delete[] ptr; // De-allocating memory

    return 0;
}
