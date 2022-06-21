#include <bits/stdc++.h>

using namespace std;

int n, k;
int ori_len, cur_len;
int ori[1000], cur[2001], cnt[1000], pi[2001];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);

    scanf("%d", &ori_len);
    for (int i = 0; i < ori_len; i++) {
        scanf("%d", &ori[i]);
    }
    n--;

    for (int a = 0; a < n; a++) {
        scanf("%d", &cur_len);
        for (int i = 0; i < cur_len; i++) {
            scanf("%d", &cur[i + k + 1]);
        }
        cur_len += (k + 1);

        for (int i = 0; i <= ori_len - k; i++) {
            bool possible = false;

            for (int j = 0; j < k; j++) {
                cur[j] = ori[i + j];
            }

            for (int pos = 1; pos < cur_len; pos++) {
                int j = pi[pos - 1];

                while (j > 0 && cur[j] != cur[pos]) {
                    j = pi[j - 1];
                }

                if (cur[j] == cur[pos]) {
                    j++;
                }

                pi[pos] = j;

                if (j == k) {
                    possible = true;
                    break;
                }
            }

            for (int j = 0; j < k; j++) {
                cur[k - j - 1] = ori[i + j];
            }

            for (int pos = 1; pos < cur_len; pos++) {
                int j = pi[pos - 1];

                while (j > 0 && cur[j] != cur[pos]) {
                    j = pi[j - 1];
                }

                if (cur[j] == cur[pos]) {
                    j++;
                }

                pi[pos] = j;

                if (j == k) {
                    possible = true;
                    break;
                }
            }

            if (possible) {
                cnt[i]++;
            }
        }
    }

    for (int i = 0; i < ori_len; i++) {
        if (cnt[i] == n) {
            printf("YES");
            return 0;
        }
    }

    printf("NO");

    return 0;
}
