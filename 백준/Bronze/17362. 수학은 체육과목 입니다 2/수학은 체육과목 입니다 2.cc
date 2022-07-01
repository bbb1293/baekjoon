#include <bits/stdc++.h>

using namespace std;

int n;
int ans[] = {1, 2, 3, 4, 5, 4, 3, 2};

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    n--;
    n %= 8;

    printf("%d", ans[n]);

    return 0;
}
