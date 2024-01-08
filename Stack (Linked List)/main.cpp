#include<iostream>
#include "stacktype.cpp"
using namespace std;

int priority(char ch)  //It returns the priority of the operator
{
    int n=0;
    if(ch == '+')
        n = 1;
    else if (ch == '-')
        n = 2;
    else if (ch == '*')
        n = 3;
    else if (ch == '/')
        n = 4;

    return n;
}

int main()
{
    string input, postfix;
    cin >> input;   // Take input from user

    // Convert infix to postfix
    StackType<char> st;
    for(char i: input)
    {
        if(i == ' ')   //ignore spaces
            continue;

        if(isdigit(i))  //If it is a digit, add it to the postfix
            postfix += i;

        else
        {
            if(i == '(' || i == ')')
            {
                if(i == '(')    //If it is an opening bracket
                    st.Push(i);

                else
                {
                    while(!st.IsEmpty() && st.Top() != '(')  //If it is a closing bracket, pop all the operators from the stack
                    {
                        postfix = postfix + " " + st.Top();
                        st.Pop();
                    }

                    if(st.IsEmpty()) // if the stack is empty, the input is invalid
                    {
                        cout << "Invalid input" << endl;
                        return 0;
                    }
                    st.Pop();                     // pop the opening bracket
                }
                continue;
            }

            //Pop all the operators from the stack that have higher priority than the current operator
            while(!st.IsEmpty() && st.Top() != '(' && priority(st.Top()) > priority(i))
            {
                postfix = postfix + " " + st.Top();
                st.Pop();
            }
            postfix = postfix + " ";
            st.Push(i);  //Push the current operator to the stack
        }
    }

    while(!st.IsEmpty())  //Pop all the remaining operators from the stack
    {
        if (st.Top() == '(')
        {
            cout << "Invalid input" << endl;
            return 0;
        }
        postfix = postfix + " " + st.Top();
        st.Pop();
    }
}

