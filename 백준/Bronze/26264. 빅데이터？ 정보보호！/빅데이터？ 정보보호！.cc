#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
int n;
char s[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    scanf("%s", s);

    int big = 0, sec = 0;
    int cur_idx = 0;

    while (s[cur_idx]) {
        if (s[cur_idx] == 'b') {
            big++;
            cur_idx += 7;
        } else {
            sec++;
            cur_idx += 8;
        }
    }

    if (big > sec) {
        printf("bigdata?");
    } else if (sec > big) {
        printf("security!");
    } else {
        printf("bigdata? security!");
    }

    return 0;
}