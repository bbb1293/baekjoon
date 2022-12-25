#import <bits/stdc++.h>

using namespace std;

int charm[1000][1000];

int main() {
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    
    a--;
    b--;
    
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            scanf("%d", &charm[y][x]);
        }
    }
    
    bool most = true;
    for (int i = 0; i < n; i++) {
        if (charm[a][b] < charm[a][i] || charm[a][b] < charm[i][b]) {
            most = false;
            break;
        }
    }
    
    if (most) {
        printf("HAPPY");
    } else {
        printf("ANGRY");
    }
    
    return 0;
}