#include <bits/stdc++.h>
using namespace std;

void merge_all(double A[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1];
    int R[n2];

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
        if (L[p] >= R[q])
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

void merge_sort(double A[], double left, int right)
{
    int mid;
    if (left < right)
    {
        mid = (left + right - 1) / 2;

        merge_sort(A, left, mid);
        merge_sort(A, mid + 1, right);
        merge_all(A, left, mid, right);
    }
}

void printMax(double A[], double D[], int n)
{
    int count = 1;
    int max = 1;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] >= D[j])
        {
            count++;
            if (count > max)
                max = count;
        }
        else
        {
            count--;
            j++;
        }
    }
    cout << max;
}

int main()
{
    double A[] = {2.00, 2.10, 3.00, 3.20, 3.50, 5.00};
    double D[] = {2.30, 3.20, 3.40, 4.00, 4.30, 5.20};
    int n = sizeof(A) / sizeof(A[0]);

    merge_sort(A, 0, n - 1);
    merge_sort(D, 0, n - 1);

    cout << "Minimun Platform Required is : ";
    printMax(A, D, n);
    return 0;
}
