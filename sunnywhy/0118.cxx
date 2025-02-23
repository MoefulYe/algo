#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <string>

using namespace std::literals;
int main(int argc, char *argv[]) {
  auto fib = std::array<uint64_t, 32>{1, 1};
  auto n = 0;
  std::cin >> n;
  for (auto i = 2; i <= n; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }
  return 0;
}
