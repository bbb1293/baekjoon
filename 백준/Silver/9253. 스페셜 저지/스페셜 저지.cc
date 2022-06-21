#include <bits/stdc++.h>

using namespace std;

string a, b, c;
bool exist[1000000];

bool is_possible(string a, string b) {
    a = b + ' ' + a;
    int b_len = b.length();

    vector<int> pi(a.length());
    for (int i = 1; i < a.length(); i++) {
        int j = pi[i - 1];

        while (j > 0 && a[j] != a[i]) {
            j = pi[j - 1];
        }

        if (a[j] == a[i]) {
            j++;
        }

        if (j == b_len) {
            return true;
        }

        pi[i] = j;
    }

    return false;
}

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;

    if (is_possible(a, c) && is_possible(b, c)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
