#include<iostream>
#include "unsortedtype.cpp"
#include "studentInfo.cpp"

using namespace std;

template<class T>
  //  Print the list
void Print(UnsortedType<T> u)
{
    int length = u.LengthIs();
    T value;

    for (int i=0; i<length; i++)
    {
        u.GetNextItem(value);
        cout << value << " ";
    }
    cout << endl;
}

template<class T>
// Retrieve an item
void Retrieve(UnsortedType<T> u, T value)
{
    bool b;
    u.RetrieveItem(value, b);

    if(b)
        cout << "Item is found" << endl;
    else
        cout << "Item is not found" << endl;

}
    // check if the list is full
void checkFull(bool b)
{
    if (b)
        cout << "List is full" << endl;
    else
        cout << "List is not full" << endl;
}

int main()
{
      // Create an object of UnsortedType class and inserting 5,7,6,9

    UnsortedType<int> ut;
    ut.InsertItem(5);
    ut.InsertItem(7);
    ut.InsertItem(6);
    ut.InsertItem(9);

    Print(ut);  // Print the list

    cout << ut.LengthIs() << endl;   // Print the length of the list
    ut.InsertItem(1);               // Insert one item in the list
    Print(ut);                     // Print the list

    Retrieve(ut, 4);             // Retrieving 4,5,9,10 in the list and print whether the item is found or not
    Retrieve(ut, 5);
    Retrieve(ut, 9);
    Retrieve(ut, 10);

    checkFull(ut.IsFull());     // Print whether the list is full or not
    ut.DeleteItem(5);           // Delete 5 from the list
    checkFull(ut.IsFull());     // Print whether the list is full or not
    ut.DeleteItem(1);          // Delete 1 from the list

    Print(ut);               // Print the list

    ut.DeleteItem(6);        // Delete 6 from the list

    Print(ut);        // Print the list


    studentInfo
            s1(15234, "Jon", 2.6),  // Create objects of studentInfo class
            s2(13732, "Tyrion", 3.9),
            s3(13569, "Sandor", 1.2),
            s4(15467, "Ramsey", 3.1),
            s5(16285, "Arya", 3.1);

    UnsortedType<studentInfo> students;  // Create an object of UnsortedType class and inserting the objects
    students.InsertItem(s1);
    students.InsertItem(s2);
    students.InsertItem(s3);
    students.InsertItem(s4);
    students.InsertItem(s5);

    studentInfo tem = 15467;   // Create a temporary object to search for 15467
    students.DeleteItem(tem);    // Delete the item from the list

    tem = 13569;        // Create a temporary object to search for 13569

    Retrieve(students, tem);    // Retrieve the item from the list
    cout << tem << endl;     // Print the item

                  // Print the list
    for (int i=0; i<students.LengthIs(); i++)
    {
        students.GetNextItem(tem);
        cout << tem;
    }

    return 0;
}
