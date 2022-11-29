#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector< vector<char> > chess(50, vector<char>(50));

int minimal(int a, int b) {
        int ret1 = 0, ret2 = 0;
        for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) {
                        if (chess[a + i][b + j] == 'W') {
                                ret1++;
                        } else {
                                ret2++;
                        }
                        j++;
                        if (chess[a + i][b + j] == 'B') {
                                ret1++;
                        } else {
                                ret2++;
                        }
                }
                i++;
                for (int j = 0; j < 8; j++) {
                        if (chess[a + i][b + j] == 'B') {
                                ret1++;
                        } else {
                                ret2++;
                        }
                        j++;
                        if (chess[a + i][b + j] == 'W') {
                                ret1++;
                        } else {
                                ret2++;
                        }
                }
        }

        return min(ret1, ret2);
}

int main() {
        char temp;
        scanf("%d %d", &N, &M);
        for (int i = 0; i < N; i++) {
                scanf("%c", &temp);
                for (int j = 0; j < M; j++) {
                        scanf("%c", &temp);
                        chess[i][j] = temp;
                }
        }
        int ret = minimal(0,0);
        for (int i = 0; i <= N - 8; i++) {
                for (int j = 0; j <= M - 8; j++) {
                        ret = min(ret, minimal(i, j));
                }
        }
        printf("%d", ret);

        return 0;
}