#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int n;
long long p[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &p[i]);
        sum += p[i];
    }

    long long left = 0, right = sum;
    long long ret = right;

    while (left <= right) {
        long long mid = (left + right) / 2;

        long long rest = mid;
        long long cashback = 0;

        bool possible = true;
        for (int i = 0; i < n; i++) {
            if (rest >= p[i]) {
                rest -= p[i];
                cashback += p[i];
            } else {
                if (p[i] - rest <= (cashback / 10)) {
                    cashback += rest;
                    cashback -= ((p[i] - rest) * 10);
                    rest = 0;
                } else {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            ret = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%lld", ret);

    return 0;
}
