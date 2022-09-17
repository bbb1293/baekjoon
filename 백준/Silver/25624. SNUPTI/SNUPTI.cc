#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<char> ret[27];
int check[26];
string tmp;
unordered_set<string> us;

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(check, -1, sizeof(check));

    cin >> n >> m;

    bool possible = true;
    for (int j = 0; j < m; j++) {
        cin >> tmp;

        if (us.find(tmp) != us.end()) {
            possible = false;
            continue;
        }
        us.insert(tmp);

        for (int i = 0; i < n && possible; i++) {
            if (check[tmp[i] - 'A'] == -1) {
                check[tmp[i] - 'A'] = i;
                ret[i].push_back(tmp[i]);
            }

            if (check[tmp[i] - 'A'] != i) {
                possible = false;
                break;
            }
        }
    }

    int sum = 1;
    for (int i = 0; i < n; i++) {
        sum *= ret[i].size();
    }

    if (sum != m) {
        possible = false;
    }

    if (possible) {
        printf("YES\n");

        for (int i = 0; i < n; i++) {
            sort(ret[i].begin(), ret[i].end());

            for (auto r : ret[i]) {
                printf("%c", r);
            }
            printf("\n");
        }

    } else {
        printf("NO");
    }

    return 0;
}
