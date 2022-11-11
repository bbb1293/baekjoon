#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5e4;
int n;
int dist[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &dist[i]);
        sum += dist[i];
    }

    int left = 0, right = 0;
    int ret = 0, cur_sum = 0;
    while (left < n) {
        int cur_dist = min(cur_sum, sum - cur_sum);
        while (min(cur_sum + dist[right],
                   sum - cur_sum - dist[right]) >
               cur_dist) {
            cur_sum += dist[right];
            cur_dist = min(cur_sum, sum - cur_sum);
            right = (right + 1) % n;
        }

        ret = max(ret, min(cur_sum, sum - cur_sum));
        cur_sum -= dist[left++];
    }

    printf("%d", ret);

    return 0;
}