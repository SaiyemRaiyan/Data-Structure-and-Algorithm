#include<iostream>
#include "QueType.cpp"

using namespace std;

int main()
{
    int n;
    QueType<int> coins;

    cout<<"Please enter number of coin types: ";
    cin>>n;
    int coin_types=n;

    cout<<"Please enter value on coin type: ";
    for(int i=0; i<coin_types; i++)
    {
        cin>>n;
        coins.Enqueue(n);
    }

    cout<<"Please enter total amount: ";
    cin>>n;

    int last_element;

    for(int i=0; i<coin_types; i++)
    {
        coins.Dequeue(last_element);
    }

    bool iter = true;
    int multiple = 0;
    while(iter)
    {
        multiple++;
        if(last_element * multiple >= n)
        {
            iter = false;
        }
    }

    cout<<multiple<<" coins are needed.";

    //3 2 3 5 200 - last set of input values
    //output is 40
    //largest coin type is 5
    //5 * 40 = 200

    //Inside while loop, lines 32 to 37 the loop runs 40 times (multiple = 40)
    //until iter becomes false when (5*40 >= 200) inside if

    return 0;
}
