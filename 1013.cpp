#include <bits/stdc++.h>

using namespace std;

char history[201];
int state[9][2] = {{7, 1}, {2, -1}, {3, -1}, {3, 4}, {7, 5},
                   {8, 5}, {7, 1},  {-1, 6}, {3, 6}};

int main() {
    freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf(" %s", history);

        int cur_state = 0, idx = 0;
        while (history[idx] != '\0') {
            cur_state = state[cur_state][history[idx++] - '0'];

            if (cur_state == -1) {
                break;
            }
        }

        if ((cur_state == 4) || (cur_state == 5) || (cur_state == 6)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}