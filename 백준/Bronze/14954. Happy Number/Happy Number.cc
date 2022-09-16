#include <bits/stdc++.h>

using namespace std;

int n;
bool visited[1000];

int get_next(int cur) {
    int ret = 0;
    while (cur) {
        ret += (cur % 10) * (cur % 10);

        cur /= 10;
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    while (n != 1) {
        n = get_next(n);

        if (visited[n]) {
            break;
        }
        visited[n] = true;
    }

    if (n != 1) {
        printf("UN");
    }
    printf("HAPPY");

    return 0;
}