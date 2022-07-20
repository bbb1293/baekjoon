#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n;
int l[MAXN], r[MAXN];
map<int, int> m;

bool check(int from, int to) {
    if (from >= to) {
        return true;
    }

    int left = from, right = to;
    while (left <= right) {
        if ((l[left] == -1 || l[left] < from) &&
            (r[left] == -1 || to < r[left])) {
            return check(from, left - 1) && check(left + 1, to);
        }
        if ((l[right] == -1 || l[right] < from) &&
            (r[right] == -1 || to < r[right])) {
            return check(from, right - 1) && check(right + 1, to);
        }
        left++;
        right--;
    }

    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        m.clear();

        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int tmp;
            scanf("%d", &tmp);

            l[i] = r[i] = -1;
            if (m.count(tmp) != 0) {
                l[i] = m[tmp];
                r[m[tmp]] = i;
            }
            m[tmp] = i;
        }

        if (check(0, n - 1)) {
            printf("non-boring\n");
        } else {
            printf("boring\n");
        }
    }

    return 0;
}
