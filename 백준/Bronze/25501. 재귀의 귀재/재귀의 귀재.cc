#include <bits/stdc++.h>

using namespace std;

int cnt;
char s[1001];

int recursion(const char *s, int l, int r) {
    cnt++;
    if (l >= r)
        return 1;
    else if (s[l] != s[r])
        return 0;
    else
        return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char *s) { return recursion(s, 0, strlen(s) - 1); }

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%s", s);

        cnt = 0;

        if (isPalindrome(s)) {
            printf("1 %d\n", cnt);
        } else {
            printf("0 %d\n", cnt);
        }
    }

    return 0;
}
