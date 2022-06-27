#include <bits/stdc++.h>

using namespace std;

double x_1, y_1, r_1, x_2, y_2, r_2;

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%lf %lf %lf", &x_1, &y_1, &r_1);
    scanf("%lf %lf %lf", &x_2, &y_2, &r_2);

    if (r_2 < r_1) {
        swap(x_1, x_2);
        swap(y_1, y_2);
        swap(r_1, r_2);
    }

    double x_d = x_1 - x_2;
    double y_d = y_1 - y_2;
    double d = sqrt(x_d * x_d + y_d * y_d);

    if (d >= r_1 + r_2) {
        printf("0.000");
    } else if (d + r_1 <= r_2) {
        printf("%.3lf", r_1 * r_1 * M_PI);
    } else {
        double theta1 = acos((r_1 * r_1 + d * d - r_2 * r_2) / (2 * r_1 * d));
        double theta2 = acos((r_2 * r_2 + d * d - r_1 * r_1) / (2 * r_2 * d));

        double s1 = (r_1 * r_1 * theta1) - (r_1 * r_1 * sin(2 * theta1) / 2);
        double s2 = (r_2 * r_2 * theta2) - (r_2 * r_2 * sin(2 * theta2) / 2);

        printf("%.3lf", s1 + s2);
    }

    return 0;
}
