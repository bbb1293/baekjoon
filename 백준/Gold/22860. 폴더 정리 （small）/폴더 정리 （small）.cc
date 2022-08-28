#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;
int n, m, idx = 0;
int file_num[MAXN + 1];
set<string> unique_file[MAXN + 1];
map<string, int> dir_to_idx;
vector<int> children[MAXN + 1];

int get_idx(string &s) {
    if (dir_to_idx.count(s) == 0) {
        dir_to_idx[s] = idx++;
    }

    return dir_to_idx[s];
}

void dfs(int cur) {
    for (auto c : children[cur]) {
        dfs(c);
        file_num[cur] += file_num[c];

        for (auto f : unique_file[c]) {
            unique_file[cur].insert(f);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dir_to_idx["main"] = idx++;

    cin >> n >> m;
    n += m;

    while (n--) {
        string a, b;
        int kind;

        cin >> a >> b >> kind;

        if (kind == 0) {
            int a_idx = get_idx(a);
            file_num[a_idx]++;
            unique_file[a_idx].insert(b);
        } else {
            int a_idx = get_idx(a);
            int b_idx = get_idx(b);

            children[a_idx].push_back(b_idx);
        }
    }

    dfs(0);

    int q;
    cin >> q;

    while (q--) {
        string whole;
        cin >> whole;

        string cur = "main";
        for (int i = 4; i < whole.size(); i++) {
            if (whole[i] == '/') {
                cur = "";
            } else {
                cur += whole[i];
            }
        }

        int cur_idx = dir_to_idx[cur];
        cout << unique_file[cur_idx].size() << ' ' << file_num[cur_idx] << '\n';
    }

    return 0;
}
