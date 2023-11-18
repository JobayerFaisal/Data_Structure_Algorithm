#include <bits/stdc++.h>
using namespace std;

bool checkParentheses(const string &exp)
{
    stack<char> PStack;

    for (char ch : exp)
    {
        if (ch == '(')
        {
            PStack.push(ch);
        }
        else if (ch == ')')
        {
            if (PStack.empty())
            {
                return false;
            }
            PStack.pop();
        }
    }

    return PStack.empty();
}

int main()
{
    string exp;
    cout << "Please, Enter an exp with parentheses: ";
    getline(cin, exp);

    bool umo = false;
    stack<int> umi;

    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(')
        {
            umo = true;
            umi.push(i);
        }
        else if (exp[i] == ')')
        {
            if (umo)
            {
                umo = false;
                umi.pop();
            }
            else
            {
                cout << "Closing parenthesis not matched" << endl;
                return 0;
            }
        }
    }

    if (umo)
    {
        int index = umi.top();
        cout << "Opening parentheses not ended at index " << index << endl;
    }
    else
    {
        cout << "All parentheses are matched." << endl;
    }

    return 0;
}