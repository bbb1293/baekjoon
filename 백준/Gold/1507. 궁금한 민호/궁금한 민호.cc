#include <bits/stdc++.h>

using namespace std;

int n;
int dist[20][20];
bool unused[20][20];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            if (i == j) {
                continue;
            }

            for (int k = 0; k < n; k++) {
                if (i == k || j == k) {
                    continue;
                }

                if (dist[i][k] == dist[i][j] + dist[j][k]) {
                    unused[i][k] = true;
                } else if (dist[i][k] >
                           dist[i][j] + dist[j][k]) {
                    printf("-1");
                    return 0;
                }
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!unused[i][j]) {
                ret += dist[i][j];
            }
        }
    }

    printf("%d", ret);

    return 0;
}