#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    long long min_diff = LLONG_MAX;
    for (int i = 0; i < n - 1; i++) {
        min_diff = min(min_diff, a[i + 1] - a[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] - a[i] == min_diff)
            cout << a[i] << " " << a[i + 1] << " ";
    }

    cout << "\n";
    return 0;
}