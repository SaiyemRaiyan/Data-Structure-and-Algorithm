#include <iostream>
#include "sortedtype.cpp"
#include "timeStamp.cpp"
using namespace std;

template<class T>
void Print(SortedType<T> u)    // Print the list
{
    int length = u.LengthIs();
    T value;

    for(int i=0; i<length; i++)
    {
        u.GetNextItem(value);
        cout << value << " ";
    }
    cout << endl;
}
template <class T>
void Retrieve(SortedType<T> u, T value)  // Retrieve item
{
    bool b;
    u.RetrieveItem(value,b);

    if(b)
        cout << "Item is found" << endl;
    else
        cout << "Item is not found" << endl;

}
void checkFull(bool b)   // check if the list is full
{
    if(b)
        cout << "List is full" << endl;
    else
        cout << "List is not full" << endl;
}

int main()
{
    SortedType<int> st;    // Create an object of SortedType class

    cout << st.LengthIs() << endl;  // Print length of the list

    // Insert five items 5,7,4,2,1
    st.InsertItem(5);
    st.InsertItem(7);
    st.InsertItem(4);
    st.InsertItem(2);
    st.InsertItem(1);

    Print(st);    // Print the list

    Retrieve(st,6);  // Retrieve 6 and print whether found or not
    Retrieve(st,5);  // Retrieve 5 and print whether found or not

    checkFull(st.IsFull());  // Print if the list is full or not
    st.DeleteItem(1); // Delete 1

    Print(st);     // Print the list

    checkFull(st.IsFull());  // Print if the list is full or not

               // Create objects of timeStamp class with the given information
    timeStamp t1(15, 34, 23);
    timeStamp t2(13, 13, 02);
    timeStamp t3(43, 45, 12);
    timeStamp t4(25, 36, 17);
    timeStamp t5(52, 02, 20);

    SortedType<timeStamp> timeStampList;  // Create an object of SortedType class

          // Insert the objects in the list
    timeStampList.InsertItem(t1);
    timeStampList.InsertItem(t2);
    timeStampList.InsertItem(t3);
    timeStampList.InsertItem(t4);
    timeStampList.InsertItem(t5);

    timeStamp temp(25, 36, 17);   // Create a temporary object to search for the given time
    timeStampList.DeleteItem(temp); // Delete the item from the list

                        // Print the list
    for(int i=0; i<timeStampList.LengthIs(); i++)
    {
        timeStampList.GetNextItem(temp);
        cout << temp << endl;
    }

    return 0;
}
