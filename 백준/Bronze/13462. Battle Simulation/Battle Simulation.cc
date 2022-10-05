#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
char mon[MAXN + 1], ret[MAXN + 1];
map<char, int> convert = {{'R', 0}, {'B', 1}, {'L', 2}};
char counter[] = "SKH";
bool cnt[3];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%s", mon);

    int mon_len = strlen(mon);
    int cur = 0;
    for (int i = 0; i < mon_len; i++) {
        if (i + 2 < mon_len) {
            memset(cnt, 0, sizeof(cnt));

            int possible = 0;
            for (int j = 0; j < 3; j++) {
                if (!cnt[convert[mon[i + j]]]) {
                    possible++;
                }

                cnt[convert[mon[i + j]]] = true;
            }

            if (possible == 3) {
                ret[cur++] = 'C';
                i += 2;
                continue;
            }
        }

        ret[cur++] = counter[convert[mon[i]]];
    }

    printf("%s", ret);

    return 0;
}