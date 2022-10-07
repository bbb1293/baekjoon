#include <bits/stdc++.h>

using namespace std;

int n;
char s[1001];
bool visited[1000];
vector<int> edges[1000], ret;

void dfs(int cur) {
    if (visited[cur]) {
        return;
    }
    visited[cur] = true;

    for (auto v : edges[cur]) {
        dfs(v);
    }

    ret.push_back(cur);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int y = 0; y < n; y++) {
        scanf("%s", s);

        for (int x = 0; x < n; x++) {
            if (s[x] == '1') {
                edges[y].push_back(x);
            }
        }
    }

    dfs(0);

    if (ret.size() == n) {
        for (auto r : ret) {
            printf("%d ", r);
        }
    } else {
        printf("impossible");
    }

    return 0;
}