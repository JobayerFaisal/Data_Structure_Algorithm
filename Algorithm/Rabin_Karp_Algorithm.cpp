#include <bits/stdc++.h>
using namespace std;
#define d 26

void rabinKarp(string pattern, string text, int pr)
{
    int m = pattern.length();
    int n = text.length();
    int i, j;
    // Hash value for pattern
    int hfp = 0;
    // Hash value for text
    int hft = 0;
    int h = 1;

    // The value of h would be "pow(d, m-1)%pr"
    for (i = 0; i < m - 1; i++)
        h = (h * d)%pr ;

    // Calculate the hash value of pattern and first window
    // of text
    for (i = 0; i < m; i++) {
        hfp = (d * hfp + pattern[i]) % pr;
        hft = (d * hft + text[i]) % pr;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= n - m; i++) {
        // Check the hash values of current window of text
        // and pattern
        if (hfp == hft) {
            // Check for characters one by one
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                cout << "Index: " << i
                     << endl;
        }

        // Calculate hash value for next window of text
        if (i < n - m) {
            hft = (d * (hft - text[i] * h) + text[i + m]) % pr;
            if (hft < 0)
                hft = (hft + pr);
        }
    }
}

int main()
{
    string text = "AABAABA";
    string pattern = "BA";
    int pr = 2381;

    rabinKarp(pattern, text, pr);
    return 0;
}