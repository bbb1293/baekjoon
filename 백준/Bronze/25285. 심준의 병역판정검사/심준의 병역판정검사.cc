#include <bits/stdc++.h>

using namespace std;

double a, b;

int main() {
    // freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%lf %lf", &a, &b);

        double c = (10000 * b) / (a * a);

        if (a < 140.1) {
            printf("6\n");
        } else if (a < 146) {
            printf("5\n");
        } else if (a < 159 || 204 <= a) {
            printf("4\n");
        } else if (a < 161) {
            if (c < 16 || 35 <= c) {
                printf("4\n");
            } else {
                printf("3\n");
            }
        } else {
            if (20 <= c && c < 25) {
                printf("1\n");
            } else if (18.5 <= c && c < 30) {
                printf("2\n");
            } else if (16 <= c && c < 35) {
                printf("3\n");
            } else {
                printf("4\n");
            }
        }
    }

    return 0;
}
