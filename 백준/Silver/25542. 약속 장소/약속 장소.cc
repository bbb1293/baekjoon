#include <bits/stdc++.h>

using namespace std;

int n, l;
char store[20][21];

bool solve(int idx) {
    if (idx == n) {
        for (int i = 0; i < l; i++) {
            if (store[0][i] == '$') {
                printf("A");
            } else {
                printf("%c", store[0][i]);
            }
        }
        return true;
    }

    int cnt = 0, target = -1;
    for (int i = 0; i < l; i++) {
        if (store[0][i] != store[idx][i]) {
            if (store[0][i] == '$') {
                target = i;
            } else {
                cnt++;
            }
        }
    }

    if (cnt > 1) {
        return false;
    }

    if (cnt == 1 && target != -1) {
        store[0][target] = store[idx][target];
    }

    return solve(idx + 1);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &l);

    for (int i = 0; i < n; i++) {
        scanf("%s", &store[i]);
    }

    for (int i = 0; i < l; i++) {
        char tmp = store[0][i];
        store[0][i] = '$';

        if (solve(1)) {
            return 0;
        }

        store[0][i] = tmp;
    }

    printf("CALL FRIEND");

    return 0;
}
