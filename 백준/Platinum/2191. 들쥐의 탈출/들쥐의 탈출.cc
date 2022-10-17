#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;
};

const int MAXN = 100;
int n, m;
double s, v;
int p[MAXN];
bool visited[MAXN];
Point rat[MAXN], hole[MAXN];
vector<int> edges[MAXN];

bool kuhn(int cur) {
    if (visited[cur]) {
        return false;
    }

    visited[cur] = true;

    for (auto v : edges[cur]) {
        if (p[v] == -1 || kuhn(p[v])) {
            p[v] = cur;
            return true;
        }
    }

    return false;
}

int match_bipartite() {
    memset(p, -1, sizeof(p));

    int ret = 0;
    for (int i = 0; i < n; i++) {
        memset(visited, 0, sizeof(visited));
        if (kuhn(i)) {
            ret++;
        }
    }

    return ret;
}

double get_dist(int i, int j) {
    double x_diff = rat[i].x - hole[j].x;
    double y_diff = rat[i].y - hole[j].y;

    return x_diff * x_diff + y_diff * y_diff;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d %lf %lf", &n, &m, &s, &v);

    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &rat[i].x, &rat[i].y);
    }

    for (int i = 0; i < m; i++) {
        scanf("%lf %lf", &hole[i].x, &hole[i].y);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (get_dist(i, j) <= s * v * s * v) {
                edges[i].push_back(j);
            }
        }
    }

    printf("%d", n - match_bipartite());

    return 0;
}