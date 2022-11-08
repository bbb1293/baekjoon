#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n;
int p[MAXN];
char s[MAXN + 1];

int get_cnt(int left, int right) {
    if (left + 1 == right) {
        return 1;
    }

    int ret = 0;
    for (int i = left + 1; i < right; i = p[i] + 1) {
        ret = max(ret, get_cnt(i, p[i]));
    }

    return ret + 1;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    scanf("%s", s);

    stack<int> pos;
    pos.push(0);
    int cnt = -1;
    if (s[0] == '(') {
        cnt = 1;
    }

    for (int i = 1; i < n; i++) {
        int add = 1;
        if (s[i] != '(') {
            add = -1;
        }

        if (add * cnt >= 0) {
            pos.push(i);
        } else {
            p[i] = pos.top();
            p[pos.top()] = i;
            pos.pop();
        }
        cnt += add;
    }

    if (cnt != 0) {
        printf("-1");

        return 0;
    }

    printf("%d", get_cnt(-1, n) - 1);

    return 0;
}