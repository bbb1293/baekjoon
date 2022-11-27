#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5;
int n;
char s_time[20];
pair<long long, long long> times[MAXN];

int char2num(char a) { return a - '0'; }

long long convert_time() {
    long long h =
        char2num(s_time[0]) * 10 + char2num(s_time[1]);
    long long m =
        char2num(s_time[3]) * 10 + char2num(s_time[4]);
    long long s =
        char2num(s_time[6]) * 10 + char2num(s_time[7]);
    long long ms = char2num(s_time[9]) * 100 +
                   char2num(s_time[10]) * 10 +
                   char2num(s_time[11]);

    return ((h * 60 + m) * 60 + s) * 1000 + ms;
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf(" %s", s_time);
        times[i].first = convert_time();

        scanf(" %s", s_time);
        times[i].second = convert_time();
    }

    sort(times, times + n);

    int ret = 0;
    priority_queue<int> pq;

    for (int i = 0; i < n; i++) {
        while (!pq.empty() && -pq.top() <= times[i].first) {
            pq.pop();
        }

        pq.push(-times[i].second);

        ret = max(ret, (int)pq.size());
    }

    printf("%d", ret);

    return 0;
}
