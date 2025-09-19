#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<long long> dq;
    char cmd;
    while (cin >> cmd) {
        if (cmd == '+') {
            long long x; cin >> x;
            dq.push_front(x);
        } else if (cmd == '-') {
            long long x; cin >> x;
            dq.push_back(x);
        } else if (cmd == '*') {
            if (dq.empty()) {
                cout << "error\n";
            } else {
                long long s = dq.front() + dq.back();
                cout << s << '\n';
                if (!dq.empty()) dq.pop_front();
                if (!dq.empty()) dq.pop_back();
            }
        } else if (cmd == '!') {
            break;
        }
    }
    return 0;
}
