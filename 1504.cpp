#include <bits/stdc++.h>

using namespace std;

const int INF = 98765432;
int n, e;
int mid_point1, mid_point2;
bool is_visited[801];
vector<int> dist;
vector<vector<int> > edge(801, vector<int>(801, INF));

void set_dijkstra(int start) {
    dist.assign(801, INF);
    memset(is_visited, 0, sizeof(is_visited));

    int cur = start;
    dist[cur] = 0;
    while (cur) {
        is_visited[cur] = true;
        int min_dist = INF, next_cand = 0;
        for (int i = 1; i <= n; i++) {
            if ((edge[cur][i] != INF) && (dist[i] > dist[cur] + edge[cur][i])) {
                dist[i] = dist[cur] + edge[cur][i];
            }
            if (!is_visited[i] && (min_dist > dist[i])) {
                min_dist = dist[i];
                next_cand = i;
            }
        }

        cur = next_cand;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d %d", &n, &e);

    while (e--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (edge[a][b] > c) {
            edge[a][b] = c;
            edge[b][a] = c;
        }
    }
    scanf("%d %d", &mid_point1, &mid_point2);

    set_dijkstra(mid_point1);
    int ret1 = dist[mid_point2] + dist[n], ret2 = dist[mid_point2] + dist[1];

    set_dijkstra(mid_point2);
    ret1 += dist[1];
    ret2 += dist[n];

    int ret = min(ret1, ret2);

    if (ret >= INF) {
        ret = -1;
    }
    printf("%d", ret);

    return 0;
}