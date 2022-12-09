#include <bits/stdc++.h>

using namespace std;

int a[6], b[6];

int get_max(int cur) {
    int ret = 0;
    if (cur == 6) {
        int sum1 = 0, sum2 = 0;
        for (int i = 1; i <= 5; i++) {
            sum1 += a[i];
            sum2 += (i * a[i]);
            ret += (a[i] * b[i]);
        }

        if (sum1 <= 3 && sum2 <= 10) {
            return ret;
        } else if (sum1 >= 4 && sum2 <= 15) {
            return ret;
        }
        return 0;

    } else {
        if (a[cur] < 15) {
            a[cur]++;
            ret = max(ret, get_max(cur));
            a[cur]--;
        }
        ret = max(ret, get_max(cur + 1));

        return ret;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    for (int i = 1; i <= 5; i++) {
        scanf("%d", &b[i]);
    }

    printf("%d", get_max(1));

    return 0;
}