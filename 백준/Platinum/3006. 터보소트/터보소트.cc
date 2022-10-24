#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
int fenwick[MAXN + 1], pos[MAXN + 1];

void update(int target) {
    for (int i = target; i <= n; i = (i | (i + 1))) {
        fenwick[i]++;
    }
}

int get_sum(int to) {
    int ret = 0;
    for (int i = to; i >= 0; i = (i & (i + 1)) - 1) {
        ret += fenwick[i];
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int num;
        scanf("%d", &num);

        pos[num] = i;
    }

    int op = 0;
    int left = 1, right = n;

    while (left <= right) {
        if (op == 0) {
            int cnt = pos[left] - 1 - get_sum(pos[left]);
            printf("%d\n", cnt);
            update(pos[left]);

            left++;
            op = 1;
        } else {
            int cnt = (n - pos[right]) - get_sum(n) +
                      get_sum(pos[right] - 1);
            printf("%d\n", cnt);
            update(pos[right]);

            right--;
            op = 0;
        }
    }

    return 0;
}