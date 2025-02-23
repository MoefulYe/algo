#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
auto huiwen(std::string_view s) -> bool {
  auto [it1, it2] = std::mismatch(s.begin(), s.end(), s.rbegin(), s.rend());
  return it1 == s.end();
}

auto dfs(std::string_view s, int k) -> bool {
  if (s.empty()) {
    return true;
  } else {
    auto flag = false;
    for (auto i = k; i <= s.length(); i++) {
      if (huiwen(s.substr(0, i))) {
        flag = dfs(s.substr(i), k) || flag;
      }
    }
    return flag;
  }
}

int main(int argc, char *argv[]) {
  auto k = 0;
  auto s = std::string();
  std::cin >> s >> k;
  auto ok = dfs(s, k);
  if (ok) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }
  return 0;
}
