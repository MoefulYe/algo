// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2662

#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    auto n = 0, k = 0;
    cin >> n >> k;
    auto arr = array<tuple<int, int>, 32>{}; // (cnt0, cnt1)

    for_each_n(istream_iterator<int>(cin), n, [&](int v) {
        for(auto i = 0; i < 32; i++) {
            auto& [cnt0, cnt1] = arr[i];
            if(v & (1 << i) != 0) {
                cnt1 = cnt1 + 1;
            } else {
                cnt0 = cnt0 + 1;
            }
        }
    });
    for(auto [x, y] : arr) {
        cout << x << " " << y << "\n";
    }
    auto cnts = 0;
    for(auto i = 0; i < 32; i++) {
        auto [cnt0, cnt1] = arr[i];
        if(k & (1 << i) != 0) { // 该位为1那么需要把所有该位为0的位反转为1
            cnts = cnts + cnt0;
        } else if(cnt0 == 0) { // 为0, 如果cnt0为0反转一次即可
            cnts = cnts + 1;
        }
    }
    cout << cnts;
}