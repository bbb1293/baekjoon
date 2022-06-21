#include <bits/stdc++.h>

using namespace std;

int n;
string s;

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    long long ret = 0;

    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    for (int i = 1; i < n; i++) {
        if (pi[i] != 0) {
            if (pi[pi[i] - 1] != 0) {
                pi[i] = pi[pi[i] - 1];
            }
            ret += (i + 1 - pi[i]);
        }
    }

    printf("%lld", ret);

    return 0;
}
