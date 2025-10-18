#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    string vowels, consonants;

    for (char c : s) {
        if (isVowel(c)) vowels += c;
        else consonants += c;
    }

    sort(vowels.begin(), vowels.end());
    sort(consonants.begin(), consonants.end());

    cout << vowels + consonants << "\n";

    return 0;
}