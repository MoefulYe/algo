// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2481&contestSubTab=problem&pid=A

#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    auto s = 0uz, e = 0uz, k = 0uz;
    cin >> s >> e >> k;
    auto v1 = s / k;
    auto v2 = (s % k) != 0;
    auto v3 = e / k;
    auto v4 = (e % k) != 0;
    auto ans = 0uz;
    if(!v2 && !v4) { // $v1 = v1, $v2 = v2  
        ans = v3 - v1 + 1;
    } else if (!v2 && v4) { // $v1 = v1, $v2 = v2.xxx
        ans = v3 - v1 + 1;
    } else if (v2 && !v4) { // $v1 = v1.xxx, $v2 = v2
        ans = v3 - v1;
    } else {
        ans = v3 - v1;
    }
    cout << ans;
}