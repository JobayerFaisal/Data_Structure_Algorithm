#include <bits/stdc++.h>
using namespace std;

int partition(int A[], int left, int right)
{
    int p = A[right];
    int i = left;

    for (int j = left; j < right; j++)
    {
        if (A[j] < p)
        {
            swap(A[i], A[j]);
            i++;
        }
    }
    swap(A[i], A[right]);
    return i;
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

int main()
{
    int n = 6;
     cout << "Enter the size of the array: " ;
     cin >> n ;
     int A[n] ;
    //int A[] = {12, 18, 1, 5, 6, 7};

     cout << "Enter the array: " ;
    for (int i = 0; i < n; i++)
    {
         cin >> A[i] ;
    }

    int f = 0;
    int l = n - 1;
    quick_sort(A, 0, l);

    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}