#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> primes;
    int x = 2;

    while ((int)primes.size() < n) {
        bool ok = true;
        for (int p : primes) {
            if (1LL * p * p > x) break;
            if (x % p == 0) { ok = false; break; }
        }
        if (ok) primes.push_back(x);
        ++x;
    }
    int k = primes[n - 1];        

    while ((int)primes.size() < k) {
        bool ok = true;
        for (int p : primes) {
            if (1LL * p * p > x) break;
            if (x % p == 0) { ok = false; break; }
        }
        if (ok) primes.push_back(x);
        ++x;
    }

    cout << primes[k - 1];
    return 0;
}
