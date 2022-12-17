#include <bits/stdc++.h>

using namespace std;

int n, k;
long long fact[18], comb[18][18];
long long c[18][18], s[18][18];

void set_fact() {
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 18; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

void set_comb() {
    for (int i = 0; i < 18; i++) {
        comb[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            comb[i][j] =
                comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }
}

void set_c() {
    for (int i = 0; i < 18; i++) {
        for (int j = 0; j <= i; j++) {
            c[i][j] = fact[i - j];
        }
    }
}

void set_s() {
    set_fact();
    set_comb();
    set_c();

    for (int i = 1; i < 18; i++) {
        for (int j = 0; j <= i; j++) {
            for (int selected = 0; selected <= j;
                 selected++) {
                if (selected & 1) {
                    s[i][j] -= (comb[j][selected] *
                                c[i][selected]);
                } else {
                    s[i][j] += (comb[j][selected] *
                                c[i][selected]);
                }
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    set_s();

    while (t--) {
        int cur_t;
        scanf("%d %d %d", &cur_t, &n, &k);

        printf("%d %lld\n", cur_t, s[n][k]);
    }

    return 0;
}