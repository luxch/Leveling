#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Error {
    int count;
    string name;
    int lineNum;
    int start;
};

typedef pair<string, Error> PAIR;

struct CmpByValue {
    bool operator()(const PAIR &lhs, const PAIR &rhs) {
        if (lhs.second.count == rhs.second.count) return lhs.second.start < rhs.second.start;
        return lhs.second.count > rhs.second.count;
    }
};

int main() {
    string path;
    int lineNum;
    unordered_map<string, Error> all;
    int start = 0;
    while (cin >> path >> lineNum) {
        auto index = path.rfind('\\');
        string name = index != string::npos ? path.substr(index + 1) : path;
        string id = name + to_string(lineNum);
        if (name.size() > 16) name = name.substr(name.size() - 16);
        auto it = all.find(id);
        if (all.end() != it) {
            it->second.count++;
        } else {
            all.insert({id, Error{1, name, lineNum, start++}});
        }
    }
    vector<PAIR> vec(all.begin(), all.end());
    sort(vec.begin(), vec.end(), CmpByValue());
    int i = 0;
    for (auto &entity : vec) {
        auto err = entity.second;
        cout << err.name << " " << err.lineNum << " " << err.count << endl;
        if (++i == 8) break;
    }
    return 0;
}
