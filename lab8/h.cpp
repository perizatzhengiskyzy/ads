#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod1 = 1000000007;
const ll mod2 = 1000000009;
const ll pw1  = 31;
const ll pw2  = 37;

int k;

pair<vector<ll>, vector<ll>> prefix_hash(const string &s, ll mod, ll pw) {
    int n = s.size();
    vector<ll> h(n + 1, 0), p(n + 1, 1);
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * pw + (s[i] - 'a' + 1)) % mod;
        p[i + 1] = (p[i] * pw) % mod;
    }
    return {h, p};
}

ll get_hash(const vector<ll> &h, const vector<ll> &p, int l, int r, ll mod) {
    ll res = (h[r] - h[l] * p[r - l]) % mod;
    if (res < 0) res += mod;
    return res;
}

string get_common_substring(vector<string> &v, int len) {
    if (len == 0) return "";

    auto hp1 = prefix_hash(v[1], mod1, pw1);
    auto hp2 = prefix_hash(v[1], mod2, pw2);

    vector<ll> h1 = hp1.first;
    vector<ll> p1 = hp1.second;
    vector<ll> h2 = hp2.first;
    vector<ll> p2 = hp2.second;

    unordered_set<uint64_t> common;

    for (int i = 0; i + len <= v[1].size(); i++) {
        ll x1 = get_hash(h1, p1, i, i + len, mod1);
        ll x2 = get_hash(h2, p2, i, i + len, mod2);
        uint64_t key = ((uint64_t)x1 << 32) ^ x2;
        common.insert(key);
    }

    for (int idx = 2; idx <= k; idx++) {
        auto hp3 = prefix_hash(v[idx], mod1, pw1);
        auto hp4 = prefix_hash(v[idx], mod2, pw2);

        vector<ll> h3 = hp3.first;
        vector<ll> p3 = hp3.second;
        vector<ll> h4 = hp4.first;
        vector<ll> p4 = hp4.second;

        unordered_set<uint64_t> cur;
        int n = v[idx].size();

        for (int i = 0; i + len <= n; i++) {
            ll x1 = get_hash(h3, p3, i, i + len, mod1);
            ll x2 = get_hash(h4, p4, i, i + len, mod2);
            uint64_t key = ((uint64_t)x1 << 32) ^ x2;
            cur.insert(key);
        }

        unordered_set<uint64_t> next;
        for (auto &x : common) {
            if (cur.count(x)) next.insert(x);
        }

        common.swap(next);
        if (common.empty()) return "";
    }

    auto hpx1 = prefix_hash(v[1], mod1, pw1);
    auto hpx2 = prefix_hash(v[1], mod2, pw2);

    vector<ll> ha1 = hpx1.first;
    vector<ll> pa1 = hpx1.second;
    vector<ll> ha2 = hpx2.first;
    vector<ll> pa2 = hpx2.second;

    int n = v[1].size();

    for (int i = 0; i + len <= n; i++) {
        ll x1 = get_hash(ha1, pa1, i, i + len, mod1);
        ll x2 = get_hash(ha2, pa2, i, i + len, mod2);
        uint64_t key = ((uint64_t)x1 << 32) ^ x2;
        if (common.count(key)) return v[1].substr(i, len);
    }

    return "";
}

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int left = 0;
    int right = INT_MAX;

    cin >> k;
    vector<string> v(k + 1);

    for (int i = 1; i <= k; i++) {
        cin >> v[i];
        right = min<int>(right, v[i].size());
    }

    string ans = "";

    while (left <= right) {
        int mid = (left + right) / 2;
        string temp = get_common_substring(v, mid);

        if (!temp.empty()) {
            ans = temp;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
