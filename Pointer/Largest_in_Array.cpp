#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << " Enter the size of the array: ";
    cin >> n;
    //int a[n];

    int *p = new int[n];
    if (p == NULL)
    {
        printf("No memory allocated\n");
        return 0;
    }

    // Taking INPUT
    cout<< "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> *(p+i);
    }

    // Checking largest or not
    int largest = 0;
    for (int i = 0; i < n; i++)
    {

        if (largest <= *(p+i))
        {
            largest = *(p+i);
        }
    }

    cout << " The largest is : " << largest << endl;

    cout << " The Array is: ";
    for (int i = 0; i < n; i++)
    {

        cout << *(p+i) << " ";
    }

    // Deallocate the dynamically allocated memory
    delete[] p;
    return 0;
}