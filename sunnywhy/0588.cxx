#include <algorithm>
#include <iostream>
#include <iterator>
#include <tuple>
#include <vector>
int main(int argc, char *argv[]) {
  auto n = 0;
  std::cin >> n;
  auto xs = std::vector<int>(n);
  auto ys = std::vector<std::tuple<int, int>>(n); // (2,3)
  auto acc = std::tuple{0, 0};
  for (auto i = 0; i < n; i++) {
    auto [cnt2, cnt3] = acc;
    if (xs[i] == 2) {
      cnt2++;
    } else if (xs[i] == 3) {
      cnt3++;
    }
    acc = {cnt2, cnt3};
    ys[i] = acc;
  }

  auto [cnt2, cnt3] = acc;
  auto it =
      std::find_if(ys.begin(), ys.end(), [=](const std::tuple<int, int> &v) {
        auto [_cnt2, _cnt3] = v;
        return _cnt2 * 2 == cnt2 && _cnt3 == cnt3;
      });
  if (it != ys.end()) {
    std::cout << it - ys.begin();
  } else {
    std::cout << -1;
  }

  // std::copy_n(std::istream_iterator<int>(std::cin), n, xs.begin());
  // auto prod = 1;
  // for (auto i = 0; i < n; i++) {
  //   prod = prod * xs[i];
  //   ys[i] = prod * prod;
  // }
  // auto it = std::lower_bound(ys.begin(), ys.end(), prod);
  // if (*it == prod) {
  //   std::cout << it - ys.begin();
  // } else {
  //   std::cout << -1;
  // }
  return 0;
}
