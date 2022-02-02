#include <bits/stdc++.h>

using namespace std;

int a[50], b[50];
int pos[1001];

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }

    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        pos[b[i]] = i;
    }

    for (int i = n - 1; i >= 0; i--) {
        pos[a[i]]--;
        a[i] = pos[a[i]] + 1;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}