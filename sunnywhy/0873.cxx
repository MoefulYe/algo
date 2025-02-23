/**
 * @param A: 第一个整数数组
 * @param lenA: 数组A中的元素个数
 * @param B: 第二个整数数组
 * @param lenB: 数组B中的元素个数
 * @param C: 第三个整数数组
 * @param lenC: 数组C中的元素个数
 * @return: 返回一个整数，表示三个数组中的公共元素个数
 */
int countCommon(int A[], int lenA, int B[], int lenB, int C[], int lenC) {
  auto i = 0; // A
  auto j = 0; // B
  auto k = 0; // C
  auto common = 0;
  while (i < lenA && j < lenB && k < lenC) {
    auto a = A[i];
    auto b = B[j];
    auto c = C[k];
    if (a == b && b == c) {
      i++;
      j++;
      k++;
      common++;
    } else if (a > b && a > c) {
      i++;
    } else if (b > a && b > c) {
      j++;
    } else /* if (c > a && c > b) */ {
      k++;
    }
  }
  return common;
}
