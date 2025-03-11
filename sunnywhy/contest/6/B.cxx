// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2621

#include <bits/stdc++.h>
using namespace std;

enum class State {
    None,
    K,
    JK,
};

auto rewind(deque<char>& cs) -> State {
    if(cs.size() == 0) {
        return State::None;
    } else if(cs.size() > 0 && cs[0] == 'k') {
        cs.pop_front();
        return State::K;
    } else if(cs.size() > 1 && cs[0] == 'j' && cs[1] == 'k') {
        cs.pop_front();
        cs.pop_front();
        return State::JK;
    }
}  

auto main() -> int {
    auto s = string{};
    cin >> s;

    auto state = State::None;
    auto queue = deque<char>{};
    for(auto i = s.rbegin(); i < s.rend(); i++) {
        auto c = *i;
        switch(state) {
            case State::None:
                if(c == 'k') {
                    state = State::K;
                } else {
                    queue.push_front(c);
                }
                break;
            case State::K:
                if(c == 'j') {
                    state = State::JK;
                } else if (c == 'k') {
                    queue.push_front('k');
                } else {
                    queue.push_front('k');
                    queue.push_front('i');
                    state = State::None;
                }
                break;
            case State::JK:
                if(c == 'i') {
                    state = rewind(queue);
                } else if(c == 'k') {
                    queue.push_front('k');
                    queue.push_front('j');
                    state = State::K;
                } else {
                    // j
                    queue.push_front('k');
                    queue.push_front('j');
                    queue.push_front('j');
                    state = State::None;
                }
                break;
        }
    }
    switch(state) {
        case State::None: break;
        case State::K:
            queue.push_front('k');
            break;
        case State::JK:
            queue.push_front('k');
            queue.push_front('j');
            break;
    }
    auto s1 = string(queue.begin(), queue.end());
    cout << s1;
}

// auto main() -> int {
//     auto input = string{};
//     constexpr auto ijk = string_view("ijk");
//     cin >> input;
//     while(true) {
//         auto pos = input.rfind(ijk);
//         if(pos == string::npos) {
//             break;
//         }
//         input.erase(input.begin() + pos, input.begin() + pos + ijk.size());
//     }
//     cout << input;
//     return 0;
// }