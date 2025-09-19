#include <iostream>
#include <string>
#include <vector>
using namespace std;

string reduce(const string& s) {
    vector<char> st;
    st.reserve(s.size());
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        if (c == '#') {
            if (!st.empty()) st.pop_back();  
        } else {
            st.push_back(c);
        }
    }
    return string(st.begin(), st.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s1, s2;
    if (!(cin >> s1 >> s2)) return 0;

    cout << (reduce(s1) == reduce(s2) ? "Yes" : "No") << '\n';
    return 0;
}
