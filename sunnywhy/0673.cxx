#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <span>
#include <unordered_set>
#include <vector>
auto foo(std::vector<int> &xs) -> int {
  auto max = 0;
  auto s = std::unordered_set<int>();
  auto i = 0;
  auto j = 0;
  while (j < xs.size()) {
    auto xj = xs[j];
    if (s.find(xj) != s.end()) { // 第一个不匹配
      max = std::max(max, j - i);
      auto xi = xs[i];
      s.erase(xi);
      i++;
    } else {
      s.insert(xj);
      j++;
    }
  }
  max = std::max(max, (int)xs.size() - i);
  return max;
}

int main(int argc, char *argv[]) {
  auto n = 0;
  std::cin >> n;
  auto xs = std::vector<int>(n);
  std::copy_n(std::istream_iterator<int>(std::cin), n, xs.begin());
  auto max = foo(xs);
  std::cout << max;
  return 0;
}
