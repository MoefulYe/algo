// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2696

#include <bits/stdc++.h>
using namespace std;

using Pos = tuple<int, int, int>;

struct Point { 
    Pos pos;
    vector<tuple<int, Pos>> neighors;
};

constexpr auto INF = numeric_limits<int>::max(); 
auto points = vector<Point>{};
constexpr auto UNRESOLVED = Pos {
    INF, INF, INF
};

auto main() -> int {
    auto n = 0, m = 0;
    cin >> n >> m;
    auto sources = vector<int>{};
    points = vector<Point>(n + 1, Point { UNRESOLVED });
    for(auto _ = 0; _ < m; _++) {
        auto t = 0;
        cin >> t;
        if(t == 1) {
            auto a = 0, b = 0, x = 0, y = 0, z = 0;
            cin >> a >> b >> x >> y >> z;
            points[a].neighors.push_back({b, {x, y, z}});
            points[b].neighors.push_back({a, {-x, -y, -z}});
        } else if(t == 2) {
            auto i = 0, x = 0, y = 0, z = 0;
            cin >> i >> x >> y >> z;
            points[i].pos = {x, y, z};
            sources.push_back(i);
        } else {
            assert(false);
        }
    }
    auto q = deque<int>(sources.begin(), sources.end());
    while(!q.empty()) {
        auto p = q.front();
        q.pop_front();
        auto& [pos, neighors] = points[p];
        auto [x, y, z] = pos;
        for(auto [point, delta]: neighors) {
            if(points[point].pos == UNRESOLVED) {
                auto [dx, dy, dz] = delta;
                auto pos = Pos {
                    x + dx,
                    y + dy,
                    z + dz,
                };
                points[point].pos = pos;
                q.push_back(point);
            }
        }
    }
    for(auto i = 1; i <= n; i++) {
        auto pos = points[i].pos;
        if(pos == UNRESOLVED) {
            cout << "-1\n";
        } else {
            auto [x, y, z] = pos;
            cout << x << " " << y << " " << z << "\n";
        }
    }
}