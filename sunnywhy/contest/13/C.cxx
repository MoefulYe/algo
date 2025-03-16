// url = https://sunnywhy.com/camp/2304/model/2592?itemId=2697

#include <bits/stdc++.h>
using namespace std;

auto n = 0, q = 0, stun = 0;
auto names = vector<string>{};
constexpr auto HEAD = 0;
struct Student {
    int next = HEAD;
    int pred = HEAD;
};
auto students = vector<Student>{};

auto main() -> int {
    cin.tie(nullptr) -> sync_with_stdio(false);
    cin >> n >> q;
    stun = n * 2;
    names = vector<string>(stun + 1);
    students = vector<Student>(stun + 1);
    for(auto i = 1; i <= stun; i++) {
        auto name = string{};
        cin >> name;
        names[i] = move(name);
    }
    for(auto i = 0; i <= stun; i++) {
        students[i] = {
            i + 1,
            i - 1
        };
    }
    students[0].pred = stun;
    students[stun].next = 0;
    auto insts = string{};
    cin >> insts;
    auto pos = 1;
    for(auto inst : insts) {
        switch(inst) {
            case 'G': {
                const auto [next, pred] = students[pos];
                if(pred == HEAD) {
                    pos = next;
                } else {
                    pos = pred;
                }        
            }
            break;
            case 'H': {
                const auto [next, pred] = students[pos];
                if(next == HEAD) {
                    pos = pred;
                } else {
                    pos = next;
                }
            }
            break;
            case 'I': {
                auto pos_next = students[pos].next;
                if(pos_next == HEAD) {
                    pos_next = students[HEAD].next;
                }
                auto [next, pred] = students[pos];
                students[next].pred = pred;
                students[pred].next = next;
                students[pos] = { HEAD, students[HEAD].pred};
                students[students[HEAD].pred].next = pos;
                students[HEAD].pred = pos;
                pos = pos_next;
            }
            break;
            case 'J': {
                auto pos_next = students[pos].next;
                if(pos_next == HEAD) {
                    pos_next = students[HEAD].next;
                }
                auto [next, pred] = students[pos];
                students[next].pred = pred;
                students[pred].next = next;
                auto frind = pos % 2 == 0 ? pos - 1 : pos + 1;
                students[pos] = { students[frind].next, frind};
                students[students[frind].next].pred = pos;
                students[frind].next = pos;
                pos = pos_next;
            }
            break;
            case 'K': {
                auto frind = pos % 2 == 0 ? pos - 1 : pos + 1;
                cout << names[frind] << "\n";
            }
            break;
            default: assert(false);
        }
    }
    pos = students[HEAD].next;
    while(pos != HEAD) {
        cout << names[pos] << "\n";
        pos = students[pos].next;
    }
}