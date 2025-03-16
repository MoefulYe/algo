// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2661
#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    auto n = 0uz, m = 0uz, k = 0uz;
    cin >> n >> m >> k;
    auto ans = (n - k + 1) * (m - k + 1) * k * k;
    // 2 * 4 * 4 = 32
    cout << ans;
}