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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int n;
    cin >> s >> n;

    vector<long long> p(s.size() + 1);
    vector<long long> h = prefix_hash(s, p);
    string covered(s.size(), '0'); 

    for (int i = 0; i < n; i++) {
        string t;
        cin >> t;

    
        long long hash_t = 0;
        for (int j = 0; j < (int)t.size(); j++) {
            hash_t = (hash_t * P + (t[j] - 'a' + 1)) % MOD;
        }

        for (int j = 0; j + t.size() <= s.size(); j++) {
            long long current = get_hash(h, p, j, j + t.size());
            if (current == hash_t) {
                for (int k = j; k < j + t.size(); k++) {
                    covered[k] = '1';
                }
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < (int)covered.size(); i++) {
        if (covered[i] == '0') {
            ok = false;
            break;
        }
    }

    cout << (ok ? "YES\n" : "NO\n");
    return 0;
}
