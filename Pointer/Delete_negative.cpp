#include <bits/stdc++.h>
using namespace std;

void printArray(int *arr, int size)
{ // Function to print an array
    for (int i = 0; i < size; i++)
        cout << *(arr + i) << " ";
    cout << endl;
}

void delElement(int *a, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(a + i) > 0)
        {
            *(a + count) = *(a + i);
            count++;
        }
    }

    printf("After deletation, The elements of the array is:");

    for (int i = 0; i < count; i++)
    {
        cout << *(a + i);
    }
}

int main()
{

    int n;
    cout << "Please, Enter the size of the array: ";
    cin >> n;

    int *p = new int[n];
    if (p == NULL)
    {
        printf("No memory allocated\n");
        return 0;
    }

    // Taking INPUT
    cout << "Please, Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> *(p + i);
    }

    printArray(p, n);

    delElement(p, n);

    delete[] p; // Deallocate the dynamically allocated memory
    return 0;
}
