#include <bits/stdc++.h>

using namespace std;

int m;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &m);

    int ret = 0;
    while(m--) {
        int tmp;
        scanf("%d", &tmp);
        ret ^= tmp;
    }

    if (ret != 0) {
        printf("koosaga");
    } else {
        printf("cubelover");
    }

    return 0;
}
