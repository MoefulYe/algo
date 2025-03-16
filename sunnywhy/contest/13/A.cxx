// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2483&contestSubTab=problem&pid=A

#include <bits/stdc++.h>
using namespace std;

auto main() -> int {
    auto n = 0, a = 0;
    cin >> n >> a;
    // 假期0 假期1 假期2 假期3 ... 
    // 假定[i,j]中间的工作时间不能被完全覆盖那么任意包含[i,j]的区间也不能覆盖
    // dp[i,j]: (剩余假期数量, 休息时长)
    // dp[i, j + 1] = 
    auto pred = 1;
    auto vacations = vector<pair<int,int>>{}; // 假期第一天, 工作的第一天
    for(auto i = 0; i < n; i++) {
        auto d = 0;
        cin >> d;
        assert(d == 1 || d == 0);
        if(d == 0 && pred == 1) {
            vacations.push_back({i, n});
        } else if(d == 1 && pred == 0) {
            vacations.back().second = i;
        }
        pred = d;
    }
    if(vacations.empty()) {
        cout << a;
        return 0;
    }
    auto max = 0;
    auto l = 0;
    while(true) {
        if(l >= vacations.size()) break;
        if(n - vacations[l].first <= max) break;
        auto r = l;
        auto rest_a = a;
        auto vacation_len = vacations[l].second - vacations[l].first;
        while(true) {
            auto r1 = r + 1;
            if(vacations.size() <= r1) break;
            auto gap = vacations[r1].first - vacations[r].second;
            if(gap > rest_a) break;
            rest_a = rest_a - gap;
            r = r1;
            vacation_len = vacation_len + vacations[r].second - vacations[r].first;
        }
        max = std::max(max, min(vacation_len + a, n));
        l = l + 1;
    }
    cout << max;
}