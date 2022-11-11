#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
char w[MAXN + 1];
int k;
vector<int> pos[26];

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%s", w);
        scanf("%d", &k);

        int w_len = strlen(w);

        for (int i = 0; i < 26; i++) {
            pos[i].clear();
        }

        for (int i = 0; i < w_len; i++) {
            pos[w[i] - 'a'].push_back(i);
        }

        int ret[2] = {MAXN, 0};

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j + k - 1 < pos[i].size();
                 j++) {
                ret[0] = min(ret[0], pos[i][j + k - 1] -
                                         pos[i][j] + 1);
                ret[1] = max(ret[1], pos[i][j + k - 1] -
                                         pos[i][j] + 1);
            }
        }

        if (ret[1] == 0) {
            printf("-1\n");
        } else {
            printf("%d %d\n", ret[0], ret[1]);
        }
    }

    return 0;
}