#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int pos[50], mark[50];

bool is_possible(int min_dist) {
    int prev = pos[0], cnt = m - 1;

    for (int i = 1; i < k; i++) {
        if (!cnt) {
            break;
        }

        if (pos[i] - prev >= min_dist) {
            prev = pos[i];
            cnt--;
        }
    }

    if (cnt) {
        return false;
    }

    return true;
}

void put_judge(int min_dist) {
    int prev = pos[0], cnt = m - 1;
    mark[0] = 1;

    for (int i = 1; i < k; i++) {
        if (!cnt) {
            break;
        }

        if (pos[i] - prev >= min_dist) {
            prev = pos[i];
            cnt--;
            mark[i] = 1;
        } else {
            mark[i] = 0;
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &k);

    for (int i = 0; i < k; i++) {
        scanf("%d", &pos[i]);
    }

    if (m == 0) {
        while (k--) {
            printf("0");
        }

        return 0;
    }

    int left = 0, right = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (is_possible(mid)) {
            put_judge(mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    for (int i = 0; i < k; i++) {
        printf("%d", mark[i]);
    }

    return 0;
}