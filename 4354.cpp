#include <bits/stdc++.h>

using namespace std;

int kmp[1000000];
char s[1000001];

int main() {
    freopen("input.txt", "r", stdin);
    while (true) {
        scanf("%s", s);

        if (!strcmp(s, ".")) {
            break;
        }

        memset(kmp, 0, sizeof(kmp));

        int s_len = strlen(s);
        for (int i = 1, j = 0; i < s_len; i++) {
            while (j && (s[j] != s[i])) {
                j = kmp[j - 1];
            }

            if (s[j] == s[i]) {
                j++;
            }
            kmp[i] = j;
        }

        if (s_len % (s_len - kmp[s_len - 1])) {
            printf("1\n");
        } else {
            printf("%d\n", s_len / (s_len - kmp[s_len - 1]));
        }
    }

    return 0;
}