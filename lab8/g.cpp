#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod1 = 1000000007;
const ll mod2 = 1000000009;
const ll pw1 = 31;
const ll pw2 = 37;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int q;
    cin >> s >> q;

    int n = s.size();

    auto hp1 = prefix_hash(s, mod1, pw1);
    auto hp2 = prefix_hash(s, mod2, pw2);

    vector<ll> h1 = hp1.first;
    vector<ll> p1 = hp1.second;

    vector<ll> h2 = hp2.first;
    vector<ll> p2 = hp2.second;

    unordered_map<uint64_t, int> mp;
    mp.reserve(n * 5);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            ll x1 = get_hash(h1, p1, i, j, mod1);
            ll x2 = get_hash(h2, p2, i, j, mod2);
            uint64_t key = ((uint64_t)x1 << 32) ^ (uint64_t)x2;
            mp[key]++;
        }
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;     
        
        ll x1 = get_hash(h1, p1, l, r, mod1);
        ll x2 = get_hash(h2, p2, l, r, mod2);

        uint64_t key = ((uint64_t)x1 << 32) ^ (uint64_t)x2;
        cout << mp[key] << "\n";
    }

    return 0;
}
