#include <bits/stdc++.h>

using namespace std;

const int MAXN = 90000;
int n;
bool exist[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int idx;
        scanf("%d", &idx);

        exist[idx] = true;
    }

    long long ret = 0;
    for (int i = 1; i <= MAXN; i++) {
        if (exist[i]) {
            if (!exist[i - 1]) {
                ret += i;
            }
        }
    }

    printf("%lld", ret);

    return 0;
}