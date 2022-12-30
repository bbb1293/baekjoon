#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n, t;
pair<int, int> carrot[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &carrot[i].second, &carrot[i].first);
    }

    sort(carrot, carrot + n);

    long long ret = 0;
    int def = t - n;

    for (int i = 0; i < n; i++) {
        ret += (carrot[i].second +
                (long long)carrot[i].first * (def + i));
    }

    printf("%lld", ret);

    return 0;
}