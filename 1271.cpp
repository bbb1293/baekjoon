#include <bits/stdc++.h>

using namespace std;

string _money, _num;
vector<int> money, num;

void init_vector() {
    int money_len = _money.length();
    int num_len = _num.length();

    money.resize(money_len);
    num.resize(num_len);

    for (int i = 0; i < money_len; i++) {
        money[i] = _money[i] - '0';
    }

    for (int i = 0; i < num_len; i++) {
        num[i] = _num[i] - '0';
    }
}

bool is_small(vector<int> &left, vector<int> &right) {
    if (left.size() != right.size()) {
        return left.size() < right.size();
    }

    int end_idx = left.size();
    for (int i = 0; i < end_idx; i++) {
        if (left[i] != right[i]) {
            return left[i] < right[i];
        }
    }
    return false;
}

void remove_zero(vector<int> &a) {
    int a_idx = 0, a_size = a.size();
    while ((a_idx != a_size) && !a[a_idx]) {
        a_idx++;
    }

    a.erase(a.begin(), a.begin() + a_idx);
}

void subtract(vector<int> &left, vector<int> &right) {
    int left_idx = left.size() - 1;
    int right_idx = right.size() - 1;

    int prev = 0;
    while (0 <= left_idx) {
        if (right_idx >= 0) {
            left[left_idx] -= (prev + right[right_idx]);

            if (left[left_idx] < 0) {
                prev = 1;
                left[left_idx] += 10;
            } else {
                prev = 0;
            }
        } else {
            left[left_idx] -= prev;
            if (left[left_idx] < 0) {
                prev = 1;
                left[left_idx] += 10;
            } else {
                break;
            }
        }
        right_idx--;
        left_idx--;
    }

    remove_zero(left);
}

void solve() {
    remove_zero(money);
    remove_zero(num);

    vector<int> rest;
    vector<int> ans;

    int money_size = money.size();
    for (int i = 0; i < money_size; i++) {
        rest.push_back(money[i]);
        remove_zero(rest);

        int cnt = 0;
        while (!is_small(rest, num)) {
            subtract(rest, num);
            cnt++;
        }
        ans.push_back(cnt);
    }

    remove_zero(ans);
    if (!ans.size()) {
        printf("0\n");
    } else {
        for (auto b : ans) {
            printf("%d", b);
        }
        printf("\n");
    }

    if (!rest.size()) {
        printf("0");
    } else {
        for (auto a : rest) {
            printf("%d", a);
        }
        printf("\n");
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> _money >> _num;

    init_vector();
    solve();
}