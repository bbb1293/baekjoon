#include <bits/stdc++.h>

using namespace std;

int r, c;
char table[1000][1001];
unordered_set<string> us;

bool is_overlabed(int len) {
    for (int x = 0; x < c; x++) {
        string tmp;
        for (int i = 0; i < len; i++) {
            tmp += table[r - i - 1][x];
        }

        if (us.count(tmp)) {
            return true;
        }
        us.insert(tmp);
    }

    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &r, &c);

    for (int y = 0; y < r; y++) {
        scanf("%s", &table[y]);
    }

    int ret = r - 1;
    int left = 1, right = r - 1;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (is_overlabed(mid)) {
            ret = min(ret, r - mid - 1);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%d", ret);

    return 0;
}