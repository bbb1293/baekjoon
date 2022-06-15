#include <bits/stdc++.h>

using namespace std;

int n;
int num[1000];
set<int> two_sum;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    int ret = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            two_sum.insert(num[i] + num[j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (two_sum.count(num[j] - num[i]) != 0) {
                ret = max(ret, num[j]);
            }
        }
    }

    printf("%d", ret);

    return 0;
}
