#include <algorithm>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

auto partition(int *base, int len) -> int {
  auto pivot = base[0];
  auto i = 0;
  auto j = len - 1;
  while (i < j) {
    while (i < j && base[j] > pivot)
      j--;
    base[i] = base[j];
    while (i < j && base[i] <= pivot)
      i++;
    base[j] = base[i];
  }
  base[i] = pivot;
  return i;
}

// auto qsort(int *base, int len) -> void {
//   if (len <= 1) {
//     return;
//   }
//   auto pivot = partition(base, len);
//   qsort(base, pivot);
//   qsort(base + pivot + 1, len - pivot - 1);
// }

auto qsort(int *first, int *last) -> void {
  if (first == last) {
    return;
  }
  auto pivot = *first;
  auto mid1 =
      std::partition(first, last, [pivot](const auto &e) { return e < pivot; });
  auto mid2 =
      std::partition(mid1, last, [pivot](const auto &e) { return e == pivot; });
  qsort(first, mid1);
  qsort(mid2, last);
}

int main(int argc, char *argv[]) {
  auto n = 0;
  std::cin >> n;
  auto xs = std::vector<int>(n);
  std::copy_n(std::istream_iterator<int>(std::cin), n, xs.begin());
  qsort(xs.data(), xs.data() + n);
  for (auto i = 0; i < n; i++) {
    std::cout << xs[i];
    if (i != n - 1) {
      std::cout << ' ';
    }
  }
  return 0;
}
