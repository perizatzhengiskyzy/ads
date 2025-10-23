#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    multiset<int> s(a.begin(), a.end());
    vector<int> res;
    for (int x : b) {
        auto it = s.find(x);
        if (it != s.end()) {
            res.push_back(x);
            s.erase(it);
        }
    }

    sort(res.begin(), res.end());

    for (int i = 0; i < (int)res.size(); i++) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << "\n";
}