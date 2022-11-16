#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e9;
int n;
char s[2000];

long long get_num(int from, int to) {
    long long num = 0;
    for (int i = from; i < to; i++) {
        num *= 10;
        num += (s[i] - '0');
    }

    return num;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    printf("? %lld\n", MAXN);
    fflush(stdout);

    scanf(" %s", s);

    int s_len = strlen(s);
    int rest = s_len - 9 * n;

    printf("!");
    for (int i = n - 1; i >= 0; i--) {
        printf(" %lld",
               get_num(rest + 9 * i, rest + 9 * (i + 1)));
    }
    printf(" %lld\n", get_num(0, rest));

    fflush(stdout);

    return 0;
}