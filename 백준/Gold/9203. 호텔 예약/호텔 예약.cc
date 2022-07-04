#include <bits/stdc++.h>

using namespace std;

int b, c;
pair<long long, long long> rv[5000];
int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

long long get_diff(int y, int m, int d, int hour, int min) {
    long long ret = min + hour * 60;

    int day = d - 1;
    for (int i = 1; i < m; i++) {
        day += days[i];
    }

    for (int i = 2013; i < y; i++) {
        day += 365;
    }

    if (y == 2016 && 2 < m) {
        day++;
    }

    ret += (day * 60 * 24);

    return ret;
}

int main() {
    //freopen("input.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    char s[21];
    int y1, m1, d1, hour1, min1, y2, m2, d2, hour2, min2;
    while (t--) {
        scanf("%d %d", &b, &c);

        for (int i = 0; i < b; i++) {
            scanf(" %s %d-%d-%d %d:%d %d-%d-%d %d:%d", s, &y1, &m1, &d1, &hour1,
                  &min1, &y2, &m2, &d2, &hour2, &min2);

            rv[i] = {get_diff(y1, m1, d1, hour1, min1),
                     get_diff(y2, m2, d2, hour2, min2) + c};
        }

        sort(rv, rv + b);

        priority_queue<long long> pq;

        int ret = 0;
        for (int i = 0; i < b; i++) {
            while (!pq.empty() && -pq.top() <= rv[i].first) {
                pq.pop();
            }

            pq.push(-rv[i].second);
            ret = max(ret, (int)pq.size());
        }

        printf("%d\n", ret);
    }

    return 0;
}
