// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2625
#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    auto s = string{};
    cin >> s;
    assert(s.size() > 0);
    auto pred_pos = s.front();
    auto sum = 0;
    for(auto cur_pos: s) {
        auto dist = abs(pred_pos - cur_pos);
        pred_pos = cur_pos;
        sum = sum + dist;
    }
    cout << sum;
}