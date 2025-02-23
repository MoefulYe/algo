/**
 * @param a: 整数数组
 * @param n: 数组中的元素个数
 * @return: 返回一个整数，表示满足条件的最小下标
 */
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
int smallestIndex(int a[], int n) {
  auto postfix = std::vector<int>(n); // 最小值
  postfix.back() = a[n - 1];
  for (auto i = n - 2; i >= 0; i--) {
    postfix[i] = std::min(postfix[i + 1], a[i]);
  }
  auto max = std::numeric_limits<int>::min();
  auto i = 0;
  for (; i < n - 1; i++) {
    max = std::max(max, a[i]);
    if (max <= postfix[i + 1]) {
      break;
    }
  }
  return i;
}
