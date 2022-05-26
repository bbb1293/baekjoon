#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5, MAXM = 1e8;
int cnt;
char s[8];
bool used[MAXM], non_prime[MAXN];
vector<int> primes;

void set_prime() {
    non_prime[0] = non_prime[1] = true;

    for (int i = 2; i < MAXN; i++) {
        if (!non_prime[i]) {
            primes.push_back(i);

            for (int j = i + i; j < MAXN; j += i) {
                non_prime[j] = true;
            }
        }
    }
}

int solve(int cur, int selected) {
    if (used[cur]) {
        return 0;
    }
    used[cur] = true;

    int ret = 0;
    if (cur < MAXN) {
        if (!non_prime[cur]) {
            ret++;
        }
    } else {
        bool is_p = true;
        for (auto p : primes) {
            if (p * p > cur) {
                break;
            }

            if ((cur % p) == 0) {
                is_p = false;
                break;
            }
        }

        if (is_p) {
            ret++;
        }
    }

    for (int i = 0; i < cnt; i++) {
        if (!(selected & (1 << i))) {
            ret += solve(cur * 10 + (s[i] - '0'), selected | (1 << i));
        }
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    set_prime();

    int c;
    scanf("%d", &c);

    while (c--) {
        memset(used, 0, sizeof(used));

        scanf("%s", s);

        cnt = strlen(s);

        printf("%d\n", solve(0, 0));
    }

    return 0;
}
