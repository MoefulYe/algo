#include <cassert>
#include <iostream>
auto is_even(int x) -> bool;
auto is_odd(int x) -> bool;

auto is_even(int x) -> bool {
  assert(x >= 0);
  if (x == 0) {
    return true;
  } else {
    return is_odd(x - 1);
  }
}

auto is_odd(int x) -> bool {
  assert(x >= 0);
  if (x == 0) {
    return false;
  } else {
    return is_even(x - 1);
  }
}

auto main() -> int {
  auto n = 0;
  std::cin >> n;
  if (is_odd(n)) {
    std::cout << "Odd";
  } else {
    std::cout << "Even";
  }
}
