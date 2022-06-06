#include <bits/stdc++.h>

using namespace std;

int h, m;
double s;
char op[10];
int heal[6];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d:%d", &h, &m);
    for (int i = 0; i < 6; i++) {
        scanf("%d", &heal[i]);
    }

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%lf %s", &s, op);

        if (op[0] == '^') {
            int cur_m = m + s / 60;
            int cur_h = (h + (cur_m / 60)) % 12;

            heal[cur_h / 2] = 0;

        } else if (op[1] == '0') {
            m += ((op[0] - '0') * 10);
            h += (m / 60);
            h %= 12;
            m %= 60;
        } else {
            h += ((op[0] - '0'));
            h %= 12;
        }
    }

    int ret = 0;
    for (int i = 0; i < 6; i++) {
        ret += heal[i];
    }

    printf("%d", min(ret, 100));

    return 0;
}