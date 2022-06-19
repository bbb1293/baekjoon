#include <bits/stdc++.h>

using namespace std;

int n, m;

int who_win(int turn, int a, int b) {
    if (b % a == 0) {
        return turn;
    }

    if (b / a == 1) {
        return who_win(turn ^ 1, b % a, a);
    } else {
        return turn;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    while (true) {
        scanf("%d %d", &n, &m);

        if (n == 0 && m == 0) {
            break;
        }

        if (n > m) {
            swap(n, m);
        }

        int ret = who_win(0, n, m);
        if (ret == 0) {
            printf("A wins\n");
        } else {
            printf("B wins\n");
        }
    }

    return 0;
}