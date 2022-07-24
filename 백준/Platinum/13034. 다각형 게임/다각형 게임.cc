#include <bits/stdc++.h>

using namespace std;

int n;
int nim[1001];
bool check[1001];

void init_win() {
    nim[0] = nim[1] = 0;
    nim[2] = 1;

    for (int i = 3; i <= n; i++) {
        memset(check, 0, sizeof(check));
        for (int j = 0; j <= i - 2; j++) {
            check[nim[j] ^ nim[i - j - 2]] = true;
        }

        for (int j = 0; j < 1000; j++) {
            if (!check[j]) {
                nim[i] = j;
                break;
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    init_win();

    if (nim[n]) {
        printf("1");
    } else {
        printf("2");
    }

    return 0;
}
