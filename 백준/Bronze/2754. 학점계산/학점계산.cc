#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    // freopen("input.txt", "r", stdin);

    cin >> s;

    cout.precision(1);
    if (s == "F") {
        cout << fixed << 0.0;
    } else {
        double ret = 4 - (s[0] - 'A');

        if (s[1] == '+') {
            ret += 0.3;
        } else if (s[1] == '-') {
            ret -= 0.3;
        }

        cout << fixed << ret;
    }

    return 0;
}
