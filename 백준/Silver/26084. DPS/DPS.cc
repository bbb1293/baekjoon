#include <bits/stdc++.h>

using namespace std;

char team[4], name[11];
int n;
int cnt1[26], cnt2[26];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%s", team);

    for (int i = 0; i < 3; i++) {
        cnt1[team[i] - 'A']++;
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", name);

        cnt2[name[0] - 'A']++;
    }

    long long ret = 1;
    for (int i = 0; i < 26; i++) {
        if (cnt1[i]) {
            if (cnt1[i] <= cnt2[i]) {
                if (cnt1[i] == 1) {
                    ret *= cnt2[i];
                } else if (cnt1[i] == 2) {
                    ret *= ((long long)cnt2[i] *
                            (cnt2[i] - 1) / 2);
                } else {
                    ret *=
                        ((long long)cnt2[i] *
                         (cnt2[i] - 1) * (cnt2[i] - 2) / 6);
                }
            } else {
                ret = 0;
                break;
            }
        }
    }

    printf("%lld", ret);

    return 0;
}
