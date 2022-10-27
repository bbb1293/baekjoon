#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;
int n, m;
int dist[MAXN][MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j],
                                 dist[i][k] + dist[k][j]);
            }
        }
    }

    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        if (dist[a - 1][b - 1] <= c) {
            printf("Enjoy other party\n");
        } else {
            printf("Stay here\n");
        }
    }

    return 0;
}