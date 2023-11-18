#include <bits/stdc++.h>
using namespace std;

const int MAX = 5;

int q1[MAX], q2[MAX], f1 = -1, r1 = -1, f2 = -1, r2 = -1;

void enq(int q[], int *f, int *r, int val)
{
    if (*r == MAX - 1)
        cout << "The queue is full and so cannot insert" << endl;
    else if (*f == -1 && *r == -1)
        *f = *r = 0;
    else
        *r = *r + 1;
    q[*r] = val;
}

void display(int q[], int *f, int *r)
{
    int i;
    if (*f == -1)
        cout << "The queue is empty " << endl;
    else
    {
        for (i = *f; i <= *r; i++)
            cout << q[i] << " ";
    }
}
int main()
{
    int i, val;

    cout << "Please, enter 5 value : ";
    for (i = 0; i < MAX; i++)
    {

        cin >> val;
        enq(q1, &f1, &r1, val);
    }

    cout << "The elements in queue 1 are : ";
    display(q1, &f1, &r1);
    for (i = f1; i <= r1; i++)
        enq(q2, &f2, &r2, q1[i]);
    cout << "\nThe elements in queue 2 are : ";
    display(q2, &f2, &r2);
}