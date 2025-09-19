#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;          
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0) return false;     
    for (int i = 3; i * 1LL * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    cin >> a;
    cout << (isPrime(a) ? "YES" : "NO");
    return 0;
}
