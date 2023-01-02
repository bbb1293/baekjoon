#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
bool ko_win[MAXN + 1];

void set_win() {
    ko_win[0] = false;
    ko_win[1] = true;

    for (int i = 2; i <= MAXN; i++) {
        for (int j = 1; j * j <= i; j++) {
            if (!ko_win[i - j * j]) {
                ko_win[i] = true;
                break;
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    set_win();

    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);

        if (ko_win[n]) {
            printf("koosaga\n");
        } else {
            printf("cubelover\n");
        }
    }

    return 0;
}
