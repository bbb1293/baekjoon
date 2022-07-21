#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50;
int n;
vector<int> edges[MAXN];

int dfs(int cur) {
    vector<int> ret;

    for (auto v : edges[cur]) {
        ret.push_back(dfs(v));
    }
    sort(ret.begin(), ret.end());

    int max_num = 0, len = ret.size();
    for (int i = 0; i < len; i++) {
        max_num = max(max_num, ret[i] + len - i);
    }

    return max_num;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);

        if (i != 0) {
            edges[p].push_back(i);
        }
    }

    printf("%d", dfs(0));

    return 0;
}
