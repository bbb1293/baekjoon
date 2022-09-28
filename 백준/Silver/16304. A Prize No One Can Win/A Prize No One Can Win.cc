#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, x;
int items[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &x);

    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }

    sort(items, items + n);

    int prev = items[0];
    int ret = 1;

    for (int i = 1; i < n; i++) {
        if (prev + items[i] > x) {
            break;
        } else {
            ret++;
            prev = items[i];
        }
    }

    printf("%d", ret);

    return 0;
}