#include <bits/stdc++.h>

using namespace std;

int n;
string s, check = "yuiophjklbnm";

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;
    cin >> s;

    if (check.find(s[n - 1]) != string::npos) {
        printf("0");
    } else {
        printf("1");
    }

    return 0;
}
