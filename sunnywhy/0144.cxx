#include <cassert>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <vector>
auto cur = std::string();
auto possiblities = std::set<std::string>{};
auto n = 0;
auto dfs(int cntl, int cntr, int stk) -> void {
  if (cntl == n && cntr == n) {
    possiblities.insert(cur);
  } else if (stk == 0) {
    // 只能插入左括号
    assert(cntl < n);
    cur.push_back('(');
    dfs(cntl + 1, cntr, stk + 1);
    cur.pop_back();
  } else {
    if (cntl < n) {
      cur.push_back('(');
      dfs(cntl + 1, cntr, stk + 1);
      cur.pop_back();
    }
    if (cntr < n) {
      cur.push_back(')');
      dfs(cntl, cntr + 1, stk - 1);
      cur.pop_back();
    }
  }
}

auto main(int argc, char *argv[]) -> int {
  std::cin >> n;
  dfs(0, 0, 0);
  for (auto &s : possiblities) {
    std::cout << s << "\n";
  }
  return 0;
}
