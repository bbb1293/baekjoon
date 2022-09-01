#include <bits/stdc++.h>

using namespace std;

int n, k;
int num[10000], cnt1[10001], cnt2[10001];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d %d", &n, &k);

    int all_cnt1 = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        cnt1[num[i]]++;

        if (cnt1[num[i]] == 1) {
            all_cnt1++;
        }
    }

    cnt1[num[0]]--;
    cnt2[num[0]]++;

    if (cnt1[num[0]] == 0) {
        all_cnt1--;
    }

    int ret = 10001;
    int all_cnt2 = 1;
    int left = 0, right = 1;
    while (left < right) {
        if (all_cnt2 == k) {
            if (all_cnt1 == k) {
                ret = min(ret, right - left);
            }
            cnt1[num[left]]++;
            cnt2[num[left]]--;

            if (cnt1[num[left]] == 1) {
                all_cnt1++;
            }

            if (cnt2[num[left]] == 0) {
                all_cnt2--;
            }
            left++;

        } else {
            if (right == n) {
                break;
            }

            cnt1[num[right]]--;
            cnt2[num[right]]++;

            if (cnt1[num[right]] == 0) {
                all_cnt1--;
            }

            if (cnt2[num[right]] == 1) {
                all_cnt2++;
            }

            right++;
        }
    }

    if (ret == 10001) {
        ret = 0;
    }

    printf("%d", ret);

    return 0;
}