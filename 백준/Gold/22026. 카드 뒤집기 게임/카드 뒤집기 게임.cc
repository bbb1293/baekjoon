#include <vector>
#include <string>

bool reversal(int N, int M, std::vector<std::string> P) {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (P[y][x] == 'X') {
                for (int xx = x; xx < N; xx += M) {
                    P[y][xx] = 'O' + 'X' - P[y][xx];
                }
            }
        }
    }

    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            if (P[y][x] == 'X') {
                for (int yy = y; yy < N; yy += M) {
                    P[yy][x] = 'O' + 'X' - P[yy][x];
                }
            }
        }
    }

    for (int y = M; y < N; y++) {
        for (int x = M; x < N; x++) {
            if (P[y][x] == 'X') {
                return false;
            }
        }
    }

    return true;
}
