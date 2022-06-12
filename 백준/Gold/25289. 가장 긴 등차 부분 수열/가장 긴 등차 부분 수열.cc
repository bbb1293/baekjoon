#include <bits/stdc++.h>

using namespace std;

int n;
int num[100000], cnt[101];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    int ret = 1;
    for (int diff = -99; diff < 100; diff++) {
        memset(cnt, 0, sizeof(cnt));

        for (int i = 0; i < n; i++) {
            int cur_cnt = 0;
            if (num[i] + diff <= 100 && 0 < num[i] + diff) {
                cur_cnt = cnt[num[i] + diff];
            }

            cnt[num[i]] = cur_cnt + 1;

            ret = max(ret, cur_cnt + 1);
        }
    }

    printf("%d", ret);

    return 0;
}
