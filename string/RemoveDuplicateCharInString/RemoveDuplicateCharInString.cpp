#include <iostream>
#include <set>

using namespace std;

int main() {
    string str;
    /*
    set<int> ss;
    while (cin >> str) {
        for (auto& c : str) {
            if (ss.end() == ss.find(c-'0'))
            {
                ss.insert(c-'0');
                cout << c;
            }
        }
        cout << endl;
    }
*/
    int array[256] = {0};
    while (cin >> str) {
        for (auto& c : str) {
            if (array[c] == 0)
            {
                array[c]++;
                cout << c;
            }
        }
        cout << endl;
    }
    return 0;
}

