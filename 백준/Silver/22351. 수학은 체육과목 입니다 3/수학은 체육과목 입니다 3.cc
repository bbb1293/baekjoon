#include <bits/stdc++.h>

using namespace std;

string s;

int check(int start) {
    int pos = 0;
    while (pos < s.length()) {
        string cur_s = to_string(start);

        if (pos + cur_s.length() > s.length()) {
            return -1;
        }

        if (cur_s != s.substr(pos, cur_s.length())) {
            return -1;
        }

        start++;
        pos += cur_s.length();
    }

    return start - 1;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    for (int i = 1; i <= 999; i++) {
        int b = check(i);
        if (b != -1) {
            cout << i << ' ' << b;
            return 0;
        }
    }

    return 0;
}
