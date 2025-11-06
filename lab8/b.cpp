#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

const long long MOD = 1e9 + 7;
const long long PW = 31;

vector<long long> prefix_hash(const string &s, vector<long long> &p){
    int n = s.size();
    vector<long long> h(n + 1, 0);
    p[0] = 1;

    for(int i = 0; i < n; i++){
        h[i + 1] = (h[i] * PW + (s[i] - 'a' + 1)) % MOD;
        p[i + 1] = (p[i] * PW) % MOD;
    }
    return h;
}

long long get_hash(const vector<long long> &h,const vector<long long> &p, int l,int r){
    long long res = (h[r] - h[l] * p[r - l]) % MOD;
    if(res < 0) res += MOD;
    return res;
}



int main(){

    return 0;
}