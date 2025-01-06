#include <bits/stdc++.h>
using namespace std;

void LC_Str(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    int DP[m + 1][n + 1];


    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            DP[i][j] = 0;
        }
    }

    int maxLen = 0;  
    int endIndex = 0;  


    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {  
                DP[i][j] = DP[i - 1][j - 1] + 1;
                if (DP[i][j] > maxLen) {
                    maxLen = DP[i][j];
                    endIndex = i - 1;  
                }
            } else {
                DP[i][j] = 0;  
            }
        }
    }

    cout << "\nLength of Longest Common Substring is: " << maxLen << endl;

    cout << "\nLongest Common Substring is: ";
    if (maxLen > 0) {
        cout << s1.substr(endIndex - maxLen + 1, maxLen) << "\n";
    } else {
        cout << "No Common Substring\n";
    }

/*    cout << "\nDP Table:\n";
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            cout << DP[i][j] << " ";
        }
        cout << "\n";
    }*/

}



int main() {
    string s1 = "ABCDGH";
    string s2 = "ACDGHR";

    LC_Str(s1, s2);
    return 0;
}
