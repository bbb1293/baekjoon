#include <bits/stdc++.h>

using namespace std;

int n;
int x[50];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    sort(x, x + n);

    long long ret = 0;
    for (int left = 0; left < n; left++) {
        for (int right = left + 2; right < n; right++) {
            if (x[left] + x[right - 1] <= x[right]) {
                continue;
            }

            int cnt = 0;
            for (int mid = right - 1; mid > left; mid--) {
                if (x[left] + x[mid] <= x[right]) {
                    break;
                }
                cnt++;
            }

            for (int mid = right - cnt; mid < right;
                 mid++) {
                int cur_cnt = 0;
                for (int mid2 = mid + 1; mid2 < right;
                     mid2++) {
                    if (x[left] + x[mid] <= x[mid2]) {
                        break;
                    }
                    cur_cnt++;
                }

                ret += (1ll << cur_cnt);
            }
        }
    }

    printf("%lld", ret);

    return 0;
}