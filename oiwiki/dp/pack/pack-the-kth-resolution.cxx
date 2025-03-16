// url = https://acm.hdu.edu.cn/showproblem.php?pid=2639
#include <bits/stdc++.h>

using namespace std;
using namespace std::ranges::views;

struct Item {
  int v, w;
  friend auto operator>>(std::istream &is, Item &self) -> std::istream & {
    is >> self.v >> self.w;
    return is;
  }
};
