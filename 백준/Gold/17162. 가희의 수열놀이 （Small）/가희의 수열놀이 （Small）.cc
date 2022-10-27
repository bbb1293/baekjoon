#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5;
int q, m;
int arr[MAXN], cnt[100];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &q, &m);

    int left = 0, right = 0, cur_cnt = m;

    while (q--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d", &arr[right]);
            arr[right] %= m;
            cnt[arr[right]]++;

            if (cnt[arr[right]] == 1) {
                cur_cnt--;
            }

            while (cnt[arr[left]] > 1) {
                cnt[arr[left]]--;
                left++;
            }

            right++;

        } else if (op == 2) {
            if (right > 0) {
                right--;
                cnt[arr[right]]--;

                if (cnt[arr[right]] == 0) {
                    cur_cnt++;

                    while (left - 1 >= 0 && cur_cnt != 0) {
                        left--;
                        cnt[arr[left]]++;

                        if (cnt[arr[left]] == 1) {
                            cur_cnt--;
                        }
                    }
                }
            }
        } else {
            if (cur_cnt != 0) {
                printf("-1\n");
            } else {
                printf("%d\n", right - left);
            }
        }
    }

    return 0;
}