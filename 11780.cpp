#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n;
vector<vector<int> > cost(101, vector<int>(101, INF));
vector<vector<int> > path(101, vector<int>(101, -1));

void set_cost() {
    for (int i = 1; i <= n; i++) {
        cost[i][i] = 0;
        path[i][i] = i;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int cand_cost = cost[i][k] + cost[k][j];
                if (cost[i][j] > cand_cost) {
                    cost[i][j] = cand_cost;
                    path[i][j] = path[i][k];
                }
            }
        }
    }
}

vector<int> get_path(int start, int end) {
    if (path[start][end] == -1) {
        return {};
    }

    vector<int> ret = {start};
    while (start != end) {
        start = path[start][end];
        ret.push_back(start);
    }

    return ret;
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    int m;
    scanf("%d", &m);

    while (m--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (cost[a][b] > c) {
            cost[a][b] = c;
            path[a][b] = b;
        }
    }

    set_cost();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (cost[i][j] >= INF) {
                printf("0 ");
            } else {
                printf("%d ", cost[i][j]);
            }
        }
        printf("\n");
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((cost[i][j] >= INF) || (cost[i][j] == 0)) {
                printf("0\n");
                continue;
            }
            vector<int> tmp = get_path(i, j);
            printf("%d", tmp.size());
            for (auto el : tmp) {
                printf(" %d", el);
            }
            printf("\n");
        }
    }

    return 0;
}