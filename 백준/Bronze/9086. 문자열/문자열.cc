#include <bits/stdc++.h>

using namespace std;

string s;

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> s;

        cout << s[0] << s.back() << '\n';
    }

    return 0;
}
