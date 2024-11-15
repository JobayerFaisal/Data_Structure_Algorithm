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

int binary_search(int A[], int first, int last, int item)
{
    if (first > last)
    {
        return -1;
    }

    int mid = first + (last - first) / 2;

    if (A[mid] == item)
    {
        return mid;
    }
    else if (A[mid] > item)
    {
        return binary_search(A, first, mid - 1, item);
    }
    else
    {
        return binary_search(A, mid + 1, last, item);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int A[n];

    cout << "Enter the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    merge_sort(A, 0, n - 1);

    int search_item;
    cout << "Enter the item to search: ";
    cin >> search_item;

    int index = binary_search(A, 0, n - 1, search_item);

    if (index == -1)
    {
        cout << "Not Found." << endl;
    }
    else
    {
        cout << "The Index of the number is: " << index << endl;
    }

    return 0;
}
