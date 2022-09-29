#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int main() {
    int N;
    cin >> N;
    map<pii, int> s;
    long sum1 = 0, sum2 = 0;
    int b, p;
    vector<int> bv(N), pv(N);
    for (int i = 0; i < N; i++) {
        cin >> b >> p;
        sum1 += b;
        sum2 += p;
        if (s.count({b, p}) == 0) {
            s.insert({{b, p}, 1});
        } else {
            s[{b, p}]++;
        }
        bv[i] = b;
        pv[i] = p;
    }
    if (N % 2 != 0 || (sum1 / (N / 2)) * (N / 2) != sum1 ||
        (sum2 / (N / 2)) * (N / 2) != sum2) {
        cout << "impossible" << '\n';
        return 0;
    }
    sum1 /= N / 2;
    sum2 /= N / 2;
    for (int i = 0; i < N; i++) {
        int rb = sum1 - bv[i], rp = sum2 - pv[i];
        if (s.count({rb, rp}) == 0 || s[{rb, rp}] <= 0) {
            cout << "impossible" << '\n';
            return 0;
        } else {
            s[{rb, rp}]--;
        }
    }
    cout << "possible" << '\n';
    return 0;
}