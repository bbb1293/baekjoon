#include <bits/stdc++.h>

using namespace std;

int y, m;
set<int> s = {2, 4, 6, 8, 9, 11};

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &y, &m);

        if (m == 1) {
            printf("%d %d %d\n", y - 1, 12, 31);
        } else if (m == 3) {
            if (((y % 100) && !(y % 4)) || !(y % 400)) {
                printf("%d %d %d\n", y, 2, 29);
            } else {
                printf("%d %d %d\n", y, 2, 28);
            }
        } else if (s.count(m)) {
            printf("%d %d %d\n", y, m - 1, 31);
        } else {
            printf("%d %d %d\n", y, m - 1, 30);
        }
    }

    return 0;
}
