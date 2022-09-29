#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> birth;
char tmp[40];
int days[] = {0,  31, 28, 31, 30, 31, 30,
              31, 31, 30, 31, 30, 31};

int convert_date2day(int m, int d) {
    int day = d;
    for (int i = 1; i < m; i++) {
        day += days[i];
    }

    return day;
}

int get_prev(int day) {
    day--;
    if (day == 0) {
        day = 365;
    }
    return day;
}

pair<int, int> convert_day2date(int day) {
    for (int i = 1; i <= 12; i++) {
        if (days[i] < day) {
            day -= days[i];
        } else {
            return {i, day};
        }
    }

    return {-1, -1};
}

int get_gap(int d1, int d2) {
    if (d1 <= d2) {
        return d2 - d1;
    } else {
        return 365 - d1 + d2;
    }
}

int get_gap2(int d1, int d2) {
    if (d1 < d2) {
        return d2 - d1;
    } else {
        return 365 - d1 + d2;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m, d;
        scanf(" %s %d-%d", tmp, &m, &d);
        birth.push_back(convert_date2day(m, d));
    }

    sort(birth.begin(), birth.end());
    birth.erase(unique(birth.begin(), birth.end()),
                birth.end());
    n = birth.size();

    pair<int, int> ret;
    if (n == 1) {
        ret = convert_day2date(get_prev(birth[0]));
        printf("%02d-%02d", ret.first, ret.second);
        return 0;
    }

    birth.push_back(convert_date2day(10, 27));
    int day, gap = -1, after_gap = -1;
    for (int i = 0; i < n; i++) {
        int cand = get_prev(birth[i]);
        int cand_gap =
            get_gap(birth[(i - 1 + n) % n], cand);
        int cand_after_gap = get_gap2(birth[n], cand);
        /*
        printf("%d %d %d\n", cand, cand_gap,
               cand_after_gap);
        */

        if (gap == -1 || gap < cand_gap ||
            (cand_gap == gap &&
             cand_after_gap < after_gap)) {
            day = cand;
            gap = cand_gap;
            after_gap = cand_after_gap;
        }
    }

    ret = convert_day2date(day);
    printf("%02d-%02d", ret.first, ret.second);

    return 0;
}