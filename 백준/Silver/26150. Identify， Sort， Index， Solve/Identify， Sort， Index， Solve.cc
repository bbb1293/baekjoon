#include <bits/stdc++.h>

using namespace std;

struct Problem {
    string s;
    int i, d;

    const bool operator<(const Problem &a) const {
        return i < a.i;
    }
};

int n;
Problem p[100];

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].s >> p[i].i >> p[i].d;
    }
    sort(p, p + n);

    string ret;
    for (int i = 0; i < n; i++) {
        char c = p[i].s[p[i].d - 1];

        if ('a' <= c && c <= 'z') {
            c -= 'a';
            c += 'A';
        }

        ret += c;
    }

    cout << ret;

    return 0;
}