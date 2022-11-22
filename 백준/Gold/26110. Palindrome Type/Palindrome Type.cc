#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
char s[MAXN + 1];

int is_possible(int left, int right, int cnt) {
    if (right <= left) {
        return cnt;
    }

    if (s[left] != s[right]) {
        if (cnt == 3) {
            return -1;
        }

        int ret1 = is_possible(left + 1, right, cnt + 1);
        int ret2 = is_possible(left, right - 1, cnt + 1);

        if (ret1 == -1) {
            return ret2;
        } else {
            if (ret2 == -1) {
                return ret1;
            }
            return min(ret1, ret2);
        }
    }
    return is_possible(left + 1, right - 1, cnt);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%s", s);

    printf("%d", is_possible(0, strlen(s) - 1, 0));

    return 0;
}
