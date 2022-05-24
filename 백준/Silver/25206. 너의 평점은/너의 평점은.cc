#include <bits/stdc++.h>

using namespace std;

map<string, double> m = {{"A+", 4.5}, {"A0", 4.0}, {"B+", 3.5},
                         {"B0", 3.0}, {"C+", 2.5}, {"C0", 2.0},
                         {"D+", 1.5}, {"D0", 1.0}, {"F", 0.0}};

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    double grade_sum = 0, credit_sum;
    while (!cin.eof()) {
        string name, grade;
        double credit;

        cin >> name >> credit >> grade;

        if (m.find(grade) != m.end()) {
            grade_sum += credit * m[grade];
            credit_sum += credit;
        }
    }

    if (credit_sum == 0) {
        cout << "0";
    } else {
        cout << grade_sum / credit_sum;
    }

    return 0;
}
