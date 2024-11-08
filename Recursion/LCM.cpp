#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main()
{
    cout << "Please, Enter two number : ";
    int n1, n2, ans = 0;
    cin >> n1 >> n2;
    ans = lcm(n1, n2);
    cout << "The LCM is: " << ans;

    return 0;
}