#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000;
int n;
char roulette[3 * MAXN + 1];
int pi[3 * MAXN + 1];

int get_gcd(int a, int b) {
    if (a == 0) {
        return b;
    }
    return get_gcd(b % a, a);
}

int main() {
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %c ", &roulette[i]);
    }
    roulette[n] = '$';
    for (int i = 1; i <= n; i++) {
        scanf(" %c ", &roulette[n + i]);
        roulette[2 * n + i] = roulette[n + i];
    }

    int cnt = 0;
    for (int i = 1, j = 0; i < 3 * n; i++) {
        while (j && (roulette[i] != roulette[j])) {
            j = pi[j - 1];
        }

        if (roulette[i] == roulette[j]) {
            j++;
        }

        pi[i] = j;

        if (j == n) {
            cnt++;
        }
    }

    int gcd = get_gcd(cnt, n);

    printf("%d/%d", cnt / gcd, n / gcd);

    return 0;
}