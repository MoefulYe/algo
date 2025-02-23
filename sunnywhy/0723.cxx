#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <vector>
int main(int argc, char *argv[]) {
  auto n = 0;
  std::cin >> n;
  auto xs = std::vector<int>(n);
  auto prefix = std::vector<int>(n);
  std::copy_n(std::istream_iterator<int>(std::cin), n, xs.begin());
  prefix[0] = xs[0];
  for (auto i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + xs[i];
  }

  auto acc = 0; // 后缀
  auto max_num = 0;
  for (auto j = n - 1; j >= 0; j--) {
    acc = acc + xs[j];
    auto it = std::lower_bound(prefix.begin(), prefix.end(), acc);
    if (it == prefix.end()) {
      assert("unreachable" && false);
    } else if (*it != acc) {
      continue;
    } else if (auto i = it - prefix.begin(); i >= j) { // 相交
      break;
    } else {
      max_num = i - j + n + 1;
    }
  }
  std::cout << max_num;
  return 0;
}
