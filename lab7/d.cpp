#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string,double> gpa = {
        {"A+",4.00},{"A",3.75},
        {"B+",3.50},{"B",3.00},
        {"C+",2.50},{"C",2.00},
        {"D+",1.50},{"D",1.00},
        {"F",0.00}
    };

    int n; 
    cin >> n;

    struct S { string last, first; double g; };
    vector<S> v; v.reserve(n);

    for (int i = 0; i < n; ++i) {
        string last, first; int m;
        cin >> last >> first >> m;
        double sum = 0, cr = 0;
        for (int j = 0; j < m; ++j) {
            string gr; int c;
            cin >> gr >> c;
            sum += gpa[gr] * c;
            cr  += c;
        }
        v.push_back({last, first, sum / cr});
    }

    sort(v.begin(), v.end(), [](const S& a, const S& b){
        if (fabs(a.g - b.g) > 1e-9) return a.g < b.g;   // возрастание
        if (a.last != b.last) return a.last < b.last;
        return a.first < b.first;
    });

    cout.setf(ios::fixed); cout << setprecision(3);
    for (auto &x : v) cout << x.last << ' ' << x.first << ' ' << x.g << '\n';
}