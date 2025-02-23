#include <cstdint>
#include <iostream>
#include <vector>
int main(int argc, char *argv[]) {
  auto n = 0, k = 0;
  std::cin >> n >> k;
  auto xs = std::vector<int>(k);
  auto pre = 0;
  auto cnt = 0uz;
  for (auto i = 0; i < n; i++) {
    auto x = 0;
    std::cin >> x;
    pre = (pre + x) % k;
    cnt = cnt + xs[pre];
    if (pre == 0) {
      cnt = cnt + 1;
    }
    xs[pre]++;
  }
  std::cout << cnt;
  return 0;
}
