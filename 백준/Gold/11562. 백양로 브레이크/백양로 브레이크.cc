#include <bits/stdc++.h>

using namespace std;

const int INF = 500;
int n, m;
int dist[251][251];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                continue;
            }
            dist[i][j] = INF;
        }
    }

    while (m--) {
        int u, v, b;
        scanf("%d %d %d", &u, &v, &b);

        dist[u][v] = dist[v][u] = 0;
        if (b == 0) {
            dist[v][u] = 1;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j],
                                 dist[i][k] + dist[k][j]);
            }
        }
    }

    int k;
    scanf("%d", &k);

    while (k--) {
        int u, v;
        scanf("%d %d", &u, &v);

        printf("%d\n", dist[u][v]);
    }

    return 0;
}