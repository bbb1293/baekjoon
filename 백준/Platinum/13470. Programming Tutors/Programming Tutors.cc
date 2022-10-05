#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100;
int n;
int dist[MAXN][MAXN], connected[MAXN];
bool used[MAXN];
pair<int, int> student[MAXN], tutor[MAXN];
vector<int> edges[MAXN];

int get_dist(int i, int j) {
    return abs(student[i].first - tutor[j].first) +
           abs(student[i].second - tutor[j].second);
}

void set_dist() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = get_dist(i, j);
        }
    }
}

bool kuhn(int cur) {
    if (used[cur]) {
        return false;
    }

    used[cur] = true;

    for (auto v : edges[cur]) {
        if (connected[v] == -1 || kuhn(connected[v])) {
            connected[v] = cur;
            return true;
        }
    }

    return false;
}

bool is_possible(int mid) {
    for (int i = 0; i < n; i++) {
        edges[i].clear();
        for (int j = 0; j < n; j++) {
            if (dist[i][j] <= mid) {
                edges[i].push_back(j);
            }
        }
    }

    memset(connected, -1, sizeof(connected));
    for (int i = 0; i < n; i++) {
        memset(used, 0, sizeof(used));
        kuhn(i);
    }

    for (int i = 0; i < n; i++) {
        if (connected[i] == -1) {
            return false;
        }
    }

    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &student[i].first,
              &student[i].second);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &tutor[i].first, &tutor[i].second);
    }

    set_dist();
    int left = 0, right = 1e9;
    int target = right;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (is_possible(mid)) {
            target = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d", target);

    return 0;
}