#include <bits/stdc++.h>

using namespace std;

const int MAXN = 25e4;
int n;
int gap[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    gap[0] = 1e9;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &gap[i]);
    }

    for (int i = 1; i <= n; i++) {
        int tmp;
        scanf("%d", &tmp);

        gap[i] -= tmp;

        if (gap[i - 1] < gap[i]) {
            gap[i] = gap[i - 1];
        }
    }

    int q;
    scanf("%d", &q);

    while (q--) {
        int w;
        scanf("%d", &w);

        int left = 0, right = n;
        int target = left;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (w <= gap[mid]) {
                target = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        printf("%d\n", target);
    }

    return 0;
}