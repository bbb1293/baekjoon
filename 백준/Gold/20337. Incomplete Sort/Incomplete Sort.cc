#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n, a[MAXN + 1], pos[MAXN + 1];
int check[MAXN + 1];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }

    printf("3\n");
    for (int iter = 0; iter < 3; iter++) {
        vector<int> selected, position;
        for (int i = 1 + (n / 4) * iter; i <= (n / 4) * (iter + 1); i++) {
            if (!check[i]) {
                selected.push_back(i);
                position.push_back(pos[i]);
                check[i] = true;
            }

            if (!check[a[i]]) {
                selected.push_back(a[i]);
                position.push_back(i);
                check[a[i]] = true;
            }
        }

        for (int i = n; i >= 1; i--) {
            if (selected.size() == n / 2) {
                break;
            }

            if (!check[i]) {
                selected.push_back(i);
                position.push_back(pos[i]);
            }
        }

        sort(selected.begin(), selected.end());
        sort(position.begin(), position.end());

        for (int i = 0; i < n / 2; i++) {
            a[position[i]] = selected[i];
            pos[selected[i]] = position[i];
        }

        for (auto p : position) {
            printf("%d ", p);
        }
        printf("\n");

        memset(check, 0, sizeof(check));
    }

    return 0;
}