#include <iostream>
/*
    Problem statement:
    he Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
*/
using namespace std;

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int f0 = 0;
    int f1 = 1;
    int ret;
    for (int i = 2; i <= n; i++) {
        ret = f0 + f1;
        f0 = f1;
        f1 = ret;
    }
    return ret;
}

int main() {
    int ans1 = fib(2);
    int ans2 = fib(3);
    int ans3 = fib(5);

    cout << "My answer for fib(2) = " << ans1 << " and the right answer is 1" << endl;
    cout << "My answer for fib(3) = " << ans2 << " and the right answer is 2" << endl;
    cout << "My answer for fib(4) = " << ans3 << " and the right answer is 3" << endl;
    return 0;
}