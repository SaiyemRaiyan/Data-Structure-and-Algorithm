#include<iostream>
#include "stacktype.cpp"
using namespace std;

// Function to check if the stack is empty
void checkEmpty(bool b)
{
    if (b)
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is not Empty" << endl;
}

// Function to check if the stack is full
void checkFull(bool b)
{
    if (b)
        cout << "Stack is Full" << endl;
    else
        cout << "Stack is not Full" << endl;
}

// Function to check if parentheses are balanced
bool areParenthesesBalanced(string str)
{
    StackType<char> parentheses; // Create a stack of characters

    for(int i=0; str[i] != '\0'; i++) // Loop until the end of string
    {
        char array_item = str[i];

        // Push opening parentheses onto the stack
        if(array_item == '(' || array_item == '{' || array_item == '[')
            parentheses.Push(array_item);

        // Pop corresponding opening parentheses when closing parentheses are encountered
        try
        {
            if(array_item == ')')
            {
                if(parentheses.Top() == '(')
                    parentheses.Pop();
                else
                    return false; // Unbalanced
            }
            else if (array_item == '}')
            {
                if(parentheses.Top() == '{')
                    parentheses.Pop();
                else
                    return false; // Unbalanced
            }
            else if(array_item == ']')
            {
                if (parentheses.Top() == '[')
                    parentheses.Pop();
                else
                    return false; // Unbalanced
            }
        }
        catch (EmptyStack)
        {
            return false; // Unbalanced
        }
    }

    // If the stack is empty, the parentheses are balanced
    return parentheses.IsEmpty();
}

int main()
{
    string str;
    cin >> str;

    if(areParenthesesBalanced(str))
        cout << "Balanced" << endl;
    else
        cout << "Not balanced" << endl;

    return 0;
}
