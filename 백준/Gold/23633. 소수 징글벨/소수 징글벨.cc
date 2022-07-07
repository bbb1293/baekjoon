#include <bits/stdc++.h>

using namespace std;

const int INF = 55555;
int a, b;
int dp[2001];
bool non_prime[2001];

void set_prime() {
    non_prime[0] = non_prime[1] = true;
    for (int j = 4; j < 2001; j += 2) {
        non_prime[j] = true;
    }

    for (int i = 3; i < 2001; i += 2) {
        if (!non_prime[i]) {
            for (int j = i + i; j < 2001; j += i) {
                non_prime[j] = true;
            }
        }
    }
}

int get_dp(int cur) {
    int &ret = dp[cur];
    if (ret != INF) {
        return ret;
    }

    int cnt = 0;
    ret = -INF;
    for (int i = 1; i <= a; i++) {
        if (cur + i > b) {
            break;
        }

        if (!non_prime[cur + i]) {
            cnt++;
        }

        ret = max(ret, cnt - get_dp(cur + i));
    }

    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);

    set_prime();

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &a, &b);

        for (int i = 0; i <= b; i++) {
            dp[i] = INF;
        }
        dp[b] = 0;

        int ret = get_dp(0);
        if (ret > 0) {
            printf("kuro\n");
        } else if (ret == 0) {
            printf("draw\n");
        } else {
            printf("siro\n");
        }
    }

    return 0;
}
