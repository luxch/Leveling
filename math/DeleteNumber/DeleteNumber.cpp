#include <iostream>

using namespace std;

struct Point {
    int index;
    Point *next;
};

int main() {
    int N = 0;
    while (cin >> N) {
        Point *head = new Point{0, nullptr};
        Point *pre = head;
        for (int i = 1; i < N; ++i)
        {
            auto* next = new Point{i, nullptr};
            pre->next = next;
            pre = pre->next;
        }
        pre->next = head;
        while (head->next->index != head->index)
        {
            Point* next = head->next;
            Point* next2 = head->next->next;
            next->next = next2->next;
            delete next2;
            next2 = nullptr;
            head = next->next;
        }
        cout << head->index << endl;
        delete head;
        head = nullptr;
    }
    return 0;
}
