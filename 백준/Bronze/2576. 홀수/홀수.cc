#include<iostream>

using namespace std;

int main() {

        int min = 100;
        int sum = 0;

        for (int i = 0; i < 7; i++) {
                int temp;
                scanf("%d", &temp);
                if (temp % 2 == 1) {
                        sum += temp;
                        if (min > temp) {
                                min = temp;
                        }
                }
        }

        if (min == 100) {
                printf("-1");
        } else {
                printf("%d\n%d", sum, min);
        }

        return 0;
}