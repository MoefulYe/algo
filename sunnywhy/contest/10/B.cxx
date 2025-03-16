// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2666

#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    auto n = 0;
    cin >> n;
    auto towers = multiset<int>{};
    auto cnt = 0;
    for(auto _ = 0; _ < n; _++) {
        auto x = 0;
        cin >> x;
        auto it = towers.lower_bound(x);
        if(it != towers.begin()) {
            it--;
            towers.erase(it);
        }
        towers.insert(x);
    }
    cout << towers.size();
}