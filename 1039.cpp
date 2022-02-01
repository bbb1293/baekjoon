#include <bits/stdc++.h>

using namespace std;

int n, k, ret, biggest, rest_k;
bool is_visited[1000001];
vector<int> num;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

vector<int> num_to_vec(int num) {
    vector<int> vec;
    while (num) {
        vec.push_back(num % 10);
        num /= 10;
    }
    return vec;
}

int vec_to_num(vector<int> &vec) {
    int ret = 0;
    for (int i = vec.size() - 1; i >= 0; i--) {
        ret *= 10;
        ret += vec[i];
    }
    return ret;
}

void solve() {
    queue<pair<int, int> > q;
    q.push({n, k});

    while (!q.empty()) {
        int cur_n = q.front().first;
        int cur_k = q.front().second;
        q.pop();

        if (ret < cur_n) {
            ret = cur_n;
            rest_k = cur_k;
        }

        if (cur_n == biggest) {
            break;
        }

        if (cur_k) {
            vector<int> tmp = num_to_vec(cur_n);
            int last = tmp.size() - 1;
            for (int i = last; i > 0; i--) {
                for (int j = 0; j < i; j++) {
                    if ((i == last) && (tmp[j] == 0)) {
                        continue;
                    }
                    swap(tmp[i], tmp[j]);
                    int next_n = vec_to_num(tmp);
                    if (!is_visited[next_n]) {
                        is_visited[next_n] = true;
                        q.push({next_n, cur_k - 1});
                    }
                    swap(tmp[i], tmp[j]);
                }
            }
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);

    num = num_to_vec(n);

    if ((num.size() == 1) || ((num.size() == 2) && (num[0] == 0))) {
        printf("-1");
    } else {
        sort(num.begin(), num.end());
        biggest = vec_to_num(num);

        is_visited[n] = true;
        solve();

        if (rest_k % 2) {
            bool flg = false;
            int cand = ret;
            int cnt[10] = {
                0,
            };
            while (cand) {
                cnt[cand % 10]++;
                if (cnt[cand % 10] > 1) {
                    flg = true;
                    break;
                }
                cand /= 10;
            }

            if (!flg) {
                ret =
                    ((ret / 100) * 100) + ((ret % 10) * 10) + ((ret / 10) % 10);
            }
        }
        printf("%d", ret);
    }

    return 0;
}