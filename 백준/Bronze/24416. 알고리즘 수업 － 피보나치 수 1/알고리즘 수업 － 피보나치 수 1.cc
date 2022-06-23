#include <bits/stdc++.h>

using namespace std;

int n;

int fib1(int k) {
    if (k == 1 || k == 2) {
        return 1;
    }

    return fib1(k - 1) + fib1(k - 2);
}

int fib2(int k) { return k - 2; }

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cout << fib1(n) << ' ' << fib2(n);

    return 0;
}
