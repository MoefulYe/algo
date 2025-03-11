#include <bits/stdc++.h>
using namespace std;

struct Item {
    int l,r,v;
    friend auto operator>>(istream& is, Item& self) -> istream& {
        cin >> self.l >> self.r >> self.v;
        return is;
    }
};

constexpr auto I64_MAX = numeric_limits<int64_t>::max();
constexpr auto I64_MIN = numeric_limits<int64_t>::min();
using i64 = int64_t;

auto n = 0, w = 0;
int g[512][512]; //选择前i个物品, 背包大小为j时候的最小种类数量
i64 dp[512][512]; //选择前i个物品，背包大小为j时候的最大价值
Item items[512];

auto main() -> int {
    cin >> n >> w;
    fill(g[0], g[0] + 512, INT_MAX);
    fill(dp[0], dp[0] + 512, I64_MIN);
    dp[0][0] = 0;
    g[0][0] = 0;
    copy_n(istream_iterator<Item>(cin), n, items + 1);
    for(auto i = 1; i <= n; i++) { // 第i样物品
        auto [l,r,v] = items[i];
        for(auto j = 0; j <= w; j++) { // 背包大小为j
            auto max_vsum = I64_MIN;
            auto min_csum = INT_MAX;
            for(auto k = l; k <= r; k++) { // 枚举所有可能
                auto vsum = dp[i-1][j];
                auto csum = g[i-1][j];
                if(k <= j) { // 背包装得下
                    auto vsum_if_taken = dp[i - 1][j - k] + v;
                    auto csum_if_taken = g[i - 1][j - k] + 1;
                    if(vsum_if_taken > vsum || vsum_if_taken == vsum && csum_if_taken < csum) {
                        vsum = vsum_if_taken;
                        csum = csum_if_taken;
                    } 
                }
                if(vsum > max_vsum || vsum == max_vsum && csum < min_csum) {
                    max_vsum = vsum;
                    min_csum = csum;
                } 
            }
            dp[i][j] = max_vsum;
            g[i][j] = min_csum;
        }
    }
    if(dp[n][w] < 0) {
        cout << "-1 -1\n"; 
    } else {
        cout << dp[n][w] << " " << g[n][w] << "\n";
    }
}