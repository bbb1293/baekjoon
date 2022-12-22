#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
pair<string, string> men[MAXN];

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> men[i].first >> men[i].second;
    }

    sort(men, men + n,
         [](pair<string, string> &a,
            pair<string, string> &b) {
             if (a.first != b.first) {
                 return a.first < b.first;
             }
             return b.second < a.second;
         });

    for (int i = 0; i < n; i++) {
        cout << men[i].first << " " << men[i].second
             << "\n";
    }

    return 0;
}