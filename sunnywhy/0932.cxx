#include <cassert>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>
auto stk = std::vector<char>{};
auto cur = std::vector<char>{};
auto all = std::set<std::string>{};
auto n = 0;

auto dfs(int cntl, int cntr) -> void {
  if (cntl == n && cntr == n) {
    all.emplace(std::begin(cur), std::end(cur));
    return;
  }
  if (cntl < n) {
    stk.push_back('[');
    cur.push_back('[');
    dfs(cntl + 1, cntr);
    stk.pop_back();
    cur.pop_back();
    stk.push_back('{');
    cur.push_back('{');
    dfs(cntl + 1, cntr);
    stk.pop_back();
    cur.pop_back();
  }

  if (stk.empty()) {
    return;
  } else if (auto back = stk.back(); back == '{') {
    stk.pop_back();
    cur.push_back('}');
    dfs(cntl, cntr + 1);
    cur.pop_back();
    stk.push_back('{');
  } else if (back == '[') {
    stk.pop_back();
    cur.push_back(']');
    dfs(cntl, cntr + 1);
    cur.pop_back();
    stk.push_back('[');
  } else {
    throw back;
  }
}

auto main() -> int {
  std::cin >> n;
  assert(n % 2 == 0);
  n = n / 2;
  try {
    dfs(0, 0);
    for (auto &s : all) {
      std::cout << s << '\n';
    }
  } catch (char c) {
    std::cout << c;
  }
}
