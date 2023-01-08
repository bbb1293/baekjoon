#include <bits/stdc++.h>

using namespace std;

string n;

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    string n16 = n + "0000";

    int n16_len = n16.length();
    int n_len = n.length();
    int add = 0, n_idx = n_len - 1;
    for (int i = n16_len - 1; i >= 0; i--) {
        if (add) {
            if (n16[i] == '0') {
                n16[i] = '1';
                add = 0;
            } else {
                n16[i] = '0';
            }
        }

        if (n_idx >= 0) {
            if (n16[i] == '1') {
                if (n[n_idx] == '1') {
                    n16[i] = '0';
                    add = 1;
                }
            } else {
                if (n[n_idx] == '1') {
                    n16[i] = '1';
                }
            }
            n_idx--;
        }
    }

    if (add) {
        n16 = '1' + n16;
    }
    cout << n16;

    return 0;
}