#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;
long long n, m;

struct Matrix {
    long long a[4];

    Matrix operator*(Matrix &other) {
        Matrix tmp;
        tmp.a[0] = ((a[0] * other.a[0]) % MOD +
                    (a[1] * other.a[2]) % MOD) %
                   MOD;
        tmp.a[1] = ((a[0] * other.a[1]) % MOD +
                    (a[1] * other.a[3]) % MOD) %
                   MOD;
        tmp.a[2] = ((a[2] * other.a[0]) % MOD +
                    (a[3] * other.a[2]) % MOD) %
                   MOD;
        tmp.a[3] = ((a[2] * other.a[1]) % MOD +
                    (a[3] * other.a[3]) % MOD) %
                   MOD;

        return tmp;
    }
};

long long get_power(long long k) {
    Matrix sum, cur;
    sum.a[0] = sum.a[3] = 1;
    sum.a[1] = sum.a[2] = 0;

    cur.a[0] = 0;
    cur.a[1] = cur.a[2] = cur.a[3] = 1;

    while (k) {
        if (k & 1) {
            sum = sum * cur;
        }
        cur = cur * cur;
        k /= 2;
    }

    return sum.a[1];
}

long long get_gcd(long long a, long long b) {
    if (b < a) {
        swap(a, b);
    }

    while (a) {
        long long tmp = b % a;
        b = a;
        a = tmp;
    }

    return b;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%lld %lld", &n, &m);

    long long gcd = get_gcd(n, m);

    printf("%lld", get_power(gcd));

    return 0;
}