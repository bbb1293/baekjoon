#include <bits/stdc++.h>

using namespace std;

int n, ret;

struct Trie {
    Trie *child[2];

} root;

Trie *make_trie() {
    Trie *ret = new Trie();
    ret->child[0] = NULL;
    ret->child[1] = NULL;

    return ret;
}

void put_trie(int a) {
    Trie *cur_trie = &root;

    for (int i = 30; i >= 0; i--) {
        int cur = a & (1 << i);

        if (cur) {
            cur = 1;
        }

        if (cur_trie->child[cur] == NULL) {
            cur_trie->child[cur] = make_trie();
        }

        cur_trie = cur_trie->child[cur];
    }
}

int find_maxor(int a) {
    Trie *cur_trie = &root;
    int cand = 0;

    for (int i = 30; i >= 0; i--) {
        int cur = a & (1 << i);

        if (cur) {
            cur = 1;
        }

        if (cur_trie->child[cur ^ 1] != NULL) {
            cand += (1 << i);
            cur_trie = cur_trie->child[cur ^ 1];
        } else {
            cur_trie = cur_trie->child[cur];
        }
    }

    return cand;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    int num;
    scanf("%d", &num);
    put_trie(num);
    n--;

    while (n--) {
        int num;
        scanf("%d", &num);

        ret = max(ret, find_maxor(num));

        put_trie(num);
    }

    printf("%d", ret);

    return 0;
}
