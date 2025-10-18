#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<string, string> orig;
    map<string, string> curr;

    for (int i = 0; i < n; i++) {
        string oldn, newn;
        cin >> oldn >> newn;
        string first;
        if (curr.count(oldn)) {
            first = curr[oldn];
            curr.erase(oldn);
        } else {
            first = oldn;
        }
        curr[newn] = first;
        orig[first] = newn;
    }

    cout << orig.size() << "\n";
    for (auto &p : orig)
        cout << p.first << " " << p.second << "\n";

    return 0;
}