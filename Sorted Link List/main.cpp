#include <iostream>
#include "sortedtype.cpp"
#include "timeStamp.cpp"
using namespace std;

template<class T>
void Print(SortedType<T> u)  // Print function
{
    int length = u.LengthIs();
         T value;
    for(int i = 0; i < length; i++)
    {
        u.GetNextItem(value);
        cout << value << endl;
    }
    cout << endl;
}

int main()
{

    SortedType<timeStamp> st;   // Create a list of objects of class "timeStamp"

    timeStamp t1(15,34,23);   // Insert 5 time values
    st.InsertItem(t1);
    timeStamp t2(13,13,02);
    st.InsertItem(t2);
    timeStamp t3(43,45,12);
    st.InsertItem(t3);
    timeStamp t4(25,36,17);
    st.InsertItem(t4);
    timeStamp t5(52,02,20);
    st.InsertItem(t5);

    timeStamp temp(25,36,17);   // Delete the timestamp "25  36  17"
    st.DeleteItem(temp);

    Print(st);     // Print the list again

    return 0;
}
