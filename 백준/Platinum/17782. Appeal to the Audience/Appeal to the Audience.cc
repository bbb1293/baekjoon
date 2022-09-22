#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, k;
int p[MAXN];
long long skill[MAXN];
bool visited[MAXN];
vector<int> children[MAXN], cnt;
vector<pair<int, int> > depth_node;

void dfs(int cur, int depth = 0) {
    if (children[cur].empty()) {
        depth_node.push_back({depth, cur});
    } else {
        for (auto child : children[cur]) {
            dfs(child, depth + 1);
        }
    }
}

int upward(int cur) {
    if (visited[cur]) {
        return 0;
    }

    visited[cur] = true;
    return 1 + upward(p[cur]);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);

    for (int i = 0; i < k; i++) {
        scanf("%lld", &skill[i]);
    }

    for (int i = 1; i < n; i++) {
        scanf("%d", &p[i]);
        children[p[i]].push_back(i);
    }

    dfs(0);

    sort(depth_node.begin(), depth_node.end());

    visited[0] = true;
    for (int i = depth_node.size() - 1; i >= 0; i--) {
        int cur = depth_node[i].second;
        cnt.push_back(upward(cur));
    }

    sort(cnt.begin(), cnt.end());
    sort(skill, skill + k);

    long long ret = 0;
    for (int i = 0; i < k; i++) {
        ret += (skill[i] * cnt[i]);
    }

    printf("%lld", ret);

    return 0;
}