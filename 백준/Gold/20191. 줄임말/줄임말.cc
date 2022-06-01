#include <bits/stdc++.h>

using namespace std;

char s[1000001], t[100001];
vector<int> pos[26];

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%s", s);
    scanf("%s", t);

    int s_len = strlen(s), t_len = strlen(t);

    for (int i = 0; i < t_len; i++) {
        pos[t[i] - 'a'].push_back(i);
    }

    int ret = 1, prev = -1;
    for (int i = 0; i < s_len; i++) {
        if (pos[s[i] - 'a'].size() == 0) {
            ret = -1;
            break;
        }

        auto it =
            upper_bound(pos[s[i] - 'a'].begin(), pos[s[i] - 'a'].end(), prev);

        if (it == pos[s[i] - 'a'].end()) {
            ret++;
            prev = pos[s[i] - 'a'].front();
        } else {
            prev = *it;
        }
    }

    printf("%d", ret);

    return 0;
}
