#include <iostream>
#include <string>
#include <string_view>
auto is_sub(std::string_view s /*子序列*/,
            std::string_view t /*主串*/) -> bool {
  auto i = 0; // 子串
  for (auto c : t) {
    if (s[i] == c) {
      i++;
      if (i == s.size()) {
        break;
      }
    }
  }
  return i == s.size();
}

int main(int argc, char *argv[]) {
  auto s = std::string(), t = std::string();
  std::cin >> s >> t;
  if (is_sub(s, t)) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  }
  return 0;
}
