#include <bits/stdc++.h>

using namespace std;

struct Info {
    int from, to, gap;
};

int n, k, d;
Info info[10000];

long long get_num(int box_idx) {
    long long ret = 0;

    for (int i = 0; i < k; i++) {
        if (info[i].from <= box_idx) {
            ret += ((min(box_idx, info[i].to) - info[i].from + info[i].gap) /
                    info[i].gap);
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %d", &n, &k, &d);
    for (int i = 0; i < k; i++) {
        scanf("%d %d %d", &info[i].from, &info[i].to, &info[i].gap);
    }

    int from = 1, to = n;
    int target = to;

    while (from <= to) {
        int mid = (from + to) / 2;

        if (get_num(mid) < d) {
            from = mid + 1;
        } else {
            target = mid;
            to = mid - 1;
        }
    }
    printf("%d", target);

    return 0;
}
