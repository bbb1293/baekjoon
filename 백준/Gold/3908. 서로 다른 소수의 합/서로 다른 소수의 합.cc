#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1120, MAXK = 14;
int n, k;
bool non_prime[MAXN + 1];
int cnt[MAXN + 1][MAXK + 1];

void set_cnt() {
    cnt[0][0] = 1;

    for (int i = 2; i <= MAXN; i++) {
        if (!non_prime[i]) {
            for (int j = i + i; j <= MAXN; j += i) {
                non_prime[j] = true;
            }

            for (int j = MAXN; j >= i; j--) {
                for (int k = 1; k <= MAXK; k++) {
                    cnt[j][k] += cnt[j - i][k - 1];
                }
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    set_cnt();

    while (t--) {
        scanf("%d %d", &n, &k);

        printf("%d\n", cnt[n][k]);
    }

    return 0;
}