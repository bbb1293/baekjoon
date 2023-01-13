#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n;
bool in[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    int ret = 0;

    scanf("%d", &n);

    while (n--) {
        int a, b;
        scanf("%d %d", &a, &b);

        if (b) {
            if (in[a]) {
                ret++;
            }
            in[a] = true;

        } else {
            if (!in[a]) {
                ret++;
            }
            in[a] = false;
        }
    }

    for (int i = 1; i <= MAXN; i++) {
        if (in[i]) {
            ret++;
        }
    }

    printf("%d", ret);

    return 0;
}