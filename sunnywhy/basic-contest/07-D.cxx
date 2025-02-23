#include <cassert>
#include <iostream>
auto main() -> int {
  auto a = 25, b = 0, c = 0;
  std::cin >> a >> b >> c;
  if (b < 25) {
    assert(false);
  }
}
