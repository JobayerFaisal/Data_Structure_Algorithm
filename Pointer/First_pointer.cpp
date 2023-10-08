// Your First C++ Program

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a, b, c;
    int *p = 0; // It is better to set the pointer value NULL. It helps
    cout << " Enter Numbers : ";
    cin >> a >> b;

    c = a + b;
    p = &c;

    cout << "The Sum is :" << *p << endl;
    cout << "The Address of Sum :" << p << endl;
    cout << "The Next Address of Sum is :" << p + 1 << endl; // The output will show mainly P+4, as it takes integer as input as well as 4 bits.

    return 0;
}
