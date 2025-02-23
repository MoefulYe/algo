#include <algorithm>
#include <iostream>
#include <string>
int main(int argc, char *argv[]) {
  auto s = std::string();
  std::cin >> s;
  std::reverse(s.begin(), s.end());
  std::cout << s;
  return 0;
}
