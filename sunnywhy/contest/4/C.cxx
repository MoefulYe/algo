// url = https://sunnywhy.com/problem/749

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

auto n = 0, k = 0;
auto used = array<bool,16>{};
auto xs = array<int, 16>{};
auto rearrange = array<int, 16>{};

auto dfs(int idx) -> void {
    if(idx == n) {
        for(auto i = 1; i < n; i++) {
            auto A = std::accumulate(rearrange.begin(), rearrange.begin() + i, 0, [](auto acc, auto v) {
                return acc * 10 + v;
            });
            auto B = std::accumulate(rearrange.begin() + i, rearrange.begin() + n, 0, [](auto acc, auto v) {
                return acc * 10 + v;
            });
            auto a = min(A, B);
            auto b = max(A, B);
            auto prod = a * b;
            if(prod == k) {
                cout << a << " " << b;
                exit(0);
            }
        }
    } else {
        for(auto i = 0; i < n; i++) {
            if(used[i]) continue;
            used[i] = true;
            rearrange[idx] = xs[i];
            dfs(idx + 1);
            used[i] = false;
        }
    }
}

auto main() -> int {
    cin >> n >> k;
    copy_n(istream_iterator<int>(cin), n, xs.begin());
    dfs(0);
    assert(false);
}