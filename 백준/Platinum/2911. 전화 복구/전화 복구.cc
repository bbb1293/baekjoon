#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, m;
pair<int, int> pc[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pc[i].first, &pc[i].second);
    }

    sort(pc, pc + n);

    long long ret = 0, cur = 0;
    for (int i = 0; i < n; i++) {
        if (cur > pc[i].second) {
            ret += (cur - pc[i].second);
        }
        cur = pc[i].second;
    }

    ret += cur;
    printf("%lld", ret);

    return 0;
}