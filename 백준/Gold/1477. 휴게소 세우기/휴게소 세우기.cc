#include <bits/stdc++.h>

using namespace std;

int n, m, l;
int pos[50];

bool is_possible(int th) {
    int prev_pos = 0;
    int rest = m;

    for (int i = 0; i < n; i++) {
        while (rest && pos[i] - prev_pos > th) {
            prev_pos += th;
            rest--;
        }

        if (pos[i] - prev_pos > th) {
            return false;
        }
        prev_pos = pos[i];
    }

    while (rest && l - prev_pos > th) {
        prev_pos += th;
        rest--;
    }

    return l - prev_pos <= th;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &m, &l);

    for (int i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
    }
    sort(pos, pos + n);

    int left = 1, right = l;
    int ret = right;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (is_possible(mid)) {
            ret = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d", ret);

    return 0;
}