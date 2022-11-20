#include<iostream>

using namespace std;

int n;

void move(int len, int st, int b, int ed) {
        if (len == 1) {
                printf("%d %d\n", st, ed);
                return;
        }

        move(len - 1, st, ed, b);
        printf("%d %d\n", st, ed);
        move(len - 1, b, st, ed);
}

int main() {
        scanf("%d", &n);
        int a = 1;
        for (int i = 1; i < n; i++) {
                a = 2 * a + 1;
        }

        printf("%d\n", a);
        move(n, 1, 2, 3);
        return 0;
}
