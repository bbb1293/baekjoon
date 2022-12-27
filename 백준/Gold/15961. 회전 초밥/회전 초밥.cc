#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e6;
int n, d, k, c;
int sushi[MAXN], cnt[3001];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d %d", &n, &d, &k, &c);

    for (int i = 0; i < n; i++) {
        scanf("%d", &sushi[i]);
    }

    int ret = 0, cur_cnt = 0;
    for (int i = 0; i < k; i++) {
        cnt[sushi[i]]++;

        if (cnt[sushi[i]] == 1) {
            cur_cnt++;
        }
    }

    int add = 0;
    if (cnt[c] == 0) {
        add = 1;
    }

    ret = cur_cnt + add;

    for (int i = 0; i < n; i++) {
        int idx = (i + k) % n;

        cnt[sushi[idx]]++;
        if (cnt[sushi[idx]] == 1) {
            cur_cnt++;
        }

        cnt[sushi[i]]--;
        if (cnt[sushi[i]] == 0) {
            cur_cnt--;
        }

        add = 0;
        if (cnt[c] == 0) {
            add = 1;
        }

        ret = max(ret, cur_cnt + add);
    }

    printf("%d", ret);

    return 0;
}