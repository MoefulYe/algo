// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2672

#include <bits/stdc++.h>
using namespace std;

auto fathers = array<int, 128 * 1024>{};

auto n = 0, m = 0;


auto find(int idx) {
    auto i = idx;
    while(fathers[i] > 0) {
        i = fathers[i];
    }
    const auto root = i;
    auto j = idx;
    while(j != root) {
        auto father = fathers[j];
        fathers[j] = root;
        j = father;
    }
    return root;
}

auto uni(int root1, int root2) {
    assert(fathers[root1] < 0);
    assert(fathers[root2] < 0);
    if(root1 == root2) return;
    auto cnt1 = -fathers[root1];
    auto cnt2 = -fathers[root2];
    auto cnt = cnt1 + cnt2;
    if(cnt1 >= cnt2) {
        fathers[root1] = -cnt;
        fathers[root2] = root1;
    } else {
        fathers[root1] = root2;
        fathers[root2] = -cnt;
    }
}

auto init() {
    cin >> n >> m;
    fill(fathers.begin(), fathers.begin() + 1 + n, -1);
    for(auto _ = 0; _ < m; _++) {
        auto x = 0, y = 0, z = 0;
        cin >> x >> y >> z;
        assert(z == 1 || z == 2);
        auto rootx = find(x);
        auto rooty = find(y);
        uni(rootx, rooty);
    }
}


auto main() -> int {
    init();
    auto cnt = 0;
    for(auto i = 1; i <= n; i++) {
        if(fathers[i] < 0) cnt = cnt + 1;
    }
    cout << cnt;
}