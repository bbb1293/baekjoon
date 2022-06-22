#include <bits/stdc++.h>

using namespace std;

int l;
int pi[1000000];
char s[1000001];

int main() {
    scanf("%d", &l);
    scanf("%s", s);

    for (int i = 1, j = 0; i < l; i++) {
        while (j && (s[j] != s[i])) {
            j = pi[j - 1];
        }

        if (s[j] == s[i]) {
            j++;
        }

        pi[i] = j;
    }

    printf("%d", l - pi[l - 1]);

    return 0;
}