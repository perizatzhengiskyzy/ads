#include <bits/stdc++.h>
using namespace std;

double gradeToGPA(string s) {
    if (s == "A+") return 4.0;
    if (s == "A") return 3.75;
    if (s == "B+") return 3.5;
    if (s == "B") return 3.0;
    if (s == "C+") return 2.5;
    if (s == "C") return 2.0;
    if (s == "D+") return 1.5;
    if (s == "D") return 1.0;
    return 0.0;
}

struct Student {
    string last, first;
    double gpa;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Student> students(n);

    for (int i = 0; i < n; i++) {
        string last, first;
        int m;
        cin >> last >> first >> m;
        double sum = 0, total = 0;
        for (int j = 0; j < m; j++) {
            string grade;
            int credit;
            cin >> grade >> credit;
            sum += gradeToGPA(grade) * credit;
            total += credit;
        }
        students[i].last = last;
        students[i].first = first;
        students[i].gpa = sum / total;
    }

    sort(students.begin(), students.end(), [](const Student &a, const Student &b) {
        if (fabs(a.gpa - b.gpa) > 1e-9) return a.gpa < b.gpa; // өсу ретімен
        if (a.last != b.last) return a.last < b.last;
        return a.first < b.first;
    });

    for (auto &s : students)
        cout << s.last << " " << s.first << " " << fixed << setprecision(3) << s.gpa << "\n";

    return 0;
}
