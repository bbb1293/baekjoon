#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n;
char plain[MAXN + 1], code[MAXN + 1];
char key[MAXN + 1];

bool is_valid(int len) {
    for (int i = len; i < n; i++) {
        if (key[i - len] != key[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%s", plain);
    scanf("%s", code);

    n = strlen(plain);

    for (int i = 0; i < n; i++) {
        key[i] = (code[i] - plain[i] + 26) % 26;
        if (key[i] == 0) {
            key[i] += 26;
        }

        key[i] -= 1;
        key[i] += 'A';
    }

    for (int i = 1; i <= n; i++) {
        if (!(n % i) && is_valid(i)) {
            for (int j = 0; j < i; j++) {
                printf("%c", key[j]);
            }
            return 0;
        }
    }

    return 0;
}