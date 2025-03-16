// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2481&contestSubTab=problem&pid=D

#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<tuple<int, int>>>; // (_, 距离)
auto init() -> tuple<Graph, int, int, vector<int>> {
    auto n = 0, m = 0, t = 0;
    cin >> n >> m >> t;
    auto g = Graph(n);
    for(auto _ = 0; _ < n; _++) {
        auto u = 0, v = 0, d = 0;
        cin >> u >> v >> d;
        g[u].push_back({v, d});
        g[v].push_back({u, d});
    }
    auto s = 0, t= 0;
    auto k = 0;
    cin >> s >> t >> k;
    auto wolves = vector<int>(k);
    copy_n(istream_iterator<int>(cin), k, wolves.begin());
    return {
        g, s, t, wolves
    };
}

auto main() -> int {
    const auto [graph, start, end, wolves] = init();
    auto dijk = [&](int s) -> vector<int> {
        auto visited = vector<bool>(graph.size());
        auto dists = vector<int>(graph.size(), numeric_limits<int>::max());
        dists[s] = 0;
        for(auto i = 0; i < graph.size(); i++) {
            auto min_dist = numeric_limits<int>::max();
            auto min_idx = -1;
            for(auto j = 0; j < graph.size(); j++) {
                if(visited[j]) continue;
                if(min_dist > dists[j]) {
                    min_dist = dists[j];
                    min_idx = j;
                }
            }
            if(min_dist == numeric_limits<int>::max()) {
                break;
            }
            visited[min_idx] = true;
            dists[min_idx] = min_dist;
            for(auto [k, dist_jk]: graph[min_dist]) {
                auto& dist = dists[k];
                dist = std::min(dist, min_dist + dist_jk);
            }
        }
        return dists;
    };
    auto wolf_min_dists = [&]() -> vector<int> {
        auto ans = vector<int>(graph.size(), numeric_limits<int>::max());
        for(auto wolf: wolves) {
            auto dists = dijk(wolf);
            for(auto i = 0; i < graph.size(); i++) {
                ans[i] = std::min(ans[i], dists[i]);
            }
        }
        return ans;
    }();
    auto visited = vector<bool>(graph.size());
    auto dists = vector<int>(graph.size(), numeric_limits<int>::max());
    auto wolf_dists = vector<int>(graph.size(), 0);
    dists[start] = 0;
    for(auto i = 0; i < graph.size(); i++) {
        auto min_dist = numeric_limits<int>::max();
        auto min_idx = -1;
        for(auto j = 0; j < graph.size(); j++) {
            if(visited[j]) continue;
            if(min_dist > dists[j]) {
                min_dist = dists[j];
                min_idx = j;
            }
        }
        if(min_dist == numeric_limits<int>::max()) {
            break;
        }
        visited[min_idx] = true;
        dists[min_idx] = min_dist;
        for(auto [k, dist_jk]: graph[min_dist]) {
            auto& dist = dists[k];
            dist = std::min(dist, min_dist + dist_jk);
        }
    }
}