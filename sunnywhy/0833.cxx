#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int a[MAXN], b[MAXN];

// 对应: ai >= bi

/* 关键函数 */
int minShift(int a[], int b[], int n) {
  auto i = n - 1;
  auto j = n - 1;
  auto res = 0;
  while (j >= 0) {
    if (a[i] >= b[j]) {
      i--;
      j--;
    } else {
      j--;
      res++;
    }
  }
  return res;
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
  int result = minShift(a, b, n);
  cout << result;
  return 0;
}
