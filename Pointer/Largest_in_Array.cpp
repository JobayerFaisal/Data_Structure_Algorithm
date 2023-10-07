#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cout << " Enter the size of the array: ";
    cin >> n;
    int a[n];

    int *p = new int[n];

    // Taking INPUT
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Checking largest or not
    int largest = 0;
    for (int i = 0; i < n; i++)
    {

        if (largest <= a[i])
        {
            largest = a[i];
        }
    }

    cout << " The largest is : " << largest << endl;

    cout << " The Array is: ";
    for (int i = 0; i < n; i++)
    {

        cout << a[i] << " ";
    }

        // Deallocate the dynamically allocated memory
    delete[] p;
    return 0;
}