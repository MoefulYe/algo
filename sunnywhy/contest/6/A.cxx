// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2620

#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
    auto n = 0;
    cin >> n;
    auto max = numeric_limits<int>::min();
    auto min = numeric_limits<int>::max();
    for_each_n(istream_iterator<int>(cin), n, [&](auto v) {
        max = std::max(max, v);
        min = std::min(min, v);
    });
    auto cnt = max - min + 1;
    cout << cnt - n;
}