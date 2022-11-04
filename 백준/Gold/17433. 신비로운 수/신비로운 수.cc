#include <bits/stdc++.h>

using namespace std;

int n;
int num[2000];

int get_gcd(int a, int b) {
    if (b < a) {
        swap(a, b);
    }

    while (a != 0) {
        int c = a % b;
        b = a;
        a = c;
    }

    return b;
}

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        bool all_equal = true;
        for (int i = 0; i < n; i++) {
            scanf("%d", &num[i]);

            if (i != 0) {
                all_equal &= (num[i - 1] == num[i]);
            }
        }

        if (all_equal) {
            printf("INFINITY\n");
        } else {
            sort(num, num + n);

            int gcd = -1;
            for (int i = 1; i < n; i++) {
                if (num[i] != num[i - 1]) {
                    if (gcd == -1) {
                        gcd = num[i] - num[i - 1];
                    } else {
                        gcd = get_gcd(gcd,
                                      num[i] - num[i - 1]);
                    }
                }
            }

            printf("%d\n", gcd);
        }
    }

    return 0;
}