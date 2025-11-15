#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(const string &pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);

    int len = 0;
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

string toLowerString(string s) {
    for (int i = 0; i < (int)s.size(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string p;
    int n;
    cin >> p >> n;

    vector<string> cities(n);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }

    string p_lower = toLowerString(p);

    int mx = 0;
    vector<pair<string, int> > match;

    // --- main loop (converted to C++98 style)
    for (int i = 0; i < n; i++) {
        string c = cities[i];
        string c_lower = toLowerString(c);

        string combined = c_lower + "#" + p_lower;
        vector<int> lps = computeLPS(combined);

        int m = lps[(int)lps.size() - 1];

        match.push_back(make_pair(c, m));
        if (m > mx) mx = m;
    }

    vector<string> res;
    for (int i = 0; i < (int)match.size(); i++) {
        string c = match[i].first;
        int m = match[i].second;

        if (m == mx && m > 0) {
            res.push_back(c);
        }
    }

    cout << res.size() << "\n";
    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << "\n";
    }

    return 0;
}
