#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
int num[MAXN + 1], presum[MAXN + 1], near_idx[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);
        presum[i] = presum[i - 1] + num[i];
    }

    int ret = presum[n], prev_idx = 0;
    for (int i = 1; i < n; i++) {
        prev_idx = max(prev_idx, near_idx[i]);
        int cur_len = presum[i] - presum[prev_idx];
        ret = min(ret, max(cur_len, presum[n] - presum[i]));

        int left = i + 1, right = n;
        int target = n;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (presum[mid] - presum[i] >= cur_len) {
                target = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        near_idx[target] = max(near_idx[target], i);
    }

    printf("%d", ret);

    return 0;
}
