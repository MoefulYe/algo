#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
int main(int argc, char *argv[]) {
  auto n = 0;
  std::cin >> n;
  auto xs = std::vector<int>(n);
  std::copy_n(std::istream_iterator<int>(std::cin), n, xs.begin());
  auto max = std::max_element(xs.begin(), xs.end());
  assert(max != xs.end());
  std::cout << *max;
  return 0;
}
