#include <bits/stdc++.h>

using namespace std;

int k, n;
bool non_prime[3000];

vector<int> solve() {
    int cnt = k;

    vector<int> ret;
    for (int i = 3; i < 3000 && cnt; i += 2) {
        if (!non_prime[i]) {
            for (int j = i + i; j < 3000; j += i) {
                non_prime[j] = true;
            }

            if (i > 2000) {
                ret.push_back(i);
                cnt--;
            }
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &k, &n);

    vector<int> ret = solve();

    for (int i = 0; i < k; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", 1 + ret[i] * j);
        }
        printf("\n");
    }

    return 0;
}
