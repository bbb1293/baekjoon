#include <bits/stdc++.h>

using namespace std;

struct Trie {
    int child[2];

    Trie() { child[0] = child[1] = -1; }
};

int n;
long long ret;
int num[200000];
vector<Trie> trie;

void insert(int a) {
    int cur_idx = 0;

    for (int i = 29; i >= 0; i--) {
        int cur = a & (1 << i);

        if (cur) {
            cur = 1;
        }

        if (trie[cur_idx].child[cur] == -1) {
            trie[cur_idx].child[cur] = trie.size();
            trie.emplace_back();
        }

        cur_idx = trie[cur_idx].child[cur];
    }
}

int get_min(int a) {
    int cur_idx = 0, ans = 0;

    for (int i = 29; i >= 0; i--) {
        int cur = a & (1 << i);

        if (cur) {
            cur = 1;
        }

        if (trie[cur_idx].child[cur] == -1) {
            ans += (1 << i);
            cur_idx = trie[cur_idx].child[cur ^ 1];
        } else {
            cur_idx = trie[cur_idx].child[cur];
        }
    }

    return ans;
}

void dnc(int from, int to, int depth) {
    if (from >= to || depth == -1) {
        return;
    }

    int mid = from;
    while (mid <= to && !(num[mid] & (1 << depth))) {
        mid++;
    }
    mid--;

    dnc(from, mid, depth - 1);
    dnc(mid + 1, to, depth - 1);

    if (mid < from || mid + 1 > to) {
        return;
    }

    trie.clear();
    trie.emplace_back();

    for (int i = from; i <= mid; i++) {
        insert(num[i]);
    }

    int cand = get_min(num[mid + 1]);
    for (int i = mid + 2; i <= to; i++) {
        cand = min(cand, get_min(num[i]));
    }

    ret += cand;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    sort(num, num + n);

    dnc(0, n - 1, 29);

    printf("%lld", ret);

    return 0;
}
