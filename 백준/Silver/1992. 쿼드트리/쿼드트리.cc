#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int n;
char quad[64][64];

string divncon(int len, int ys, int xs) {
    bool flg = true;
    for (int y = ys; y < ys + len; y++) {
        for (int x = xs; x < xs + len; x++) {
            if (quad[ys][xs] != quad[y][x]) {
                flg = false;
                break;
            }
        }
        if (!flg) {
            break;
        }
    }

    if (flg) {
        if (quad[ys][xs] == '0') {
            return "0";
        } else {
            return "1";
        }
    }

    return "(" + divncon(len / 2, ys, xs) + divncon(len / 2, ys, xs + len / 2) + divncon(len / 2, ys + len / 2, xs) + divncon(len / 2, ys + len / 2, xs + len / 2) + ")";
}

int main() {
    scanf("%d", &n);
    char tmp;
    scanf("%c", &tmp);

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%c", &quad[y][x]);
        }
        scanf("%c", &tmp);
    }

    cout << divncon(n, 0, 0);
    return 0;
}
