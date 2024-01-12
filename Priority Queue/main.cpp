#include <iostream>
#include "pqtype.cpp"
using namespace std;

void checkEmpty(bool b)  //Check if the queue is empty
{
    if(b)
        cout << "Queue is empty" << endl;
    else
        cout << "Queue is not empty" << endl;
}

int main()
{
    PQType<int> pq(15);    //Create a "PQType" object with size 15

    checkEmpty(pq.IsEmpty());    //Print if the queue is empty or not

    for(int i=0; i<10; i++)    // Insert ten items, in the order they appear
    {
        int n;
        cin>>n;
        pq.Enqueue(n);
    }
    checkEmpty(pq.IsEmpty());   //This Print if the queue is empty or not

    int dqvalue;
    pq.Dequeue(dqvalue);  //Dequeue one element and print the dequeued value
    cout<< dqvalue <<endl;

    pq.Dequeue(dqvalue);  // Dequeue one element and print the dequeued value
    cout<< dqvalue <<endl;


    //Maximum number of candies
    int NBags, Kmin, sum=0;   //Here, I define NBags means how many bags
    cin >> NBags >> Kmin;

    PQType<int> bCandies(NBags); //Here, I define bCandies means bags of candies

    for(int i=0; i<NBags; i++)
    {
        int temp;
        cin >> temp;
        bCandies.Enqueue(temp);
    }


    for(int i=Kmin; i>0; i--)  //Kmin means number in each minutes
    {
        bCandies.Dequeue(dqvalue);
        sum = sum+dqvalue;
        bCandies.Enqueue(dqvalue/2);
    }

    cout<< sum <<endl;

    return 0;
}
