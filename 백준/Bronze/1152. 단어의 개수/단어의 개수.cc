#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);

    string s;
    getline(cin, s);

    int ret = 0, cnt = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            if (cnt) {
                ret++;
            }
            cnt = 0;
        } else {
            cnt++;
        }
    }

    if (cnt) {
        ret++;
    }

    printf("%d", ret);

    return 0;
}
