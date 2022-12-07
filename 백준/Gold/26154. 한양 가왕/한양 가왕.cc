#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3;
int n, m;
int p1[MAXN], p2[MAXN];

void do_round() {
    int tmp = p1[0];
    p1[0] = p2[0];
    for (int i = 1; i < n; i++) {
        p2[i - 1] = p2[i];

        if (p2[i - 1] < p1[i - 1]) {
            swap(p1[i - 1], p2[i - 1]);
        }
    }

    p2[n - 1] = tmp;

    if (p2[n - 1] < p1[n - 1]) {
        swap(p1[n - 1], p2[n - 1]);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &p1[i], &p2[i]);

        if (p2[i] < p1[i]) {
            swap(p1[i], p2[i]);
        }
    }

    int cnt = min(m, n);
    m -= cnt;
    while (cnt--) {
        do_round();
    }

    m %= n;
    while (m--) {
        do_round();
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d\n", p1[i], p2[i]);
    }

    return 0;
}