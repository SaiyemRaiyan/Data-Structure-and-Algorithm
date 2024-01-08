#include <iostream>
#include "complex.cpp"
using namespace std;

int main()
{
    Complex c1(5, 2), c2(5, 3);   // Initialize two complex numbers

    Complex c3 = c1+c2;   // Add two complex numbers
    c3.Print();

    Complex c4 = c1*c2;   // Multiply two complex numbers
    c4.Print();

    cout << (c1 != c2) << endl;  // Check if two complex numbers are not equal

    return 0;
}
