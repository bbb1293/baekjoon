#include <bits/stdc++.h>

using namespace std;

int n;
long long len[50];

void set_len() {
    len[0] = 3;
    for (int i = 1; i < 50; i++) {
        len[i] = 2 * len[i - 1] + 3 + i;
    }
}

void solve(int cur, int nth) {
    if (nth <= len[cur]) {
        if (nth <= len[cur - 1]) {
            solve(cur - 1, nth);
        } else {
            nth -= len[cur - 1];

            if (nth <= 3 + cur) {
                if (nth == 1) {
                    printf("m");
                } else {
                    printf("o");
                }

            } else {
                nth -= (3 + cur);
                solve(cur - 1, nth);
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    set_len();

    scanf("%d", &n);

    solve(49, n);

    return 0;
}