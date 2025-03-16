// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2671

#include <bits/stdc++.h>
using namespace std;

// auto get_primes(int n) -> vector<int> {
//     auto is_prime = vector<bool>(n+1, true);
//     auto primes = vector<int>{};
//     is_prime[0] = false;
//     is_prime[1] = false;
//     for(auto i = 2; i <= n; i++) {
//         if(is_prime[i]) {
//             primes.push_back(i);
//             // NOTE 这里 i * i有溢出的问题
//             for(auto j = i * i; j <= n; j = j + i) {
//                 is_prime[j] = false;
//             }
//         }
//     }
//     return primes;
// }

// // 假定可以分解成n个质数的形式，必定有一个质因子是2,假定指数大于1所以有一个2与其他的质因子
// auto main() -> int {
//     auto n = 0;
//     cin >> n;
//     auto primes = get_primes(n/2);
//     if(n >= 8) {
//         cout << primes.size();
//     } else if (n == 1) {
//         cout << 0;
//     } else {
//         cout << primes.size() - 1;
//     }
// }

auto get_primes(int n) -> vector<int> {
    auto is_prime = vector<bool>(n+1, true);
    auto primes = vector<int>{};
    is_prime[0] = false;
    is_prime[1] = false;
    for(auto i = 2; i * i <= n; i++) {
        if(is_prime[i]) {
            for(auto j = i * i; j <= n; j = j + i) {
                is_prime[j] = false;
            }
        }
    }
    for(auto i = 2; i <= n; i = i + 1) {
        if(is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

// 假定可以分解成n个质数的形式，必定有一个质因子是2,假定指数大于1所以有一个2与其他的质因子
auto main() -> int {
    auto n = 0;
    cin >> n;
    auto primes = get_primes(n/2);
    if(n >= 8) {
        cout << primes.size();
    } else if (n == 1) {
        cout << 0;
    } else {
        cout << primes.size() - 1;
    }
}