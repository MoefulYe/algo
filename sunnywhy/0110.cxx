#include <iostream>
#include <string>
auto foo(int n, std::string &output) -> void {
  if (n == 0) {
    output.append("我的小鲤鱼");
  } else {
    output.append("抱着");
    foo(n - 1, output);
    output.append("的我");
  }
}

int main(int argc, char *argv[]) {
  auto res = std::string("吓得我抱起了");
  auto n = 0;
  std::cin >> n;
  foo(n, res);
  return 0;
}
