#include <bits/stdc++.h>

using namespace std;

string s;
bool exist[1000000];

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    if (s.length() < 3) {
        printf("-1");
        return 0;
    }

    vector<int> pi(s.length());
    for (int i = 1; i < s.length() - 1; i++) {
        int j = pi[i - 1];

        while (j > 0 && s[j] != s[i]) {
            j = pi[j - 1];
        }

        if (s[j] == s[i]) {
            j++;
        }

        pi[i] = j;
        exist[j] = true;
    }

    int j = pi[s.length() - 2];
    while (j > 0 && s[j] != s.back()) {
        j = pi[j - 1];
    }

    if (s[j] == s.back()) {
        j++;
    }

    while (j > 0 && !exist[j]) {
        j = pi[j - 1];
    }

    if (j == 0) {
        printf("-1");
    } else {
        for (int i = 0; i < j; i++) {
            cout << s[s.length() - j + i];
        }
    }

    return 0;
}
