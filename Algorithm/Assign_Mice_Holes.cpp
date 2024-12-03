#include <bits/stdc++.h>
using namespace std;

int Max_Time(vector<int> mice, vector<int> hole, int n)
{
    int max = 0;
    int value = 0;

    for (int i = 0; i < n; i++)
    {
        value = abs(mice[i] - hole[i]);
        // cout << value << " ";
        if (max < value)
        {
            max = value;
        }
    }
    return max;
}

int main()
{
    vector<int> mice = {4, -4, 2};
    vector<int> hole = {4, 0, 5};
    int n = mice.size();

    sort(mice.begin(), mice.end());
    sort(hole.begin(), hole.end());

    int max = Max_Time(mice, hole, n);

    cout << "The maximum time is required to assign holes is: " << max << " ";

    return 0;
}
