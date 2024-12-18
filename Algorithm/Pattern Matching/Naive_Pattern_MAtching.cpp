#include <bits/stdc++.h>
using namespace std;

void naiveApproach(string pat, string text)
{
    int n = text.length();
    int m = pat.length();
    for (int i = 0; i < m; i++)
    {
        pat[i] = toupper(pat[i]);
    }
    for (int i = 0; i < n; i++)
    {
        text[i] = toupper(text[i]);
    }

    for (int i = 0; i <= n - m; i++)
    {
        bool match = true;
        for (int j = 0; j < m; j++)
        {
            if (text[i + j] != pat[j])
            {
                match = false;
                break;
            }
        }
        if (match)
        {
            cout << "Pattern found at index : " << i << endl;
        }
    }
};

int main()
{
    string text = "The quick brown fox jumps over the lazy ";
    string pattern = "The";

    naiveApproach(pattern, text);
    return 0;
}