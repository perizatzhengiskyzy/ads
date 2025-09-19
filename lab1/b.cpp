#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    if (!(cin >> N)) return 0;

    vector<long long> st;
    st.reserve(N);

    for (int i = 0; i < N; ++i) {
        long long x; 
        cin >> x;

      
        while (!st.empty() && st.back() > x) st.pop_back();

        if (st.empty()) cout << -1;
        else            cout << st.back();

        if (i + 1 < N) cout << ' ';
        st.push_back(x);
    }
    cout << '\n';
    return 0;
}
