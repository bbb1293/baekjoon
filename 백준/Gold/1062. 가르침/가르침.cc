#include <bits/stdc++.h>

using namespace std;

int n, k;
int word[50];
char tmp[16];

int solve(int bits, int cnt, int cur) {
    if (cnt == k) {
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if ((word[i] & bits) == word[i]) {
                ret++;
            }
        }

        return ret;
    }

    int ret = 0;
    for (int i = cur; i < 26; i++) {
        ret = max(ret, solve(bits | (1 << i), cnt + 1, i + 1));
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf(" %s", tmp);

        for (int j = 0; tmp[j]; j++) {
            word[i] |= (1 << (tmp[j] - 'a'));
        }
    }

    printf("%d", solve(0, 0, 0));

    return 0;
}
