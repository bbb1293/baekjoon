#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, idx;
map<string, int> indices;
string names[2 * MAXN];
vector<int> edges[2 * MAXN];
vector<string> ret;
bool visited[2 * MAXN];

void dfs(int cur) {
    for (auto v : edges[cur]) {
        if (!visited[v]) {
            visited[v] = true;
            ret.push_back(names[v]);
            dfs(v);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b, c;
        cin >> a >> b >> c;

        if (!indices.count(a)) {
            indices[a] = idx;
            names[idx++] = a;
        }

        if (!indices.count(c)) {
            indices[c] = idx;
            names[idx++] = c;
        }

        edges[indices[a]].push_back(indices[c]);
    }

    if (indices.count("Baba")) {
        int target = indices["Baba"];
        visited[target] = true;
        dfs(target);

        sort(ret.begin(), ret.end());

        for (auto r : ret) {
            cout << r << "\n";
        }
    }

    return 0;
}