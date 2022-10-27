#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, b;
int a[MAXN];
map<int, int> cnt;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &b);

    int target;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if (a[i] == b) {
            target = i;
        }
    }

    cnt[0] = 1;

    int big = 0, small = 0;
    for (int i = target + 1; i < n; i++) {
        if (a[i] < b) {
            small++;
        } else {
            big++;
        }

        cnt[small - big]++;
    }

    long long ret = 0;

    big = 0, small = 0;
    for (int i = target - 1; i >= 0; i--) {
        if (a[i] < b) {
            small++;
        } else {
            big++;
        }

        if (cnt.count(big - small)) {
            ret += (cnt[big - small]);
        }
    }

    ret += cnt[0];

    printf("%lld", ret);

    return 0;
}