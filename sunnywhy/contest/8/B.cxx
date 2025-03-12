// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2630
#include <bits/stdc++.h>
using namespace std;
using Map = map<int, int>;

auto init() -> tuple<Map, int> {
    auto n = 0, k = 0;
    cin >> n >> k;
    auto mp = Map{};
    for(auto _ = 0; _ < n; _++) {
        auto jindu = 0;
        cin >> jindu;
        auto [it, ok] = mp.insert({ jindu, 1 });
        if(!ok) {
            it -> second++;
        }
    }
    return { mp, k };
}

auto first(Map& mp) -> Map::iterator {
    return mp.begin();
}

auto second(Map& mp) -> Map::iterator {
    auto it = mp.begin();
    it++;
    return it;
}

auto main() -> int {
    auto [mp, k] = init();
    assert(mp.size() > 0);
    while(mp.size() > 1) {
        auto it1 = first(mp);
        auto it2 = second(mp);
        auto [jindu1, cnt1] = *it1;
        auto [jindu2, cnt2] = *it2;
        auto consumed = (jindu2 - jindu1) * cnt1;
        if(consumed <= k) {
            k = k - consumed;
            it2 -> second = cnt1 + cnt2;
            mp.erase(it1);
        } else { // consumed > k
            auto v = k / cnt1;
            cout << v + jindu1;
            return 0;
        }
    }
    assert(mp.size() == 1);
    auto [jindu, cnt] = *mp.begin();
    auto v = k / cnt;
    cout << v + jindu;
    return 0;
}