#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> res;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] < b[j]) res.push_back(a[i++]);
        else res.push_back(b[j++]);
    }
    while (i < n) res.push_back(a[i++]);
    while (j < m) res.push_back(b[j++]);

    for (int k = 0; k < (int)res.size(); k++) {
        if (k) cout << " ";
        cout << res[k];
    }
    cout << "\n";
}