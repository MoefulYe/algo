#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
int main(int argc, char *argv[]) {
  auto n = 0, m = 0;
  std::cin >> n >> m;
  auto xs = std::vector<int>(n);
  auto ys = std::vector<int>(m);
  std::copy_n(std::istream_iterator<int>(std::cin), n, xs.begin());
  std::copy_n(std::istream_iterator<int>(std::cin), m, ys.begin());
  std::sort(xs.begin(), xs.end());
  std::sort(ys.begin(), ys.end());

  auto cnt = 0;
  auto i = 0, j = 0;
  while (i < n && j < m) {
    auto x = xs[i];
    auto y = ys[j];
    if (x <= y) {
      cnt++;
      i++;
      j++;
    } else { // x > y
      j++;
    }
  }
  std::cout << cnt;
  return 0;
}
