#include <bits/stdc++.h>

using namespace std;

string tmp, s, k;

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> tmp;
    for (auto c : tmp) {
        if (!('0' <= c && c <= '9')) {
            s += c;
        }
    }

    cin >> k;

    int k_len = k.length();
    k += ' ';
    k += s;

    int len = k.length();
    vector<int> pi(len);
    for (int i = 1; i < len; i++) {
        int j = pi[i - 1];

        while (j > 0 && k[i] != k[j]) {
            j = pi[j - 1];
        }

        if (k[i] == k[j]) {
            j++;
        }

        pi[i] = j;

        if (j == k_len) {
            cout << '1';
            return 0;
        }
    }

    cout << '0';

    return 0;
}
