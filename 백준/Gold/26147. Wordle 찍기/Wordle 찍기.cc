#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
string check[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> check[i];
    }

    for (int i = 0; i < n; i++) {
        int cnt[3] = {
            0,
        };

        for (int j = 0; j < 5; j++) {
            if (check[i][j] == 'G') {
                cnt[0]++;
            } else if (check[i][j] == 'Y') {
                cnt[1]++;
            } else {
                cnt[2]++;
            }
        }

        if (cnt[0] == 4 && cnt[1] == 1) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    cout << "ABCDE\n";
    for (int i = 0; i < n; i++) {
        string ret = "ZZZZZ\n";

        for (int j = 0; j < 5; j++) {
            if (check[i][j] == 'G') {
                ret[j] = j + 'A';
            }
        }

        for (int j = 0; j < 5; j++) {
            if (check[i][j] == 'Y') {
                for (int k = (j + 1) % 5; k != j;
                     k = (k + 1) % 5) {
                    if (ret[k] != k + 'A') {
                        ret[j] = k + 'A';
                        break;
                    }
                }
            }
        }

        cout << ret;
    }

    return 0;
}