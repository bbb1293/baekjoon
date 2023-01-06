#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n, q;
pair<int, int> xa[MAXN], cand[MAXN];
long long l[MAXN], r[MAXN];
long long l_cnt[MAXN], r_cnt[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &xa[i].second, &xa[i].first);
    }

    for (int i = 0; i < q; i++) {
        scanf("%d", &cand[i].first);
        cand[i].second = i;
    }

    sort(xa, xa + n);
    sort(cand, cand + q);

    int idx = 0;
    for (int i = 0; i < q; i++) {
        if (i != 0) {
            l[cand[i].second] = l[cand[i - 1].second];
            l_cnt[cand[i].second] =
                l_cnt[cand[i - 1].second];
            l[cand[i].second] +=
                (l_cnt[cand[i].second] *
                 (cand[i].first - cand[i - 1].first));
        }

        while (idx < n && xa[idx].first <= cand[i].first) {
            l_cnt[cand[i].second] += xa[idx].second;
            l[cand[i].second] +=
                ((long long)(cand[i].first -
                             xa[idx].first) *
                 xa[idx].second);
            idx++;
        }
    }

    idx = n - 1;
    for (int i = q - 1; i >= 0; i--) {
        if (i != q - 1) {
            r[cand[i].second] = r[cand[i + 1].second];
            r_cnt[cand[i].second] =
                r_cnt[cand[i + 1].second];
            r[cand[i].second] +=
                (r_cnt[cand[i].second] *
                 (cand[i + 1].first - cand[i].first));
        }

        while (idx >= 0 && cand[i].first <= xa[idx].first) {
            r_cnt[cand[i].second] += xa[idx].second;
            r[cand[i].second] +=
                ((long long)(xa[idx].first -
                             cand[i].first) *
                 xa[idx].second);
            idx--;
        }
    }

    for (int i = 0; i < q; i++) {
        printf("%lld\n", l[i] + r[i]);
    }

    return 0;
}