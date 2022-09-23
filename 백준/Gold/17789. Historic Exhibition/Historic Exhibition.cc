#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
int p, v;
int ret[MAXN];
pair<int, int> c[MAXN];
pair<pair<int, int>, int> ab[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &p, &v);

    for (int i = 0; i < p; i++) {
        scanf("%d %d", &ab[i].first.first, &ab[i].first.second);

        if (ab[i].first.first > ab[i].first.second) {
            swap(ab[i].first.first, ab[i].first.second);
        }
        ab[i].second = i + 1;
    }

    for (int i = 0; i < v; i++) {
        scanf("%d", &c[i].first);
        c[i].second = i;
    }

    sort(ab, ab + p);
    sort(c, c + v);

    int cur = 0;
    for (int i = 0; i < v; i++) {
        bool found = false;
        while (cur < p) {
            if (ab[cur].first.first == c[i].first ||
                ab[cur].first.second == c[i].first) {
                ret[c[i].second] = ab[cur].second;
                found = true;
                cur++;
                break;
            }
            cur++;
        }

        if (!found) {
            printf("impossible");
            return 0;
        }
    }

    for (int i = 0; i < v; i++) {
        printf("%d\n", ret[i]);
    }

    return 0;
}