#include <cmath>

/*
    Problem statement:
    Given an integer n, return true if it is a power of three. Otherwise, return false.
    An integer n is a power of three, if there exists an integer x such that n == 3x.
*/

//Solution without recursion nor loops
bool isPowerOfThree(int n) {
    if (n < 1) return false;
    double x = log(n)/log(3);
    return (x - floor(x+1.e-12))<1.e-12;
}
//Solution with loop, can be easly written in recursion
bool isPowerOfThree1(int n) {
    if (n < 1) return false;
    while (n % 3 == 0) n /= 3;
    return n == 1;
}

int main(){


    return 0;
}