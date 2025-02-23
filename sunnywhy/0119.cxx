#include <iostream>
#include <sstream>
#include <string>
std::string s;
auto hanoi(int n, char from, char to, char via) -> int {
  if (n == 0) {
    return 0;
  }
  auto cnt1 = hanoi(n - 1, from, via, to);
  std::stringstream ss;
  ss << from << "->" << to << "\n";
  s += ss.str();
  auto cnt2 = hanoi(n - 1, via, to, from);
  return cnt1 + cnt2 + 1;
};
int main(int argc, char *argv[]) {
  auto n = 0;
  std::cin >> n;
  auto cnt = hanoi(n, 'A', 'C', 'B');
  std::cout << cnt << "\n" << s;
  return 0;
}
