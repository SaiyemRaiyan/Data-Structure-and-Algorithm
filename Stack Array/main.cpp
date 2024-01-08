#include<iostream>
#include "stacktype.cpp"
using namespace std;

void checkEmpty(bool b) //Check if the stack is empty
{
    if(b)
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is not Empty" << endl;
}

void checkFull(bool b)  // Check if the list is full
{
    if(b)
        cout << "Stack is Full" << endl;
    else
        cout << "Stack is not Full" << endl;
}

void Print(StackType<int> stk)  //Print the list
{
    StackType<int>tem;

    while(!stk.IsEmpty())
    {
        tem.Push(stk.Top());
        stk.Pop();
    }

    while(!tem.IsEmpty())
    {
        stk.Push(tem.Top());
        cout << tem.Top() << " ";
        tem.Pop();
    }
    cout << endl;
}

int main()
{

    StackType<int> stk;     // Create a stack of integers

    checkEmpty(stk.IsEmpty());   // Check if the stack is empty or not

         // Push items
    stk.Push(5);
    stk.Push(7);
    stk.Push(4);
    stk.Push(2);

    checkEmpty(stk.IsEmpty());    // Check if the stack is empty or not

    checkFull(stk.IsFull());     // Check if the stack is full or not

    Print(stk);    // Print the values in the stack

    stk.Push(3);    // push 3

    Print(stk);     // Print the values in the stack

    checkFull(stk.IsFull());      // Check if the stack is full or not

               // Pop two items
    stk.Pop();
    stk.Pop();

    cout << stk.Top() << endl;    // Print top item


    StackType<char> parentheses;      // Create a stack of characters

    string str;   // String to take input from the user
    cin >> str;

    for(int i=0; str[i] != '\0'; i++)  // Loop until the end of string
    {
        char array_item = str[i];

        if(array_item == '(')
            parentheses.Push(array_item);

        try
        {
            if(array_item == ')')
                parentheses.Pop();
        }
           catch(EmptyStack)
        {
            cout << "Unbalanced" << endl;
            return 0;
        }
    }

    if(parentheses.IsEmpty())
        cout << "Balanced" << endl;
    else
        cout << "Not balanced" << endl;

    return 0;
}
