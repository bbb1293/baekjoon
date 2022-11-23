#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e7;
char s[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%s", s);

    long long ret = 0, cur = -1;

    for (int i = 0; s[i]; i++) {
        if (s[i] == '(') {
            cur++;
        } else {
            if (s[i - 1] == '(') {
                ret += cur;
            }
            cur--;
        }
    }

    printf("%lld", ret);

    return 0;
}
