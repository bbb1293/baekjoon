#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;
    int s_len = s.length();

    int ret = 0;

    vector<int> pi(s_len);
    for (int start = 0; start < s_len; start++) {
        pi[start] = 0;
        for (int i = start + 1; i < s_len; i++) {
            int j = pi[i - 1];

            while (j > 0 && s[i] != s[j + start]) {
                j = pi[j + start - 1];
            }

            if (s[i] == s[j + start]) {
                j++;
            }
            pi[i] = j;
            ret = max(ret, j);
        }
    }

    cout << ret;

    return 0;
}
