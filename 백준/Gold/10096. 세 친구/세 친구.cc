#include <bits/stdc++.h>

using namespace std;

int n;
string u, s[2];

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> u;

    if (n & 1) {
        int left = 0, right = n / 2;
        while (left < n / 2 && right < n) {
            if (u[left] != u[right]) {
                left--;
            } else {
                s[0] += u[left];
            }
            left++;
            right++;
        }

        left = 0, right = n / 2 + 1;
        while (left <= n / 2 && right < n) {
            if (u[left] != u[right]) {
                right--;
            } else {
                s[1] += u[left];
            }
            left++;
            right++;
        }

        if (s[0].size() == n / 2) {
            if (s[1].size() == n / 2) {
                if (s[0] != s[1]) {
                    cout << "NOT UNIQUE";
                } else {
                    cout << s[0];
                }
            } else {
                cout << s[0];
            }
        } else {
            if (s[1].size() == n / 2) {
                cout << s[1];
            } else {
                cout << "NOT POSSIBLE";
            }
        }
    } else {
        cout << "NOT POSSIBLE";
    }

    return 0;
}