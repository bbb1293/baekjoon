#include <bits/stdc++.h>

using namespace std;

string s, p;

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    cin >> p;

    int p_len = p.length();

    p += ' ';
    p += s;

    int len = p.length();
    vector<int> pi(len);

    for (int i = 1; i < len; i++) {
        int j = pi[i - 1];

        while (j > 0 && p[i] != p[j]) {
            j = pi[j - 1];
        }

        if (p[i] == p[j]) {
            j++;
        }
        pi[i] = j;

        if (j == p_len) {
            cout << '1';
            return 0;
        }
    }
    cout << '0';

    return 0;
}
