#include <bits/stdc++.h>

using namespace std;

long double pi = 3.1415926535897932384626L;

int main() {

    int n, m;
    long double r;
    std::cin >> m >> n >> r;
    int a_angle, a_r, b_angle, b_r;
    std::cin >> a_angle >> a_r >> b_angle >> b_r;

    int r_min = std::min(a_r, b_r);

    long double ho = pi * r / m *
                     std::abs(a_angle - b_angle) / n *
                     r_min;
    long double lseg = r / n * std::abs(a_r - b_r);

    long double segwhat = r / n * (a_r + b_r);

    std::cout << std::setprecision(20)
              << std::min(ho + lseg, segwhat) << '\n';

    return 0;
}