#include <iostream>
#include "unsortedtype.h"
#include "unsortedtype.cpp"
using namespace std;

int main()
{
    UnsortedType<int> list1, list2, merged;      // Create three lists

    int n, v;
    cin>>n;    // Take inputs for list1
    for(int i=0; i<n; i++)
    {
        cin >> v;
        list1.InsertItem(v);
    }

    cin >> n;            // Take inputs for list2

    for(int i=0; i<n; i++)
    {
        cin >> v;
        list2.InsertItem(v);
    }

    int v1, v2, index1, index2;

    index1 = list1.LengthIs();
    index2 = list2.LengthIs();
    list1.GetNextItem(v1);
    list2.GetNextItem(v);

    while (index1>0 && index2>0) // Merging the lists
    {
        if(v1>v2)
        {
            merged.InsertItem(v1);
            index1--;
            if (index1 > 0)
                list1.GetNextItem(v1);
        }
            else if (v2 > v1)
        {
            merged.InsertItem(v2);
            index2--;
               if(index2 > 0)
                   list2.GetNextItem(v2);
        }
           else
        {
            merged.InsertItem(v1);
            merged.InsertItem(v);
                index1--;
                index2--;
            if(index1 > 0)
                list1.GetNextItem(v);
            if(index2 > 0)
                list2.GetNextItem(v2);
        }
    }

    while(index1 > 0)       // Add the remaining elements of list1
    {
        merged.InsertItem(v1);
        index1--;
             if(index1 > 0)
             list1.GetNextItem(v1);
    }

    while(index2 > 0)  // Adding the remaining elements of list2
    {
        merged.InsertItem(v2);
        index2--;
        if(index2 > 0)
            list2.GetNextItem(v2);
    }

    int value_merged, index_merged;
    index_merged = merged.LengthIs()-1;

    while(index_merged >= 0)    // Print the merged list
    {
        merged.GetNextItem(value_merged);
        cout << value_merged << ' ';
        index_merged--;
    }
        cout << endl;

    return 0;
}
