#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
int cnt[26];
char s[MAXN + 1], target[] = "HIARC";

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    scanf("%s", s);

    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'A']++;
    }

    int ret = n;
    for (int i = 0; i < 5; i++) {
        ret = min(ret, cnt[target[i] - 'A']);
    }

    printf("%d", ret);

    return 0;
}
