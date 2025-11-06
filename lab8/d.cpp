#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const long long P = 31;

vector<long long> prefix_hash(const string &s, vector<long long> &p) {
    int n = s.size();
    vector<long long> h(n + 1, 0);
    p[0] = 1;
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * P + (s[i] - 'a' + 1)) % MOD;
        p[i + 1] = (p[i] * P) % MOD;
    }
    return h;
}

long long get_hash(const vector<long long> &h, const vector<long long> &p, int l, int r) {
    long long res = (h[r] - h[l] * p[r - l]) % MOD;
    if (res < 0) res += MOD;
    return res;
}

void solve(int n) {
    vector<string> patterns(n + 1);
    vector<long long> count_patterns(n + 1, 0);
    long long max_count = 0;

    for (int i = 1; i <= n; i++) {
        cin >> patterns[i];
    }

    string text;
    cin >> text;

    vector<long long> p(text.size() + 1);
    vector<long long> h = prefix_hash(text, p);

    for (int i = 1; i <= n; i++) {
        const string &t = patterns[i];
        long long hash_t = 0;

        for (int j = 0; j < (int)t.size(); j++) {
            hash_t = (hash_t * P + (t[j] - 'a' + 1)) % MOD;
        }

        long long cnt = 0;
        for (int j = 0; j + t.size() <= text.size(); j++) {
            long long sub_hash = get_hash(h, p, j, j + t.size());
            if (sub_hash == hash_t) cnt++;
        }

        count_patterns[i] = cnt;
        max_count = max(max_count, cnt);
    }

    cout << max_count << '\n';
    for (int i = 1; i <= n; i++) {
        if (count_patterns[i] == max_count) {
            cout << patterns[i] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        solve(n);
    }

    return 0;
}
