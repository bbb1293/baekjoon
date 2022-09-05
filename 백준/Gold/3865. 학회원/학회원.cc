#include <bits/stdc++.h>

using namespace std;

int n, idx;
vector<int> children[2000];
bool used[2000];

int get_size(int cur) {
    int ret = 0;
    for (auto child : children[cur]) {
        if (used[child]) {
            continue;
        }
        if (children[child].empty()) {
            ret++;
            used[child] = true;
        } else {
            ret += get_size(child);
            used[child] = true;
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        for (int i = 0; i < idx; i++) {
            children[i].clear();
        }

        idx = 0;
        unordered_map<string, int> m;
        memset(used, 0, sizeof(used));

        while (n--) {
            string input;
            cin >> input;

            string group;
            int i = 0;
            for (; i < input.length(); i++) {
                if (input[i] == ':') {
                    break;
                }
                group += input[i];
            }

            if (m.count(group) == 0) {
                m[group] = idx++;
            }

            int group_idx = m[group];

            string tmp;
            for (i = i + 1; i < input.length(); i++) {
                if (input[i] == ',' || input[i] == '.') {
                    if (m.count(tmp) == 0) {
                        m[tmp] = idx++;
                    }
                    children[group_idx].push_back(m[tmp]);
                    tmp.clear();
                } else {
                    tmp += input[i];
                }
            }
        }

        cout << get_size(0) << '\n';
    }

    return 0;
}
