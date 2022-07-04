#include <bits/stdc++.h>

using namespace std;

string s;
int s_len;

bool check(string &cur) {
    for (int len = 1; len < s_len; len++) {
        if (cur.substr(0, len) >= cur.substr(len, s_len - len)) {
            return false;
        }
    }

    return true;
}

bool get_next(string &cur, int pos) {
    if (pos == s_len) {
        return true;
    }

    cur[pos] = '0';
    if (check(cur) && get_next(cur, pos + 1)) {
        return true;
    }

    cur[pos] = '1';
    if (check(cur) && get_next(cur, pos + 1)) {
        return true;
    }

    return false;
}

void solve(string &cur) {
    string ret;
    string tmp = cur;
    for (int i = s_len - 1; i >= 0; i--) {
        if (tmp[i] == '0') {
            tmp[i] = '1';

            if (check(tmp) && get_next(tmp, i + 1)) {
                cout << tmp;
                return;
            }
        }
    }
    cout << -1;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    s_len = s.length();

    solve(s);

    return 0;
}
