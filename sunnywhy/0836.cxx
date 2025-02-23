#include <bits/stdc++.h>
#include <limits>
using namespace std;
const int MAXN = 100000;
int a[MAXN], b[MAXN], c[MAXN], result[MAXN * 3];

/* 关键函数 */
int mergeThreeArrays(int a[], int b[], int c[], int n, int result[]) {
  auto i = 0;
  auto j = 0;
  auto k = 0;
  auto n1 = n * 3;
  auto at = [=](int xs[], int i) {
    return i < n ? xs[i] : numeric_limits<int>::max();
  };
  for (auto l = 0; l < n1; l++) {
    auto ai = at(a, i);
    auto bj = at(b, j);
    auto ck = at(c, k);
    if (ai <= bj && ai <= ck) {
      result[l] = ai;
      i++;
    } else if (bj <= ai && bj <= ck) {
      result[l] = bj;
      j++;
    } else {
      result[l] = ck;
      k++;
    }
  }
  return n1;
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }
  int cnt = mergeThreeArrays(a, b, c, n, result);
  for (int i = 0; i < cnt; i++) {
    cout << result[i] << (i == cnt - 1 ? "\n" : " ");
  }
  return 0;
}
