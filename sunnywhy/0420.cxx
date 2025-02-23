#include <algorithm>
#include <bits/stdc++.h>
#include <cassert>
using namespace std;
constexpr auto N = 128;
constexpr auto V = 1024;
int w[N];
int c[N];
int dp[V];
auto n = 0, v = 0;
auto main() -> int {
  // init
  cin >> n >> v;
  copy_n(istream_iterator<int>(cin), n, w + 1);
  copy_n(istream_iterator<int>(cin), n, c + 1);
  fill(dp, dp + V, 0);
  // algo
  for (auto i = 1; i <= n; i++) {
    for (auto j = v; j >= 0; j++) {
      if (j >= w[i]) {
        dp[j] = max(dp[j], dp[j - w[i]] + c[i]);
      } else {
        dp[j] = dp[j];
      }
    }
  }
  cout << dp[v];
  return 0;
}
