#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);

    int r = 0, c = 0, max_num = -1;
    for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
            int tmp;
            scanf("%d", &tmp);

            if (max_num < tmp) {
                r = y;
                c = x;
                max_num = tmp;
            }
        }
    }

    printf("%d\n%d %d", max_num, r + 1, c + 1);

    return 0;
}
