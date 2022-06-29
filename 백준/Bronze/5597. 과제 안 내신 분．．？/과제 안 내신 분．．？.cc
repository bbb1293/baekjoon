#include <bits/stdc++.h>

using namespace std;

bool exist[31];

int main() {
    // freopen("input.txt", "r", stdin);

    for (int i = 0; i < 28; i++) {
        int tmp;
        scanf("%d", &tmp);
        exist[tmp] = true;
    }

    for (int i = 1; i <= 30; i++) {
        if (!exist[i]) {
            printf("%d\n", i);
        }
    }

    return 0;
}
