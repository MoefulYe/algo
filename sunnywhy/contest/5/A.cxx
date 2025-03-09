// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2608
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

auto main() -> int {
    auto k = 0;
    auto t = string{};
    cin >> k >> t;
    auto s = string_view(t);
    auto ret = t.substr(0, 0);
    for(auto i = 0; i < s.size(); i++) {
        auto min = 'Z';
        auto max = 'A';
        auto j = i;
        for(; j < s.size(); j++) {
            auto c = s[j];
            min = std::min(min, c);
            max = std::max(max, c);
            if(max - min > k) {
                break;
            }
        }
        // j是第一个不满足的位置
        auto sub_s = s.substr(i, j - i);
        if(sub_s.size() > ret.size()) {
            ret = sub_s;
        }
    }
    assert(ret != "");
    cout << ret;
}