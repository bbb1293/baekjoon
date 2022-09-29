#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long x, y, r;
    cin >> x >> y >> r;
    cout << x + r << ' ' << y + r << '\n';
    cout << x + r << ' ' << y - r << '\n';
    cout << x - r << ' ' << y - r << '\n';
    cout << x - r << ' ' << y + r << '\n';
    return 0;
}