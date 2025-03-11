// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2626

#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    auto n = 0, m = 0;
    cin >> n >> m;
    auto cs = vector<int>(n);
    copy_n(istream_iterator<int>(cin), n, cs.begin());
    auto ds = vector<int>(m);
    copy_n(istream_iterator<int>(cin), m, ds.begin());
    auto max = numeric_limits<int>::min();
    sort(cs.begin(), cs.end());
    sort(ds.begin(), ds.end());
    for(auto c: cs) {
        auto pos = lower_bound(ds.begin(), ds.end(), c);
        if(pos == ds.end()) { // 说明所有的陷阱都在该树桩前
            auto anquan = c - ds.back();
            max = std::max(max, anquan);
        } else if(pos == ds.begin()) { // 说明所有的陷阱都比该树桩后
            // if(*pos == c) {
            //     cout << c << endl;
            //     assert(false);
            // }
            auto anquan = ds.front() - c;
            max = std::max(max, anquan);
        } else {
            // if(*pos == c) {
            //     cout << c << endl;
            //     assert(false);
            // }
            auto pred = pos - 1;
            auto succ = pos;
            auto anquan1 = c - *pred;
            auto anquan2 = *succ - c;
            auto anquan = std::min(anquan1, anquan2);
            max = std::max(max, anquan);
        }
    }
    assert(max > 0);
    cout << max;
}