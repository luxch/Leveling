// C++ program to counts the number of 'k' digits between 0 and n
#include <iostream>
#include <random>

using std::default_random_engine;
using namespace std;
using ULONGLONG = unsigned long long;

ULONGLONG calculateOneByOne(ULONGLONG number, int k) {
    ULONGLONG sum = 0;
    for (ULONGLONG i = 0; i <= number; i++) {
        ULONGLONG count = 0;
        ULONGLONG n = i;
        do {
            if ((n % 10) == k) count++;
            n /= 10;
        } while (n != 0);
        sum += count;
    }
    return sum;
}

ULONGLONG numberOfOneDigitInRange(ULONGLONG number, int k) {
    // Traverse every digit and count for every digit
    ULONGLONG count = 0;
    ULONGLONG factor = 1;
    ULONGLONG lowerNum = 0;
    ULONGLONG currDigit = 0;
    ULONGLONG higherNum = 0;
    while (number / factor != 0) {
        /*
         * For example: "abcde"
         * current digit is 'c'
         * lower number is "de"
         * higher number is "ab"
         */
        lowerNum = number - (number / factor) * factor;
        currDigit = (number / factor) % 10;
        higherNum = number / (factor * 10);

        if (currDigit < k) {
            count += higherNum * factor;
        } else if (currDigit == k) {
            count += higherNum * factor + lowerNum + 1;
        } else {
            count += (higherNum + 1) * factor;
        }
        factor *= 10;
    }
    if (k == 0) {
        factor = 10;
        while (number / factor != 0) {
            count -= factor;
            factor *= 10;
        }
    }
    return count;
}

int main() {
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, 10000000);
    for (size_t i = 0; i < 10; ++i)
    {
        ULONGLONG number = u(e);
        cout << number << " : ";
        cout << calculateOneByOne(number, i) << " <==> ";
        cout << numberOfOneDigitInRange(number, i) << endl;
    }
    return 0;
}

