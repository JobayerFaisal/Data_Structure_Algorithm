#include <bits/stdc++.h>
using namespace std;

void Activities(int s[], int f[], int n)
{
    int i, j;
    j = 0;
    int count = 1;

    for (i = 1; i < n; i++)
    {
        if (s[i] >= f[j])
        {
            count++;
            j = i;
        }
    }

    cout << "Maximum Number of activities is: ";
    cout << count;
}

int main()
{
    int s[] = {10, 21, 25};
    int f[] = {20, 25, 35};
    int n = sizeof(s) / sizeof(s[0]);

    Activities(s, f, n);
    return 0;
}
