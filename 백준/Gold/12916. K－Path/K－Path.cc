#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
int n, k;

struct Matrix {
    long long m[100][100];

    Matrix operator*(const Matrix &a) const {
        Matrix ret;

        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                ret.m[y][x] = 0;

                for (int i = 0; i < n; i++) {
                    ret.m[y][x] += (m[y][i] * a.m[i][x]);
                    ret.m[y][x] %= MOD;
                }
            }
        }

        return ret;
    }
};

Matrix power_k(Matrix &ori, int k) {
    if (k == 1) {
        return ori;
    }

    Matrix tmp = power_k(ori, k / 2);

    if (k & 1) {
        return (tmp * tmp * ori);
    }
    return (tmp * tmp);
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);

    Matrix ret;

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%lld", &ret.m[y][x]);
        }
    }

    ret = power_k(ret, k);

    long long cnt = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cnt += ret.m[y][x];
            cnt %= MOD;
        }
    }

    printf("%lld", cnt);

    return 0;
}