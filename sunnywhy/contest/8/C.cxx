// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2631

#include <bits/stdc++.h>
using namespace std;


// 1 2 1
// 1 2 1
// 1 3 1 
// 1 3 1
// 2 3 1
// 有多个颜色可以选择时,
// 如果较小的数字拿掉后选不通
// 那么选较大数字肯定也选不通
// 
// 如果同一种颜色可以选择多次时候
// 选哪个？

using Color = int;
using Column = vector<Color>;
auto n = 0, m = 0;
auto mat = vector<Column>{};


auto init() {
    cin >> n >> m;
    for(auto _ = 0; _ < m; _++) {
        auto col = vector<int>{};
        auto k = 0;
        cin >> k;
        for(auto _ = 0; _ < k; _++) {
            auto a = 0;
            cin >> a;
            assert(a >= 1 && a <= 3);
            col.push_back(a);
        }
        mat.push_back(move(col));
    }
}

auto main() -> int {
    auto origin = vector<int>(m, 0);
    auto queue = deque<Postion*>
}