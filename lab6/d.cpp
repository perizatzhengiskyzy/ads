#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<tuple<int,int,int,string>> dates(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int d = stoi(s.substr(0,2));
        int m = stoi(s.substr(3,2));
        int y = stoi(s.substr(6,4));
        dates[i] = make_tuple(y, m, d, s);
    }

    sort(dates.begin(), dates.end());

    for (auto &t : dates) cout << get<3>(t) << "\n";

    return 0;
}