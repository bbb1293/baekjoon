#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5, MAXM = 1e6;
int n, num[MAXN], cnt[MAXM + 1];

int get_ret(int cur) {
    int ret = 0;
    for (int i = 1; i * i <= cur; i++) {
        if (!(cur % i)) {
            ret += cnt[i];

            if (cur / i != i) {
                ret += cnt[cur / i];
            }
        }
    }

    return ret - 1;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        cnt[num[i]]++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", get_ret(num[i]));
    }

    return 0;
}