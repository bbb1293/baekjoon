#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5;
char s[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%s", s);

    int ret = 0;
    int n = strlen(s);

    queue<int> q[2];
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            q[0].push(i);
        } else if (s[i] == 'B') {
            q[1].push(i);
        } else {
            if (!q[1].empty()) {
                q[1].pop();
                ret++;
            }
        }
    }

    while (!q[0].empty() && !q[1].empty()) {
        while (!q[1].empty() &&
               q[0].front() > q[1].front()) {
            q[1].pop();
        }

        if (!q[1].empty()) {
            q[0].pop();
            q[1].pop();
            ret++;
        }
    }

    printf("%d", ret);

    return 0;
}
