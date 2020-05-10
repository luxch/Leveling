#include <iostream>
using namespace std;

int main() {
    int N = 0, M = 0;
    while (cin >> N >> M)
    {
        int grades[N];
        for (int i = 0; i < N; ++i)
        {
            cin >> grades[i];
        }
        char c;
        int A, B;
        while (M-- > 0 && cin >> c >> A >> B) {
            if ('Q' == c){
                if (A > B) swap(A, B);
                int max = grades[A-1];
                for (int i = A; i < B; ++i) {
                    if (max < grades[i])
                    {
                        max = grades[i];
                    }
                }
                cout << max << endl;
            }
            else if ('U' == c)
            {
                grades[A-1] = B;
            }
        }
    }
    return 0;
}
