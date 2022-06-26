#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e5;
int n;
string s;
vector<int> max_nums;

int main() {
    // freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    cin >> s;

    char prev = s[0];
    int max_num = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (prev != s[i]) {
            prev = s[i];
            max_nums.push_back(max_num);
            max_num = num;
        } else {
            max_num = max(max_num, num);
        }
    }
    max_nums.push_back(max_num);

    if (max_nums.size() < 3) {
        cout << '0';
    } else {
        sort(max_nums.begin() + 1, max_nums.end() - 1);

        long long ret = 0;
        int cnt = (max_nums.size() - 1) / 2;
        for (int i = 0; i < cnt; i++) {
            ret += max_nums[max_nums.size() - 2 - i];
        }
        cout << ret;
    }

    return 0;
}
