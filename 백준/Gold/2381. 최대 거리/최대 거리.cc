#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> p, m;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);

        p.push_back(x + y);
        m.push_back(y - x);
    }

    sort(p.begin(), p.end());
    sort(m.begin(), m.end());

    int ret = max(abs(p.back() - p[0]), abs(m.back() - m[0]));
    printf("%d", ret);

    return 0;
}
