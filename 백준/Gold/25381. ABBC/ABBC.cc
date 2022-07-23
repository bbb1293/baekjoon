#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5;
char s[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%s", s);

    int s_len = strlen(s);
    int ret = 0;

    queue<int> b;
    for (int i = 0; i < s_len; i++) {
        if (s[i] == 'B') {
            b.push(i);
        } else if (s[i] == 'C') {
            if (!b.empty()) {
                ret++;
                b.pop();
            }
        }
    }

    for (int i = 0; i < s_len; i++) {
        if (s[i] == 'A') {
            if (!b.empty() && b.front() < i) {
                b.pop();
            }

            if (!b.empty()) {
                ret++;
                b.pop();
            }
        }
    }

    printf("%d", ret);

    return 0;
}
