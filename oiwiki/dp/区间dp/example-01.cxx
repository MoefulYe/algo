// url = https://loj.ac/p/10147

#include <bits/stdc++.h>
using namespace std;
using namespace std::ranges;

auto dp = array<array<int, 512>, 512>{};
auto stones = array<int, 512>{};
auto pres = array<int, 512>{};
