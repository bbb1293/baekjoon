#include <bits/stdc++.h>

using namespace std;

int y, d;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &y);
    scanf("%d", &d);

    int ret = 29;
    if ((!(y % 4) && (y % 100)) || !(y % 400)) {
        ret++;
    }

    printf("%d", ret);

    return 0;
}