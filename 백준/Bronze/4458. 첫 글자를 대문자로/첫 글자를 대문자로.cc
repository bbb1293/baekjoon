#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    // freopen("input.txt", "r", stdin);

    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;

    string s;
    getline(cin, s);

    while (n--) {
        getline(cin, s);

        if ('a' <= s[0] && s[0] <= 'z') {
            s[0] -= 'a';
            s[0] += 'A';
        }

        cout << s << "\n";
    }

    return 0;
}