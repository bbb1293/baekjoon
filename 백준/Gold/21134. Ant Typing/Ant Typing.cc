#include <bits/stdc++.h>

using namespace std;

char s[100001];
int cnt[10][10];
bool used[10];

int solve(vector<int> &cur) {
    if (cur.size() == 9) {
        int ret = 0;
        for (int i = 0; i < 9; i++) {
            if (cur[i] == s[0] - '0') {
                ret += i;
            }

            for (int j = i + 1; j < 9; j++) {
                ret += ((j - i) * (cnt[cur[i]][cur[j]] +
                                   cnt[cur[j]][cur[i]]));
            }
        }

        return ret;
    } else {
        int ret = 1e9;
        for (int i = 1; i < 10; i++) {
            if (!used[i]) {
                used[i] = true;
                cur.push_back(i);

                ret = min(ret, solve(cur));

                used[i] = false;
                cur.pop_back();
            }
        }

        return ret;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%s", s);

    int n = strlen(s);
    for (int i = 1; i < n; i++) {
        cnt[s[i - 1] - '0'][s[i] - '0']++;
    }

    vector<int> cur;
    int ret = n + solve(cur);

    printf("%d", ret);

    return 0;
}