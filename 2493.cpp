#include <bits/stdc++.h>

using namespace std;

int n;
int height[500001];

int main() {
    freopen("input.txt", "r", stdin);

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &height[i]);
    }

    stack<pair<int, int> > s;

    for (int i = n; i > 0; i--) {
        while (!s.empty() && (height[i] > s.top().first)) {
            height[s.top().second] = i;
            s.pop();
        }
        s.push({height[i], i});
        height[i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", height[i]);
    }

    return 0;
}