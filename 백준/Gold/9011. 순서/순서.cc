#include <bits/stdc++.h>

using namespace std;

int n, num[100], ret[100];
bool used[101];

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &num[i]);
        }

        memset(used, 0, sizeof(used));

        bool possible = true;
        for (int i = n - 1; i >= 0; i--) {
            num[i]++;

            int cur = 1;
            while (num[i] && cur <= n) {
                if (!used[cur]) {
                    num[i]--;
                }
                cur++;
            }

            if (num[i]) {
                possible = false;
                break;
            }
            used[cur - 1] = true;
            ret[i] = cur - 1;
        }

        if (possible) {
            for (int i = 0; i < n; i++) {
                printf("%d ", ret[i]);
            }
            printf("\n");
        } else {
            printf("IMPOSSIBLE\n");
        }
    }

    return 0;
}
