#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    for (int j = 0; j < m; j++) {
        vector<int> col(n);
        for (int i = 0; i < n; i++)
            col[i] = mat[i][j];
        sort(col.rbegin(), col.rend());
        for (int i = 0; i < n; i++)
            mat[i][j] = col[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }

    return 0;
}