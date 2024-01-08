#include <iostream>
#include "quetype.cpp"
using namespace std;

void checkEmpty(bool b) //Check if the queue is empty or not
{
    if(b)
        cout << "Queue is Empty" << endl;
    else
        cout << "Queue is not Empty" << endl;
}

void checkFull(bool b)  //Check if the list is full or not
{
    if(b)
        cout << "Queue is full" << endl;
    else
        cout << "Queue is not full" << endl;
}

void Print(QueType<int> &queType)  //Print the list
{
    QueType<int> temp;

    while(!queType.IsEmpty())
    {
        int value;
        queType.Dequeue(value);
        cout << value << " ";
        temp.Enqueue(value);
    }
    cout << endl;

    while(!temp.IsEmpty())
    {
        int value;
        temp.Dequeue(value);
        queType.Enqueue(value);
    }
}

int main()
{
    QueType<int> queue(5);    //Create a queue of integer size 5

    checkEmpty(queue.IsEmpty());   //Print if the queue is empty or not

                // Enqueue four items 5,7,4,2
    queue.Enqueue(5);
    queue.Enqueue(7);
    queue.Enqueue(4);
    queue.Enqueue(2);

    checkEmpty(queue.IsEmpty()); //Print if the queue is empty or not
    checkFull(queue.IsFull());  //Print if the queue is full or not

    queue.Enqueue(6);  // Enqueue item 6

    Print(queue); //Print the values in the queue

    checkFull(queue.IsFull());  //Print if the queue is full or not

    if(!queue.IsFull())
        queue.Enqueue(8);   // Enqueue item 8
    else
        cout << "Queue Overflow" << endl;

    int dq;
          // Dequeue two items
    queue.Dequeue(dq);
    queue.Dequeue(dq);

    Print(queue);   //Print the values in the queue

          // Dequeue three items
    queue.Dequeue(dq);
    queue.Dequeue(dq);
    queue.Dequeue(dq);

    checkEmpty(queue.IsEmpty());  //Print if the queue is empty or not

    if(!queue.IsEmpty())
        queue.Dequeue(dq);   // Dequeue an item
    else
        cout << "Queue Underflow" << endl;


    QueType<string> binary; //Create an empty queue
    int num;
    string S;
    cin>>num;

    binary.Enqueue("1");  //Enqueue the first binary number "1"

    while(num--)  //For print "n" binary numbers
    {
        binary.Dequeue(S);  // Dequeue and print the value
        string s1 = S;
        cout<<s1<<endl;

             string s2 = s1;
        binary.Enqueue(s1.append("0"));  // Append "0" at the dequeued value and enqueue it
        binary.Enqueue(s2.append("1"));  // Append "1" at the dequeued value and enqueue it
    }
    return 0;
}
