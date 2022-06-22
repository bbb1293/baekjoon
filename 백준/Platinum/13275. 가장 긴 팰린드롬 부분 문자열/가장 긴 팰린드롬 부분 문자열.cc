#include <bits/stdc++.h>

using namespace std;

vector<int> manacher(string s) {
    s = '$' + s + '^';

    int s_len = s.length();
    vector<int> p(s_len + 2);

    int l = 1, r = 1;
    for (int i = 1; i <= s_len; i++) {
        p[i] = max(0, min(r - i, p[r + l - i]));

        while (s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }

        if (i + p[i] > r) {
            r = i + p[i];
            l = i - p[i];
        }
    }

    return p;
}

vector<int> even_manacher(string s) {
    string t;
    for (auto c : s) {
        t += (string("#") + c);
    }

    vector<int> m = manacher(t + string("#"));
    return vector<int>(m.begin() + 1, m.end() - 1);
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int ret = 0;

    vector<int> odd = manacher(s);
    vector<int> even = even_manacher(s);

    for (auto d : odd) {
        ret = max(ret, (d - 1) * 2 + 1);
    }

    for (int i = 0; i < even.size(); i += 2) {
        ret = max(ret, ((even[i] - 1) / 2) * 2);
    }

    cout << ret;

    return 0;
}
