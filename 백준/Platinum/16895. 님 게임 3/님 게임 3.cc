#include <bits/stdc++.h>

using namespace std;

int m;
int num[1000];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &m);

    int ret = 0;
    for (int i = 0; i < m; i++) {
        scanf("%d", &num[i]);
        ret ^= num[i];
    }

    int cnt = 0;
    for (int i = 0; i < m; i++) {
        int tmp = ret ^ num[i];
        for (int j = 0; j < num[i]; j++) {
            if ((tmp ^ j) == 0) {
                cnt++;
            }
        }
    }

    printf("%d", cnt);

    return 0;
}
