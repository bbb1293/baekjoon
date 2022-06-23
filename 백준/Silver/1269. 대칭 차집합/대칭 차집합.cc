#include <bits/stdc++.h>

using namespace std;

int n, m;
set<int> a, b;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    int tmp;
    while (n--) {
        scanf("%d", &tmp);
        a.insert(tmp);
    }

    while (m--) {
        scanf("%d", &tmp);
        b.insert(tmp);
    }

    int ret = a.size() + b.size();
    for (auto aa : a) {
        if (b.count(aa)) {
            ret -= 2;
        }
    }

    printf("%d", ret);

    return 0;
}
