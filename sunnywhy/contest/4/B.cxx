// url = https://sunnywhy.com/problem/769

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

using Node = vector<int>;
using Nodes = vector<Node>;
auto n = 0;
auto nodes = Nodes{};
auto $min = numeric_limits<int>::max();

auto calc_cnts(int idx) -> int {
    auto ret = 1;
    for(auto child : nodes[idx]) {
        ret = ret + calc_cnts(child);
    }
    $min = std::min($min, abs(n - ret * 2));
    return ret;
}

auto main() -> int {
    cin >> n;
    nodes = Nodes(n+1);
    for(auto _ = 0; _ < n - 1; _++) {
        auto a = 0, b = 0;
        cin >> a >> b;
        nodes[a].push_back(b);
    }
    calc_cnts(1);
    cout << $min;
}
