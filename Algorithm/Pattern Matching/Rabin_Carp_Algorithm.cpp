#include<bits/stdc++.h>
using namespace std;

#define d 256
#define q 101

void search(const string& text, const string& pattern) {
 int n = text.length();
 int m = pattern.length();
 int p = 0;
 int t = 0;
 int h = 1;

 for (int i = 0; i < m - 1; i++) {
 h = (h * d) % q;
 }

 for (int i = 0; i < m; i++) {
 p = (d * p + pattern[i]) % q;
 t = (d * t + text[i]) % q;
 }

 for (int i = 0; i <= n - m; i++) {
 if (p == t) {
 bool match = true;
 for (int j = 0; j < m; j++) {
 if (text[i + j] != pattern[j]) {
 match = false;
 break;
 }
 }
 if (match) {
 cout << "Pattern found at index " << i << endl;
 }
 }

 if (i < n - m) {
 t = (d * (t - text[i] * h) + text[i + m]) % q;

 if (t < 0) {
 t += q;
 }
 }
 }
}

int main() {
 string text, pattern;

 cout << "Enter the text: ";
 getline(cin, text);

 cout << "Enter the pattern: ";
 getline(cin, pattern);

 search(text, pattern);

 return 0;
}
