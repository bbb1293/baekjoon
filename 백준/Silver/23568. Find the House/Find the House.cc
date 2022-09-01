#include <bits/stdc++.h>

using namespace std;

int n;
map<int, int> m;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    while (n--) {
        int pos, move;
        char op;

        scanf("%d %c %d", &pos, &op, &move);

        if (op == 'L') {
            move = -move;
        }

        m[pos] = move;
    }

    int cur;
    scanf("%d", &cur);

    while (m.count(cur) != 0) {
        cur += m[cur];
    }

    printf("%d", cur);

    return 0;
}