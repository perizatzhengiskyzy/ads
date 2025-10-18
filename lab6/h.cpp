#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    char x;
    cin >> x;

    char balanced = arr[0];
    for (char c : arr) {
        if (c > x) {
            balanced = c;
            break;
        }
    }

    cout << balanced << "\n";

    return 0;
}