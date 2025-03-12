// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2473&contestSubTab=problem&pid=A


#include <bits/stdc++.h>
using namespace std;

auto is_yuanyin(char c) {
    static const auto yuanyins = unordered_set<char>{
        'a', 'e', 'i', 'o', 'u',
        'A', 'E', 'I', 'O', 'U'
    };
    return yuanyins.find(c) != yuanyins.end();
}

auto main() -> int {
    auto s = string{};
    cin >> s;
    auto output1 = string{};
    auto output2 = string{};
    for(auto c: s) {
        if(!is_yuanyin(c)) {
            output1.push_back(c);
        } else {
            output2.push_back(c);
        }
    }
    cout << output1 << output2 << '\n';
}