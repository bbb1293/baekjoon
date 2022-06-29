#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
long long n;

vector<long long> mult(vector<long long> &a, vector<long long> &b) {
    vector<long long> ret;
    ret.push_back(((a[0] * b[0]) % MOD + (a[1] * b[2]) % MOD) % MOD);
    ret.push_back(((a[0] * b[1]) % MOD + (a[1] * b[3]) % MOD) % MOD);
    ret.push_back(((a[2] * b[0]) % MOD + (a[3] * b[2]) % MOD) % MOD);
    ret.push_back(((a[2] * b[1]) % MOD + (a[3] * b[3]) % MOD) % MOD);

    return ret;
}

vector<long long> solve(long long k) {
    if (k == 0) {
        return {1, 0, 0, 1};
    }

    if (k == 1) {
        return {4, MOD - 1, 1, 0};
    }

    vector<long long> ret = solve(k / 2);
    ret = mult(ret, ret);

    if (k & 1) {
        vector<long long> tmp = solve(1);
        ret = mult(ret, tmp);
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%lld", &n);

    if (n & 1) {
        printf("0");
        return 0;
    }

    vector<long long> ret = solve((n - 2) / 2);
    printf("%lld", ((ret[0] * 3) % MOD + ret[1]) % MOD);

    return 0;
}
