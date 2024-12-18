#include <bits/stdc++.h>
using namespace std;

int partition(int A[], int left, int right)
{
    int p = A[left];
    int j = right;

    for (int i = right; i > left; i--)
    {
        if (A[i] <= p)
        {
            swap(A[i], A[j]);
            j--;
        }
    }
    swap(A[j], A[left]);
    return j;
}

void quick_sort(int A[], int left, int right)
{
    if (left < right)
    {
        int pivot = partition(A, left, right);

        quick_sort(A, left, pivot - 1);
        quick_sort(A, pivot + 1, right);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n = 6;

    int A[] = {12, 18, 1, 5, 6, 7};

    int f = 0;
    int l = n - 1;
    quick_sort(A, 0, l);

    cout << "The Descending order of the array is: ";
    printArray(A,n) ;

    return 0;
}