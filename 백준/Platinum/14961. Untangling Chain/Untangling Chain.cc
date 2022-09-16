#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
int n;
int num[4], pos[2];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    int cur_dir = 0;

    for (int i = 0; i < n; i++) {
        int l, dir;
        scanf("%d %d", &l, &dir);

        if (cur_dir < 2) {
            num[cur_dir]++;
            printf("%d ", num[cur_dir] - pos[cur_dir & 1]);
            pos[cur_dir & 1] = num[cur_dir];

        } else {
            num[cur_dir]--;
            printf("%d ", pos[cur_dir & 1] - num[cur_dir]);
            pos[cur_dir & 1] = num[cur_dir];
        }

        cur_dir = (cur_dir + dir + 4) % 4;
    }

    return 0;
}