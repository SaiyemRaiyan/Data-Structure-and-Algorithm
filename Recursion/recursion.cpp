#include<iostream>
#include<cmath>
using namespace std;

int fib(int n)
{
    if(n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}

int factorial(int n)
{
    if(n == 1 || n == 0)
        return 1;
    else
        return n * factorial(n-1);
}

int sumOfDigits(int x)
{
    if(x == 0)
        return 0;
    else
        return x % 10 + sumOfDigits(x / 10);
}

int findMin(int a[], int size)
{
    int min = a[0];
    for(int i=1; i<size; i++)  // Fix: change the loop condition to i < size
    {
        if(a[i] < min)
            min = a[i];
    }
      return min;
}

int DecToBin(int dec)
{
    if(dec == 0)
        return 0;
    else
        return dec % 2 + 10 * DecToBin(dec / 2);
}

double seriesSum(int n)
{
    if(n == 0)
        return 1;
    else
        return 1.0 / pow(2, n) + seriesSum(n-1);
}

int main()
{
    int fibo, fact, sum, MinSize, binary, series;

    cout << "Enter a number for Fibonacci: ";
    cin >> fibo;
    cout << "Fibonacci: " << fib(fibo) << endl;

    cout << "Enter a number for Factorial: ";
    cin >> fact;
    cout << "Factorial: " << factorial(fact) << endl;

    cout << "Enter a number for sum of digits: ";
    cin >> sum;
    cout << "Sum of the digits: " << sumOfDigits(sum) << endl;

    int a[10] = {10, 20, 30, 40, 5, 6, 7, 8, 90, 10};
    cout << "Minimum number: " << findMin(a, 10) << endl;

    cout << "Enter a number for Decimal to Binary conversion: ";
    cin >> binary;
    cout << "Binary is: " << DecToBin(binary) << endl;

    cout << "Enter a number for series sum: ";
    cin >> series;
    cout << "Sum of the series: " << seriesSum(series) << endl;

    return 0;
}
