#include <bits/stdc++.h>

using namespace std;

int n;
map<int, int> m;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    while (n--) {
        int tmp;
        scanf("%d", &tmp);

        m[tmp]++;
    }

    int v;
    scanf("%d", &v);
    printf("%d", m[v]);

    return 0;
}
