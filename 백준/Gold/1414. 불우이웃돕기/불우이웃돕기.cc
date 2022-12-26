#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int n, p[MAXN];
char tmp[MAXN + 1];
priority_queue<pair<int, pair<int, int> > > pq;

void init_p() {
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
}

int get_p(int cur) {
    while (cur != p[cur]) {
        p[cur] = p[p[cur]];
        cur = p[cur];
    }

    return cur;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    init_p();

    int sum = 0;
    for (int y = 0; y < n; y++) {
        scanf("%s", tmp);
        for (int x = 0; x < n; x++) {
            if ('a' <= tmp[x] && tmp[x] <= 'z') {
                int dist = tmp[x] - 'a' + 1;
                pq.push({-dist, {y, x}});
                sum += dist;
            } else if (tmp[x] != '0') {
                int dist = tmp[x] - 'A' + 27;
                pq.push({-dist, {y, x}});
                sum += dist;
            }
        }
    }

    int cnt = 0;
    while (!pq.empty()) {
        int dist = -pq.top().first;
        auto [y, x] = pq.top().second;
        pq.pop();

        int y_p = get_p(y);
        int x_p = get_p(x);

        if (y_p != x_p) {
            cnt++;
            p[y_p] = x_p;
            sum -= dist;
        }
    }

    if (cnt == n - 1) {
        printf("%d", sum);
    } else {
        printf("-1");
    }

    return 0;
}