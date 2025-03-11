// url = https://oi.wiki/dp/knapsack/#%E5%BC%95%E5%85%A5
// origin = https://www.luogu.com.cn/problem/P2871
#include <bits/stdc++.h>
using namespace std;

struct Item {
  int w, d; // 重量, 价值
  friend auto operator>>(istream &is, Item &self) -> istream & {
    is >> self.w >> self.d;
    return is;
  }
};
auto n = 0, m = 0;
int value[13000];
Item items[3500];
auto main() -> int {
  cin >> n >> m;
  fill(value, value + n + 1, 0);
  copy_n(istream_iterator<Item>(cin), n, items + 1);
  for (auto i = 1; i <= n; i++) {
    auto [w, d] = items[i];
    for (auto j = m; j >= w; j--) {
      value[j] = max(value[j], value[j - w] + d);
    }
  }
  cout << value[m];
}
