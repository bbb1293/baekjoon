#include <bits/stdc++.h>

using namespace std;

int n;
int a[2000], num[2000], dp[2000][2];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        int len = 0;
        num[len] = a[i];

        for (int j = i + 1; j < n; j++) {
            int left = 0, right = len;
            int target = -1;

            while (left <= right) {
                int mid = (left + right) / 2;

                if (num[mid] < a[j]) {
                    target = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (target != -1) {
                num[target + 1] = a[j];
                len = max(len, target + 1);
            }
        }
        dp[i][0] = len;
    }

    for (int i = 0; i < n; i++) {
        int len = 0;
        num[len] = a[i];

        for (int j = i + 1; j < n; j++) {
            int left = 0, right = len;
            int target = -1;

            while (left <= right) {
                int mid = (left + right) / 2;

                if (a[j] < num[mid]) {
                    target = mid;
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            if (target != -1) {
                num[target + 1] = a[j];
                len = max(len, target + 1);
            }
        }
        dp[i][1] = len;
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret = max(ret, dp[i][0] + dp[i][1] + 1);
    }

    printf("%d", ret);

    return 0;
}
