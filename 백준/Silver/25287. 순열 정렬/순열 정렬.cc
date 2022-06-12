#include <bits/stdc++.h>

using namespace std;

int n;
int num[50001];

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &num[i]);
        }

        bool possible = true;
        for (int i = 1; i <= n; i++) {
            int min_cur = min(num[i], n - num[i] + 1);
            int max_cur = max(num[i], n - num[i] + 1);

            if (num[i - 1] <= min_cur) {
                num[i] = min_cur;
            } else if (num[i - 1] <= max_cur) {
                num[i] = max_cur;
            } else {
                possible = false;
            }
        }

        if (possible) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
