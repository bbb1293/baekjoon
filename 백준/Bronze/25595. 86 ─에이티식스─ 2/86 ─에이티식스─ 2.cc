#include <bits/stdc++.h>

using namespace std;

int n;
int state[100][100];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    int parity;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%d", &state[y][x]);

            if (state[y][x] == 2) {
                parity = (y + x) & 1;
            }
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (state[y][x] == 1) {
                if (((y + x) & 1) == parity) {
                    printf("Kiriya");
                    return 0;
                }
            }
        }
    }

    printf("Lena");

    return 0;
}
