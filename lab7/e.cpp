#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    sort(a.begin(), a.end(), [](const vector<int> &x, const vector<int> &y) {
        int sx = accumulate(x.begin(), x.end(), 0);
        int sy = accumulate(y.begin(), y.end(), 0);
        if (sx != sy) return sx > sy;
        return x < y;
    });

    for (auto &row : a) {
        for (int i = 0; i < m; i++)
            cout << row[i] << " ";
        cout << "\n";
    }
}