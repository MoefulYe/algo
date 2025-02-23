#include <algorithm>
#include <iostream>
#include <iterator>
#include <limits>
#include <vector>
int main(int argc, char *argv[]) {
  auto n = 0;
  std::cin >> n;
  auto xs = std::vector<int>(n);
  std::copy_n(std::istream_iterator<int>(std::cin), n, xs.begin());
  auto prefix = std::vector<int>(n);
  auto one_cnt = 0;
  for (auto i = 0; i < n; i++) {
    one_cnt = one_cnt + xs[i];
    prefix[i] = one_cnt;
  }
  auto min = one_cnt - prefix[one_cnt - 1];
  for (auto i = 1; i < n + 1 - one_cnt; i++) {
    min = std::min(one_cnt - prefix[i - 1 + one_cnt] + prefix[i - 1], min);
  }
  std::cout << min;
  return 0;
}
