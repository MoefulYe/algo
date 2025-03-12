// url = https://www.luogu.com.cn/problem/P5788
#include <bits/stdc++.h>
using namespace std;
auto main() -> int {
  auto n = 0;
  cin >> n;
  auto xs = vector<int>(n + 1);
  auto ans = vector<int>(n + 1);
  ranges::copy_n(istream_iterator<int>(cin), n, xs.begin() + 1);
  auto s = stack<int>{};
  for (auto i : ranges::iota_view{1, n + 1}) {
    while (!s.empty() && xs[s.top()] < xs[i]) {
      ans[s.top()] = i;
      s.pop();
    }
    s.push(i);
  }
  for (auto nge : ans | views::drop(1)) {
    cout << nge << " ";
  }
  return 0;
}
