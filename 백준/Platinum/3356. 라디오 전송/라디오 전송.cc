#include <bits/stdc++.h>

using namespace std;

int l;
string s;
int pi[1000000];

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> l >> s;

    int s_len = s.length();

    for (int i = 1, j = 0; i < s_len; i++) {
        while (j && s[i] != s[j]) {
            j = pi[j - 1];
        }

        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;
    }

    printf("%d", s_len - pi[s_len - 1]);

    return 0;
}
