#include <bits/stdc++.h>

using namespace std;

const int MAXM = 5e6;
int n;
bool non_prime[MAXM + 1];
set<int> all_num, num[2];
long long score[2];

void set_prime() {
    non_prime[0] = non_prime[1] = true;

    for (int i = 2; i * i <= MAXM; i++) {
        if (!non_prime[i]) {
            for (int j = i + i; j <= MAXM; j += i) {
                non_prime[j] = true;
            }
        }
    }
}

void process(int a, int turn) {
    int op_turn = (turn ^ 1);

    if (non_prime[a]) {
        if (num[op_turn].size() < 3) {
            score[op_turn] += 1000;
        } else {
            score[op_turn] += *next(num[op_turn].end(), -3);
        }
    } else {
        if (all_num.count(a)) {
            if (num[turn].count(a)) {
                all_num.erase(a);
                num[turn].erase(a);
            }
            score[turn] -= 1000;

        } else {
            all_num.insert(a);
            num[turn].insert(a);
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    set_prime();

    scanf("%d", &n);

    while (n--) {
        int a, b;
        scanf("%d %d", &a, &b);

        process(a, 0);
        process(b, 1);
    }

    if (score[0] == score[1]) {
        printf("우열을 가릴 수 없음");
    } else if (score[0] < score[1]) {
        printf("소수 마스터 갓규성");
    } else {
        printf("소수의 신 갓대웅");
    }

    return 0;
}