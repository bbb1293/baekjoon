#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5;
int n, m;
long long a[MAXN + 1];
map<long long, int> cnt1, cnt2;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);

        if (i != 1) {
            if (a[i - 1] <= a[i]) {
                if (a[i - 1] < a[i]) {
                    cnt1[a[i] - a[i - 1]]++;
                }

                if (!(a[i] % a[i - 1])) {
                    cnt2[a[i] / a[i - 1]]++;
                }
            }
        }
    }

    while (m--) {
        int i;
        long long x;

        scanf("%d %lld", &i, &x);

        if (i != n) {
            if (a[i] <= a[i + 1]) {
                if (a[i] < a[i + 1]) {
                    cnt1[a[i + 1] - a[i]]--;
                }

                if (!(a[i + 1] % a[i])) {
                    cnt2[a[i + 1] / a[i]]--;
                }
            }

            if (x <= a[i + 1]) {
                if (x < a[i + 1]) {
                    cnt1[a[i + 1] - x]++;
                }

                if (!(a[i + 1] % x)) {
                    cnt2[a[i + 1] / x]++;
                }
            }
        }

        if (i != 1) {
            if (a[i - 1] <= a[i]) {
                if (a[i - 1] < a[i]) {
                    cnt1[a[i] - a[i - 1]]--;
                }

                if (!(a[i] % a[i - 1])) {
                    cnt2[a[i] / a[i - 1]]--;
                }
            }

            if (a[i - 1] <= x) {
                if (a[i - 1] < x) {
                    cnt1[x - a[i - 1]]++;
                }

                if (!(x % a[i - 1])) {
                    cnt2[x / a[i - 1]]++;
                }
            }
        }

        a[i] = x;

        if (a[1] <= a[2]) {
            if (a[1] < a[2] && cnt1[a[2] - a[1]] == n - 1) {
                printf("+\n");
                continue;
            }

            if (!(a[2] % a[1]) && cnt2[a[2] / a[1]] == n - 1) {
                printf("*\n");
                continue;
            }
        }

        printf("?\n");
    }

    return 0;
}
