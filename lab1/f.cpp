#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> primes;
    for (int x = 2; (int)primes.size() < n; ++x) {
        bool ok = true;
        for (int p : primes) {
            if (1LL * p * p > x) break;
            if (x % p == 0) { ok = false; break; }
        }
        if (ok) primes.push_back(x);
    }

    cout << primes[n - 1];
    return 0;
}
