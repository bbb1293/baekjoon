#include <bits/stdc++.h>

using namespace std;

int n;
string a[16], b[16];
map<string, int> m1, m2;

int solve(int bits, int cur) {
    if (cur == n) {
        return 0;
    }

    if (bits & (1 << cur)) {
        int ret = 0;

        if (m1[a[cur]] > 1 && m2[b[cur]] > 1) {
            m1[a[cur]]--;
            m2[b[cur]]--;

            ret = 1 + solve(bits, cur + 1);

            m1[a[cur]]++;
            m2[b[cur]]++;
        }

        return ret;

    } else {
        return solve(bits, cur + 1);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        m1.clear();
        m2.clear();

        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> a[j] >> b[j];
            m1[a[j]]++;
            m2[b[j]]++;
        }

        int ret = 0;
        for (int bits = 1; bits < (1 << n); bits++) {
            ret = max(ret, solve(bits, 0));
        }

        cout << "Case #" << i << ": " << ret << "\n";
    }

    return 0;
}
