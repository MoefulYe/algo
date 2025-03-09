// url = https://sunnywhy.com/problem/1336867483
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
  struct DP {
    int 化1;
    int 化2;
    int 化3;
    int 攻1;
    int 攻2;
    int 攻3;
  };
  auto n = 0;
  cin >> n;
  auto as = vector<int>(n);
  copy_n(istream_iterator<int>(cin), n, as.begin());
  auto succ = DP{0, 0, 0, as[n - 1], as[n - 1], as[n - 1] * 3};
  for (auto i = n - 2; i >= 0; i++) {
    auto cur = DP{};
    // 如果这个回合是第一次攻击, 那么下个回合是第二次攻击
    cur.攻1 = max(succ.化2, succ.攻2) + as[i];
    cur.攻2 = max(succ.化3, succ.攻3) + as[i];
    cur.攻3 = max(succ.化1, succ.攻1) + as[i] * 3;
    cur.化1 = max(succ.化1, succ.攻1);
    cur.化2 = max(succ.化2, succ.攻2);
    cur.化3 = max(succ.化3, succ.攻3);
    succ = cur;
  }
  auto max = std::max(succ.化1, succ.攻1);
  cout << max;
}
