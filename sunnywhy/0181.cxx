#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
auto diff(std::vector<int> &xs, std::vector<int> &ys) -> std::vector<int> {
  auto res = std::vector<int>();
  auto i = 0;
  auto j = 0;
  while (i < xs.size() && j < ys.size()) {
    auto x = xs[i];
    auto y = ys[j];
    if (x == y) {
      i++;
      j++;
    } else if (x < y) {
      res.push_back(x);
      i++;
    } else {
      j++;
    }
  }
  while (i < xs.size()) {
    auto x = xs[i];
    res.push_back(x);
    i++;
  }
  return res;
}

int main(int argc, char *argv[]) {
  auto n = 0, m = 0;
  std::cin >> n >> m;
  auto xs = std::vector<int>(n), ys = std::vector<int>(m);
  std::copy_n(std::istream_iterator<int>(std::cin), n, xs.begin());
  std::copy_n(std::istream_iterator<int>(std::cin), m, ys.begin());
  auto d = diff(xs, ys);
  auto cnt = (int)d.size();
  for (auto i = 0; i < cnt; i++) {
    std::cout << d[i];
    if (i != cnt - 1) {
      std::cout << ' ';
    }
  }
  return 0;
}
