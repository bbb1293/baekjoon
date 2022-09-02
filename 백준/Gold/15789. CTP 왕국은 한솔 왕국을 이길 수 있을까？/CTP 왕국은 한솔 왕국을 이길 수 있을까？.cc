#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, m;
int c, h, k;
vector<int> edges[MAXN + 1];
int p[MAXN + 1], group_size[MAXN + 1];

void init_p() {
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        group_size[i] = 1;
    }
}

int get_p(int a) {
    while (a != p[a]) {
        p[a] = p[p[a]];
        a = p[a];
    }
    return a;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    init_p();

    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);

        int a_p = get_p(a);
        int b_p = get_p(b);

        if (a_p != b_p) {
            group_size[b_p] += group_size[a_p];
            p[a_p] = b_p;
        }
    }

    scanf("%d %d %d", &c, &h, &k);

    int c_p = get_p(c);
    int h_p = get_p(h);

    vector<int> cnt;
    for (int i = 1; i <= n; i++) {
        if (p[i] == i && i != c_p && i != h_p) {
            cnt.push_back(group_size[i]);
        }
    }

    sort(cnt.begin(), cnt.end());

    int ret = group_size[c_p];
    for (int i = cnt.size() - 1; i >= 0; i--) {
        if (k == 0) {
            break;
        }

        ret += cnt[i];
        k--;
    }

    printf("%d", ret);

    return 0;
}
