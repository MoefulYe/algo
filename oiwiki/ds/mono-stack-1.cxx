// url = https://www.luogu.com.cn/problem/P1901
#include <bits/stdc++.h>
using namespace std;
namespace views = std::ranges::views;

struct Tower {
  int h, v;
  friend auto operator>>(istream &is, Tower &self) -> istream & {
    is >> self.h >> self.v;
    return is;
  }
};

auto main() -> int {
  auto n = 0;
  cin >> n;
  auto towers = vector<Tower>(n);
  ranges::copy_n(istream_iterator<Tower>(cin), n, towers.begin());
  auto energies = vector<int>(n);
  auto s = deque<int>{};
  for (const auto i : ranges::iota_view{0, n}) {
    while (!s.empty() && towers[s.back()].h < towers[i].h) {
      energies[i] += towers[s.back()].v;
      s.pop_back();
    }
    s.push_back(i);
  }
  s.clear();
  for (const auto i : ranges::iota_view{0, n} | views::reverse) {
    while (!s.empty() && towers[s.back()].h < towers[i].h) {
      energies[i] += towers[s.back()].v;
      s.pop_back();
    }
    s.push_back(i);
  }
  auto sum = reduce(energies.begin(), energies.end(), 0,
                    [](auto a, auto b) { return max(a, b); });
  cout << sum;
}
