#include <bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    int c;
    if (b == 0)
    {
        return 1;
    }

    else
    {
        c = a * power(a, b - 1);
        return c;
    }
}

int main()
{
    cout << "Please, Enter the number and the Power : ";
    int n, p, ans = 0;
    cin >> n >> p;
    ans = power(n, p);
    cout << "The answer is: " << ans;

    return 0;
}