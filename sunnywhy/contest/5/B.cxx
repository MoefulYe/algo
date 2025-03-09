// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2609

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

using Iter = set<int>::iterator;

auto foo(Iter begin, Iter end) -> tuple<Iter,int> {
    if(begin == end) {
        return {begin, 0};
    }
    auto it = begin;
    auto pred = *it;
    auto cnt = 1;
    it++;
    for(;it != end; it++) {
        auto cur = *it;
        if(cur != pred + 1) {
            return {it, cnt};
        } else {
            cnt = cnt + 1;
            pred = cur;
        }
    }
    return {end, cnt};
}

auto main() -> int {
    auto n = 0;
    auto xs = set<int>{};
    cin >> n;
    for(auto _ = 0; _ < n; _++) {
        auto x = 0;
        cin >> x;
        xs.insert(x);
    }
    assert(n > 0);
    auto it = xs.begin();
    auto end = xs.end();
    auto max = numeric_limits<int>::min();
    while(true) {
        auto [$it, cnt] = foo(it, end);
        max = std::max(max, cnt);
        it = $it;
        if(it == end) break;
    }
    assert(max > 0);
    cout << max;
    return 0;
}