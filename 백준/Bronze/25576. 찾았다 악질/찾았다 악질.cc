#include <bits/stdc++.h>

using namespace std;

int n, m;
int ori[100];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d", &ori[i]);
    }

    int cnt = 0;
    for (int i = 1; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            int tmp;
            scanf("%d", &tmp);

            sum += abs(tmp - ori[j]);
        }

        if (sum > 2000) {
            cnt++;
        }
    }

    n--;
    if ((n + 1) / 2 <= cnt) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}