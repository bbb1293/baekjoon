#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e5;
int n, m;
int a[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int left = 0, right = 0;
    int sum = 0, ret = 0;
    while (left < n) {
        while (right < n &&
               (sum + a[right] <= m || left == right)) {
            sum += a[right++];
        }

        if (sum <= m) {
            ret = max(ret, sum);
        }

        sum -= a[left++];
    }

    printf("%d", ret);

    return 0;
}