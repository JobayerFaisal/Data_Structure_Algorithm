#include <bits/stdc++.h>
using namespace std;

void merge_all(int A[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = A[mid + 1 + i];
    }

    int p = 0, q = 0, r = left;

    while (p < n1 && q < n2)
    {
        if (L[p] <= R[q])
        {
            A[r] = L[p];
            p++;
        }
        else
        {
            A[r] = R[q];
            q++;
        }
        r++;
    }

    while (p < n1)
    {
        A[r] = L[p];
        r++;
        p++;
    }

    while (q < n2)
    {
        A[r] = R[q];
        r++;
        q++;
    }
}

void merge_sort(int A[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge_all(A, left, mid, right);
    }
}

int main()
{
    int n = 6;
    cout << "Enter the size of the array: ";
    cin >> n;
    int A[n];
    // int A[] = { 12, 12, 12, 5, 6, 7 };

    cout << "Enter the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    int f = 0;
    int l = n - 1;
    merge_sort(A, 0, n - 1);

    cout << "The sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}