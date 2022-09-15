#include <bits/stdc++.h>

using namespace std;

int n;
int num[1000000], pi[1000000];

void kmp() {
    int k = n - 1, p = 1;
    int j = 0;

    for (int i = 1; i < n; i++) {
        while (j > 0 && num[j] != num[i]) {
            j = pi[j - 1];
        }

        if (num[j] == num[i]) {
            j++;
        }

        pi[i] = j;

        if (j) {
            int cur_p = i + 1 - j, cur_k = n - 1 - i;

            if (cur_k + cur_p < k + p) {
                k = cur_k;
                p = cur_p;
            } else if (cur_k + cur_p == k + p && cur_p < p) {
                k = cur_k;
                p = cur_p;
            }
        }
    }

    printf("%d %d", k, p);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[n - i - 1]);
    }

    kmp();

    return 0;
}