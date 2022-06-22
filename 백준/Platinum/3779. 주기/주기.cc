#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int pi[1000000];

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cur = 1;
    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        cout << "Test case #" << cur << '\n';
        cur++;

        cin >> s;
        int s_len = s.length();

        for (int i = 1, j = 0; i < s_len; i++) {
            while (j && s[i] != s[j]) {
                j = pi[j - 1];
            }

            if (s[i] == s[j]) {
                j++;
            }

            pi[i] = j;
            int period = (i + 1) - j;

            if (j && !((i + 1) % period)) {
                cout << i + 1 << ' ' << ((i + 1) / period) << '\n';
            }
        }
        cout << '\n';
    }

    return 0;
}
