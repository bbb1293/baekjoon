#include <bits/stdc++.h>

using namespace std;

int n;
int state[20];
char tmp[21];

int get_num(int bits) {
    for (int y = 0; y < n; y++) {
        if (bits & (1 << y)) {
            state[y] ^= ((1 << n) - 1);
        }
    }

    int ret = 0;
    for (int x = 0; x < n; x++) {
        int cnt = 0;
        for (int y = 0; y < n; y++) {
            if (state[y] & (1 << x)) {
                cnt++;
            }
        }

        ret += min(cnt, n - cnt);
    }

    for (int y = 0; y < n; y++) {
        if (bits & (1 << y)) {
            state[y] ^= ((1 << n) - 1);
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int y = 0; y < n; y++) {
        scanf("%s", tmp);

        for (int x = 0; x < n; x++) {
            state[y] <<= 1;
            if (tmp[x] == 'H') {
                state[y]++;
            }
        }
    }

    int ret = 987654321;
    for (int bits = 0; bits < (1 << n); bits++) {
        ret = min(ret, get_num(bits));
    }

    printf("%d", ret);

    return 0;
}