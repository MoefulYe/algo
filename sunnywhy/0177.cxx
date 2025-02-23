#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
auto merge_sort(int *base, int len) -> void {
  if (len <= 1) {
    return;
  }
  auto base1 = base;
  auto len1 = len / 2;
  auto base2 = base + len1;
  auto len2 = len - len1;
  merge_sort(base1, len1);
  merge_sort(base2, len2);
  std::inplace_merge(base1, base2, base + len);
}

int main(int argc, char *argv[]) {
  auto n = 0;
  std::cin >> n;
  auto xs = std::vector<int>(n);
  std::copy_n(std::istream_iterator<int>(std::cin), n, xs.begin());
  auto p = xs.begin();
  merge_sort(xs.data(), n);
  for (auto i = 0; i < xs.size(); i++) {
    std::cout << xs[i];
    if (i != xs.size() - 1) {
      std::cout << ' ';
    }
  }
  return 0;
}
