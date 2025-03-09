// url = https://sunnywhy.com/problem/868
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

auto main() -> int {
  auto n = 0, k = 0;
  cin >> n >> k;
  auto as = vector<int>(n);
  copy_n(istream_iterator<int>(cin), n, as.begin());
  for (auto _ = 0; _ < k; _++) {
    auto min_pos = min_element(as.begin(), as.end());
    (*min_pos)++;
  }
  auto prod = std::accumulate(as.begin(), as.end(), 1, std::multiplies<>{});
  cout << prod;
}
