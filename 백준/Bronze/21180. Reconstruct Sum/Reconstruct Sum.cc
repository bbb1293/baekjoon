#include <bits/stdc++.h>

using namespace std;

int n;
set<int> s;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    int sum = 0;
    while (n--) {
        int num;
        scanf("%d", &num);

        sum += num;
        s.insert(num);
    }

    if (!(sum & 1) && s.count(sum / 2)) {
        printf("%d", sum / 2);
    } else {
        printf("BAD");
    }

    return 0;
}