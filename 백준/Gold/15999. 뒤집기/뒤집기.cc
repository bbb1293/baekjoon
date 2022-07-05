#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
int n, m;
char grid[2000][2001];
bool is_fixed[2000][2000];

long long power(int k) {
    if (k == 0) {
        return 1;
    }

    if (k == 1) {
        return 2;
    }

    long long ret = power(k / 2);

    if (k & 1) {
        return (((ret * 2) % MOD) * ret) % MOD;
    }
    return ((ret * ret) % MOD);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int y = 0; y < n; y++) {
        scanf("%s", grid[y]);
    }

    int cnt = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (y + 1 < n && grid[y][x] != grid[y + 1][x]) {
                is_fixed[y][x] = true;
                is_fixed[y + 1][x] = true;
            }

            if (x + 1 < m && grid[y][x] != grid[y][x + 1]) {
                is_fixed[y][x] = true;
                is_fixed[y][x + 1] = true;
            }

            if (!is_fixed[y][x]) {
                cnt++;
            }
        }
    }

    printf("%lld", power(cnt));

    return 0;
}
