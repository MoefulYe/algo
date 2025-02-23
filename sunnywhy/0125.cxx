#include <cstdint>
#include <iostream>
auto f(int n, int upper_bound) -> int32_t {
  if (n <= 1 || upper_bound <= 0) {
    return 0;
  }
  auto ans = 0;
  for (auto i = 1; i <= upper_bound; i++) {
    ans = ans + f(n - i, i);
    if (n - i > 0 && n - i <= i && n - i <= upper_bound) {
      ans = ans + 1;
    }
  }
  return ans;
}

int main(int argc, char *argv[]) {
  auto n = 0;
  std::cin >> n;
  std::cout << f(n, n - 1);
  return 0;
}
