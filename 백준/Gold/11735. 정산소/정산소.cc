#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
bool visited[2][MAXN + 1];
int n, q;
long long cnt[2], removed[2];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &q);

    cnt[0] = cnt[1] = n;
    long long base = ((long long)n * (n + 1)) / 2;

    while (q--) {
        char op;
        int k;

        scanf(" %c %d", &op, &k);

        int idx = 0;

        if (op == 'R') {
            idx = 1;
        }

        if (visited[idx][k]) {
            printf("0\n");
        } else {
            visited[idx][k] = true;

            printf("%lld\n",
                   cnt[idx] * k + base - removed[idx]);
            cnt[(idx + 1) % 2]--;
            removed[(idx + 1) % 2] += k;
        }
    }

    return 0;
}
