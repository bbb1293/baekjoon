#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6;
int n;
int h[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }

    stack<int> num;

    long long ret = 0;
    for (int i = 0; i < n; i++) {
        int ori_size = num.size();

        while (!num.empty() && num.top() < h[i]) {
            num.pop();
        }

        ret +=
            min(ori_size, ori_size - (int)num.size() + 1);

        num.push(h[i]);
    }

    printf("%lld", ret);

    return 0;
}