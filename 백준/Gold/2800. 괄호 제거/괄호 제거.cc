#include <bits/stdc++.h>

using namespace std;

string s;
stack<int> in_pos;
vector<pair<int, int> > in_out_pos;
bool del[201];
set<string> ret;

void solve(int cur, bool once) {
    if (cur == in_out_pos.size()) {
        if (!once) {
            return;
        }

        string tmp = "";
        for (int i = 0; s[i]; i++) {
            if (!del[i]) {
                tmp += s[i];
            }
        }
        ret.insert(tmp);

    } else {
        solve(cur + 1, once);

        del[in_out_pos[cur].first] = true;
        del[in_out_pos[cur].second] = true;

        solve(cur + 1, once | true);

        del[in_out_pos[cur].first] = false;
        del[in_out_pos[cur].second] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // freopen("input.txt", "r", stdin);

    cin >> s;

    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            in_pos.push(i);
        } else if (s[i] == ')') {
            in_out_pos.push_back({in_pos.top(), i});
            in_pos.pop();
        }
    }

    solve(0, false);

    for (auto &r : ret) {
        cout << r << '\n';
    }

    return 0;
}
