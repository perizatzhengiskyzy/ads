#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    vector<long long> a(n);
    vector<long long> power(n + 1, 1);

    for (int i = 1; i <= n; i++) {
        power[i] = power[i - 1] * 2;
    }

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string s = "";
    for (int i = 0; i < n; i++) {
        long long cur;
        if (i == 0)
            cur = a[i] + 97; 
        else
            cur = (a[i] - a[i - 1]) / power[i] + 97; 
        s += char(cur);
    }

    cout << s << '\n';
    return 0;
}
