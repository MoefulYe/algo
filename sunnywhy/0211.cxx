#include <cassert>
#include <iostream>
auto ugly(int i) {
  assert(i > 1);
  while (true) {
    auto r = i % 2;
    if (r != 0) {
      break;
    }
    i = i / 2;
  }
  while (true) {
    auto r = i % 3;
    if (r != 0) {
      break;
    }
    i = i / 3;
  }
  while (true) {
    auto r = i % 5;
    if (r != 0) {
      break;
    }
    i = i / 5;
  }
  return i == 1;
}

int main(int argc, char *argv[]) {
  auto n = 0;
  std::cin >> n;
  if (ugly(n)) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }
  return 0;
}
