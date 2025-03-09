// url = https://sunnywhy.com/problem/763

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
using Martix = array<array<int, 3>,3>;

// auto input() -> Martix {
//     auto ret = Martix{};
//     for(auto i = 0; i < 3; i++) {
//         for(auto j = 0; j < 3; j++) {
//             cin >> ret[i][j];
//         }
//     }
//     return ret;
// }

// auto diff(const Martix& lhs, const Martix& rhs) -> int {
//     auto cnt = 0;
//     for(auto i = 0; i < 3; i++) {
//         for(auto j = 0; j < 3; j++) {
//             if(lhs[i][j] != rhs[i][j]) cnt = cnt + 1;
//         }
//     }
//     return cnt;
// }

// auto main() -> int {
//     auto before = input();
//     auto now = input(); 
//     auto cnt = diff(before, now);
//     if(cnt == 0) {
//         cout << 0;
//     } else if(cnt == 1) {
//         cout << -1;
//     } else {
//         auto step = cnt - 1;
//         if(step > 16) {
//         cout << -1;
//         }
//     }
// }