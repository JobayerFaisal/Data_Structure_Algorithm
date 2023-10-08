#include <bits/stdc++.h>
using namespace std;


void bubbleSort(int *arr, int n)        // A function to implement bubble sort
{
    for (int i = 0; i < n - 1; i++)     // Last i elements are already
        for (int j = i + 1; j < n; j++)
        {
            if (*(arr + i) > *(arr + j))
            {
                int temp = *(arr + i);      // swaping two numbers
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
}

void printArray(int *arr, int size){         // Function to print an array
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << " Enter the size of the array: ";
    cin >> n;

    int *p = new int[n];
    if (p == NULL)
    {
        printf("No memory allocated\n");
        return 0;
    }

    cout << " Enter the elements of the array: ";   // Taking INPUT for the Array

    for (int i = 0; i < n; i++)
    {
        cin >> *(p + i);
    }

    cout << "The Array before sorting is: ";    // Printing the Unsorted array
    printArray(p, n);

    bubbleSort(p, n);
    cout << "The Sorted array is : ";
    printArray(p, n);

    delete[] p;
    return 0;
}
