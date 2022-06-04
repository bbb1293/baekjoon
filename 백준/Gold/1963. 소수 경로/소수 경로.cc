#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e4;
bool used[MAXN], non_prime[MAXN];

void set_prime() {
    for (int i = 2; i < MAXN; i++) {
        if (!non_prime[i]) {
            for (int j = i + i; j < MAXN; j += i) {
                non_prime[j] = true;
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    set_prime();

    int t;
    scanf("%d", &t);

    while (t--) {
        memset(used, 0, sizeof(used));

        int a, b;
        scanf("%d %d", &a, &b);

        if (a == b) {
            printf("0\n");
            continue;
        }

        queue<int> q;
        q.push(a);
        used[a] = true;

        int cur = 0, ret = -1;
        while (!q.empty() && ret == -1) {
            int q_size = q.size();
            cur++;
            while (q_size-- && ret == -1) {
                int cur_num = q.front();
                q.pop();

                int pos = 1;
                for (int i = 0; i < 4; i++) {
                    int tmp_num = cur_num - (((cur_num / pos) % 10) * pos);
                    for (int j = 0; j < 10; j++) {
                        int next_num = tmp_num + (j * pos);

                        if (used[next_num] || non_prime[next_num] ||
                            next_num < 1000) {
                            continue;
                        }

                        if (next_num == b) {
                            ret = cur;
                            break;
                        }

                        q.push(next_num);
                        used[next_num] = true;
                    }

                    pos *= 10;
                }
            }
        }

        if (ret == -1) {
            printf("Impossible\n");
        } else {
            printf("%d\n", ret);
        }
    }

    return 0;
}
