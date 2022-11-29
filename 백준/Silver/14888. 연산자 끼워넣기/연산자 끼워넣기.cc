#include<iostream>
#include<stdio.h>

using namespace std;

int n;
int minima = 1000000000;
int maxima = -1000000000;
int num[11];
int oper_num[4];

void solve(int sum, int cur, int num_plus, int num_minus, int num_cross, int num_divide) {
    if (cur == n) {
        if (sum <= minima) {
            minima = sum;
        }
        if (sum >= maxima) {
            maxima = sum;
        }
    } else {
        if (num_plus < oper_num[0]) {
            solve(sum + num[cur], cur + 1, num_plus + 1, num_minus, num_cross, num_divide);
        }
        if (num_minus < oper_num[1]) {
            solve(sum - num[cur], cur + 1, num_plus, num_minus + 1, num_cross, num_divide);
        }
        if (num_cross < oper_num[2]) {
            solve(sum * num[cur], cur + 1, num_plus, num_minus, num_cross + 1, num_divide);
        }
        if (num_divide < oper_num[3]) {
            solve(sum / num[cur], cur + 1, num_plus, num_minus, num_cross, num_divide + 1);
        }
    }
}

int main(){

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }

    for (int i = 0; i < 4; i++) {
        scanf("%d", &oper_num[i]);
    }

    solve(num[0], 1, 0, 0, 0, 0);

    printf("%d\n%d", maxima, minima);

    return 0;
}
