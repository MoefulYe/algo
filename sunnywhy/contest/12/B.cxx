// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2481&contestSubTab=problem&pid=B

#include <bits/stdc++.h>
using namespace std;

// h行w列 0based

constexpr auto DIRS = array<tuple<int,int>, 4>{
    tuple{1, 0}, // d
    {0, -1}, // l
    {0, 1}, // r
    {-1, 0}, // u
};

constexpr auto DIR_CHAR = array<char, 4>{
    'D',
    'L',
    'R',
    'U'
};

auto mat = array<array<bool,128>,128>{};
auto h = 0, w = 0, n = 0, goal = 0;
auto paths = vector<int>{};

auto dfs(int r, int c) -> int {
    if(paths.size() + 1 >= goal) {
        for(auto dir: paths) {
            cout << DIR_CHAR[dir];
        }
        exit(0);
    } else {
        for(auto i = 0; i < 4; i++) {
            auto [dr, dc] = DIRS[i];
            auto r1 = r + dr;
            auto c1 = c + dc;
            if(r1 >= 0 && r1 < h && c1 >= 0 && c1 < w && !mat[r1][c1]) {
                paths.push_back(i);
                mat[r1][c1] = true;
                dfs(r1, c1);
                mat[r1][c1] = false;
                paths.pop_back();
            }
        }
    }
}

auto init() {
    cin >> h >> w >> n;
    auto tmp = (h * w - n);
    goal = (tmp + 1) / 2;
    for(auto _ = 0; _ < n; _++) {
        auto r = 0, c = 0;
        cin >> r >> c;
        assert(!mat[r][c]);
        mat[r][c] = true;
    }
}

auto main() -> int {
    init();
    mat[0][0] = true;
    dfs(0, 0);
    assert(false);
}