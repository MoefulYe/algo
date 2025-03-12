// url = https://oi.wiki/ds/monotonous-queue/
// origin = https://www.luogu.com.cn/problem/P2698

#include <bits/stdc++.h>
using namespace std;
namespace ranges = std::ranges;
struct Rain {
  int x, y;
  friend auto operator<=>(const Rain &lhs, const Rain &rhs) {
    return lhs.x <=> rhs.x;
  }
  friend auto operator>>(istream &is, Rain &self) -> istream & {
    is >> self.x >> self.y;
    return is;
  }
};

auto main() -> int {
  auto n = 0, d_least = 0;
  cin >> n >> d_least;
  auto rains = std::vector<Rain>(n);
  ranges::copy_n(istream_iterator<Rain>(cin), n, rains.begin());
  ranges::sort(rains, less{});
  auto l = 0;
  auto r = 0;
  auto min_queue = deque<int>{0};
  auto max_queue = deque<int>{0};
  auto min_w = numeric_limits<int>::max();
  while (true) {
    auto d = rains[max_queue.front()].y - rains[min_queue.front()].y;
    auto w = rains[r].x - rains[l].x;
    if (d < d_least) {
      r = r + 1;
      if (r == n) {
        break;
      }
      while (!min_queue.empty() && rains[min_queue.back()].y >= rains[r].y) {
        min_queue.pop_back();
      }
      min_queue.push_back(r);
      // NOTE 注意取等号
      while (!max_queue.empty() && rains[max_queue.back()].y <= rains[r].y) {
        max_queue.pop_back();
      }
      max_queue.push_back(r);
    } else {
      min_w = std::min(min_w, w);
      if (min_queue.front() == l) {
        min_queue.pop_front();
      }
      if (max_queue.front() == l) {
        max_queue.pop_front();
      }
      l = l + 1;
    }
  }
  if (min_w == numeric_limits<int>::max()) {
    cout << "-1";
  } else {
    cout << min_w;
  }
}
