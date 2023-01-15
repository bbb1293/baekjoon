#include <bits/stdc++.h>

using namespace std;

int n, a, b;
bool non_prime[100001], visited[2000001];

void set_prime() {
    non_prime[0] = non_prime[1] = true;
    for (int i = 2; i * i <= 100000; i++) {
        if (!non_prime[i]) {
            for (int j = i + i; j <= 100000; j += i) {
                non_prime[j] = true;
            }
        }
    }
}

bool validate(int x) {
    return (a <= x) && (x <= b) && !non_prime[x];
}

void put_cand(int cand, queue<int> &q, bool &found) {
    if (validate(cand)) {
        found = true;
    } else {
        visited[cand] = true;
        q.push(cand);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    set_prime();

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d", &n, &a, &b);

        bool possible = false;
        for (int i = a; i <= b; i++) {
            if (!non_prime[i]) {
                possible = true;
                break;
            }
        }

        if (!possible) {
            printf("-1\n");
        } else {
            if (validate(n)) {
                printf("0\n");
                continue;
            }

            memset(visited, 0, sizeof(visited));

            queue<int> q;
            q.push(n);
            visited[n] = true;

            bool found = false;
            int ret = 0;
            while (!q.empty() && !found) {
                int sz = q.size();
                ret++;

                while (sz-- && !found) {
                    int cur = q.front();
                    q.pop();

                    if (!visited[cur + 1]) {
                        put_cand(cur + 1, q, found);
                    }

                    if (cur && !visited[cur - 1]) {
                        put_cand(cur - 1, q, found);
                    }

                    if (!visited[cur / 3]) {
                        put_cand(cur / 3, q, found);
                    }

                    if (!visited[cur / 2]) {
                        put_cand(cur / 2, q, found);
                    }
                }
            }
            printf("%d\n", ret);
        }
    }

    return 0;
}
