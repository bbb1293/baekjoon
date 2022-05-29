#include <bits/stdc++.h>

using namespace std;

long long n, a_num, a_price, b_num, b_price;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%lld %lld %lld %lld %lld", &n, &a_num, &a_price, &b_num, &b_price);

    if (a_price * b_num > b_price * a_num) {
        swap(a_num, b_num);
        swap(a_price, b_price);
    }

    long long ret = ((n + a_num - 1) / a_num) * a_price;

    for (int i = 1; i < a_num; i++) {
        long long n_tmp = n - i * b_num;
        if (n_tmp < 0) {
            n_tmp = 0;
        }

        ret = min(ret, i * b_price + ((n_tmp + a_num - 1) / a_num) * a_price);
    }

    printf("%lld", ret);

    return 0;
}
