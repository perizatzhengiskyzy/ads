#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int freq[26] = {0};
    for (char c : s) freq[c - 'a']++;

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < freq[i]; j++)
            cout << char('a' + i);

    cout << "\n";
    return 0;
}