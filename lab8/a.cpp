#include <bits/stdc++.h>
#include <string>
#include <unordered_set>

using namespace std;

long long MOD = 1e9 + 7;
string get_hash(const string &s){
    long long h = 0;
    long long power = 1;

    for (int i = 0; i < s.size(); i++){
        char c = s[i];
        h = (h + ((c - 47) * power) % MOD) % MOD ;
        power = (power * 11) % MOD;
    }
    return to_string(h);
}

int main(){
    int n;
    cin >> n;

    vector<string> all_values;
    unordered_set<string> all_set;

    for(int i = 0; i < 2 * n; i++){
        string s;
        cin >> s;
        all_values.push_back(s);
        all_set.insert(s);
    }

    int found = 0;

    for(int i = 0; i < all_values.size(); i++){
        if(found == n){
            break;
        }
        string s = all_values[i];
        string h = get_hash(s);

        if (all_set.find(h) != all_set.end()){
            cout << "Hash of string \"" << s << "\" is " << h << "\n";
            found++;
        }
    }

}