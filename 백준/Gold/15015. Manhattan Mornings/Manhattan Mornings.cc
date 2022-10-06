#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;

    bool operator<(const Point &rhs) const {
        return x == rhs.x ? y < rhs.y : x < rhs.x;
    }
};

bool in_range(int s, int e, int to_determine) {
    return std::min(s, e) <= to_determine and
           to_determine <= std::max(s, e);
}

int main() {
    

    int n;
    std::cin >> n;
    Point start, end;
    std::cin >> start.x >> start.y >> end.x >> end.y;

    std::vector<Point> input;

    for (int i = 0; i < n; ++i) {
        int x, y;
        std::cin >> x >> y;
        if (in_range(start.x, end.x, x) and
            in_range(start.y, end.y, y)) {
            input.push_back({x, y});
        }
    }

    if (start.x > end.x) {
        std::swap(start, end);
    }

    for (Point &p : input) {
        p.x -= start.x;
        p.y -= start.y;
    }
    end.x -= start.x;
    end.y -= start.y;
    start.x = 0;
    start.y = 0;

    if (end.y < 0) {
        for (Point &p : input) {
            p.y *= -1;
        }
    }

    std::sort(input.begin(), input.end());

    std::vector<int> memo(input.size(), -1), minmemo(1, -1);

    std::function<int(int)> bsear = [&minmemo](int y) {
        if (y >= minmemo.back()) {
            minmemo.push_back(y);
            return int(minmemo.size() - 1);
        } else {
            int idx = std::upper_bound(minmemo.begin(),
                                       minmemo.end(), y) -
                      minmemo.begin();
            minmemo[idx] = y;
            return idx;
        }
    };

    for (int i = 0; i < input.size(); ++i) {
        int y = input[i].y;
        memo[i] = bsear(y);
    }

    std::cout << std::reduce(memo.begin(), memo.end(), 0,
                             [](int l, int r) {
                                 return std::max(l, r);
                             })
              << '\n';

    return 0;
}