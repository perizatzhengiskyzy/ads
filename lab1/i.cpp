#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    string s;
    if (!(cin >> n >> s)) return 0;

    queue<int> QS, QK;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'S') QS.push(i);
        else QK.push(i);
    }

    while (!QS.empty() && !QK.empty()) {
        int i = QS.front(); QS.pop();
        int j = QK.front(); QK.pop();
        if (i < j) {                 
            QS.push(i + n);
        } else {                     
            QK.push(j + n);
        }
    }

    cout << (QS.empty() ? "KATSURAGI" : "SAKAYANAGI");
    return 0;
}
