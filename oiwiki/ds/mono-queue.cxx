// url = "https://oi.wiki/ds/monotonous-queue/"
// origin = "http://poj.org/problem?id=2823"
#include <bits/stdc++.h>
using namespace std;
auto main() -> int {
  auto elem_num = 0, window_size = 0;
  cin >> elem_num >> window_size;
  auto xs = std::vector<int>(elem_num);
  copy_n(istream_iterator<int>(cin), elem_num, xs.begin());
  auto get = [&](auto cmp) -> vector<int> {
    auto res = vector<int>{};
    auto q = deque<int>{};
    for (auto i = 0; i < window_size; i++) {
      while (!q.empty() && cmp(xs[i], xs[q.back()]))
        q.pop_back();
      q.push_back(i);
    }
    for (auto i = window_size; i < elem_num; i++) {
      if (q.front() <= i - window_size) {
        q.pop_front();
      }
      while (!q.empty() && cmp(xs[i], xs[q.back()]))
        q.pop_back();
      q.push_back(i);
      res.push_back(xs[q.front()]);
    }
    return res;
  };
  auto display = [&](vector<int> &xs) {
    auto len = (int)xs.size();
    for (auto i = 0; i < len; i++) {
      cout << xs[i];
      if (i == len - 1) {
        cout << "\n";
      } else {
        cout << " ";
      }
    }
  };
  auto min = get(less<>{});
  auto max = get(greater<>{});
  display(min);
  display(max);
}
