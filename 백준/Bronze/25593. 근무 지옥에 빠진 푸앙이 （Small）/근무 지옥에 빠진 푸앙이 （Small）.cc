#include <bits/stdc++.h>

using namespace std;

int n;
int hour[4] = {4, 6, 4, 10};
map<string, int> m;

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 7; k++) {
                string tmp;
                cin >> tmp;

                if (tmp != "-") {
                    m[tmp] += hour[j];
                }
            }
        }
    }

    int min_hour = 1e9, max_hour = 0;
    for (auto key_value : m) {
        min_hour = min(key_value.second, min_hour);
        max_hour = max(key_value.second, max_hour);
    }

    if (max_hour - min_hour <= 12) {
        printf("Yes");
    } else {
        printf("No");
    }

    return 0;
}
