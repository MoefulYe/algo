// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2611
// TLE
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct Node {
    int weight;
    vector<int> children;
};

auto n = 0;
auto nodes = vector<Node>{};
auto mids = vector<int>{};
auto $ws = multiset<int>{};

auto mid(multiset<int>& xs) -> int {
    auto size = xs.size();
    // if size为奇数 then xs[size / 2]
    // else (xs[size / 2 -1] + xs[size/2])/2
    auto it = xs.begin();
    if(size % 2 == 1) {
        for(auto _ = 0; _ < size / 2; _++) {
            it++;
        }
        auto mid = *it;
        return mid * 2;   
    } else {
        for(auto _ = 0; _ < size / 2 - 1; _++) {
            it++;
        }
        auto first = *it;
        it++;
        auto second = *it;
        return first + second;
    }
}

auto dfs(int idx) -> void {
    const auto& [weight, children] = nodes[idx];
    auto it = $ws.insert(weight);
    mids[idx] = mid($ws);
    for(auto child: children) {
        dfs(child);
    }
    $ws.erase(it);
}

auto main() -> int {
    cin >> n;
    nodes = vector<Node>(n+1);
    mids = vector<int>(n+1);
    for(auto i = 1; i <= n; i++) {
        cin >> nodes[i].weight;
    }
    for(auto _ = 0; _ < n - 1; _++) {
        auto u = 0, v = 0;
        cin >> u >> v;
        nodes[u].children.push_back(v);
    }
    dfs(1);
    for(auto i = 1; i <= n; i++) {
        auto mid = mids[i];
        cout << mid/2;
        if(mid % 2 ==0) {
            cout << ".0";
        } else {
            cout << ".5";
        }
        if(n != i) {
            cout << " ";
        }
    }
}