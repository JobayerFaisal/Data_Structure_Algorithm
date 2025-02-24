#include <bits/stdc++.h>
using namespace std;

void LIS(int arr[], int n)
{
    int DP[n];
    int parent[n];

    for (int i = 0; i < n; i++)
    {
        DP[i] = 1;
        parent[i] = -1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && DP[i] < DP[j] + 1)
            {
                DP[i] = DP[j] + 1;
                parent[i] = j;
            }
        }
    }


    cout<< "DP TABLE: " << endl; 
    for (int i = 0; i < n; i++)
    {
        cout<< DP[i] << " "; 
    }

    cout<< endl; 
    int maxLength = 0, lastIndex = 0;
    for (int i = 0; i < n; i++)
    {
        if (DP[i] > maxLength)
        {
            maxLength = DP[i];
            lastIndex = i;
        }
    }

    vector<int> lis;
    while (lastIndex != -1)
    {
        lis.push_back(arr[lastIndex]);
        lastIndex = parent[lastIndex];
    }
    reverse(lis.begin(), lis.end());

    cout << "Length of Longest Increasing Subsequence is : " << maxLength << endl;
    cout << "Longest Increasing Subsequence: ";
    for (int x : lis)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {0,1,0,3,2,3};



    int n = sizeof(arr) / sizeof(arr[0]);
    LIS(arr, n);
    return 0;
}
