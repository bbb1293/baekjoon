#include <bits/stdc++.h>

using namespace std;

string ori;
set<string> s;

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> ori;

    for (int i = 0; i < ori.length(); i++) {
        for (int j = 1; j <= ori.length(); j++) {
            s.insert(ori.substr(i, j));
        }
    }

    cout << s.size();

    return 0;
}
