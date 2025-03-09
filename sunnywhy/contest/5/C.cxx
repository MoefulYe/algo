// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2610

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

auto $main() -> int {
    auto n = 0, k = 0, a = 0, b = 0;
    cin >> n >> k >> a >> b;
    assert(a + 1 < b);
    // 1.a...b... n
    // o-o-o-o-o-o-o 
    //   |   |
    //   ---- 
    // [a+1..n] -> *
    // a + 1 -> a + k + 1
    // a + 2 -> a + k + 2
    // ? -> n
    auto cnt1 = max((n - a - k), 0);
    // [1..a] -> [1..b - 1] 走不了捷径
    // 1 -> 1 + k
    // ...
    // b - 1 - k -> b - 1
    auto cnt2 = max(min((b - 1 - k), a), 0);
    // [1..a] -> [b..n] 走捷径
    // x刚好到达b
    // a - x + 1 = k
    auto x = a + 1 - k;
    // y 刚好到达n
    // a - y + 1 + n - b = k
    // y = a + 1 + n - b - k
    auto y = a + 1 - k + n - b; // y >= x
    auto cnt3 = 0;
    if(y <= 0) {
        cnt3 = 0;
    } else if(y <= a && x <= 0) {
        cnt3 = y;
    } else if(y <= a && x <= a) {
        cnt3 = y - x + 1;
    } else if(y > a && x <= 0) {
        cnt3 = a;
    } else if(y > a && x <= a) {
        cnt3 = a - x + 1;
    } else if(y > a && x > a) {
        cnt3 = 0;
    } else {
        assert(false);
    }
    return cnt1 + cnt2 + cnt3;
}

auto main() -> int {
    cin.tie(nullptr)->sync_with_stdio(false);
    auto q = 0;
    cin >> q;
    for(auto _ = 0; _ < q; _++) {
        cout << $main() << '\n';
    }
}