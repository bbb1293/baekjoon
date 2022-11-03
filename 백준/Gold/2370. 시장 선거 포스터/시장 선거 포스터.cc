#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
int n;
pair<int, int> lr[MAXN];
map<int, int> m;
int cnt[MAXN], color[2 * MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &lr[i].first, &lr[i].second);

        m[lr[i].first] = 1;
        m[lr[i].second] = 1;
    }

    int idx = 0;
    for (auto &m_pair : m) {
        m_pair.second = idx++;
    }

    memset(color, -1, sizeof(color));

    for (int i = 0; i < n; i++) {
        lr[i].first = m[lr[i].first];
        lr[i].second = m[lr[i].second];

        cnt[i] = lr[i].second - lr[i].first + 1;

        for (int j = lr[i].first; j <= lr[i].second; j++) {
            if (color[j] != -1) {
                cnt[color[j]]--;
            }
            color[j] = i;
        }
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i]) {
            ret++;
        }
    }

    printf("%d", ret);

    return 0;
}