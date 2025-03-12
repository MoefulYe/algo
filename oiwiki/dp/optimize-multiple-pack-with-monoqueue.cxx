// https://oi.wiki/dp/opt/monotonous-queue-stack/
#include <bits/stdc++.h>
using namespace std;
namespace views = std::ranges::views;

struct Item {
  int v, w, m;
  friend auto operator>>(istream &is, Item &self) -> istream & {
    is >> self.v >> self.w >> self.m;
    return is;
  }
};

auto n = 0, w = 0, pred = 1, now = 0;
auto items = vector<Item>{};
auto dp = array<vector<int>, 2>{};
auto q = deque<int>{};

auto main() -> int {
  cin >> n >> w;
  items = vector<Item>(n + 1);
  dp = {vector<int>(w + 1), vector<int>(w + 1)};
  ranges::copy_n(istream_iterator<Item>(cin), n, items.begin() + 1);

  for (auto [v_i, w_i, m_i] : items | views::drop(1)) {
    auto dp_now = span(dp[now]);
    auto dp_pred = span(dp[pred]);
    for (auto j : ranges::iota_view{0, w_i}) {
      q.clear();
      for (auto k = 0; w_i * k + j <= w; k = k + 1) {
        const auto weight_of_k = w_i * k + j;
        // 弹出范围外
        // 本次循环依赖前面m_i个状态故不取等号
        while (!q.empty() && q.front() < k - m_i) {
          q.pop_front();
        }

        while (true) {
          if (q.empty())
            break;
          const auto weight_of_qback = q.back() * w_i + j;
          auto if_derived_from_qback =
              dp_pred[weight_of_qback] + (k - q.back()) * v_i;
          auto no_derived = dp_pred[weight_of_k];
          if (if_derived_from_qback <= no_derived) {
            q.pop_back();
          } else {
            break;
          }
        }
        q.push_back(k);

        const auto weight_of_qfront = q.front() * w_i + j;
        dp_now[weight_of_k] = dp_pred[weight_of_qfront] + (k - q.front()) * v_i;
      }
    }
    swap(pred, now);
  }
  cout << dp[pred][w];
}
