#include <iostream>
#include <unordered_set>
/*
    Problem statement:
    Write an algorithm to determine if a number n is happy.

    A happy number is a number defined by the following process:

    Starting with any positive integer, replace the number by the sum of the squares of its digits.
    Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    Those numbers for which this process ends in 1 are happy.
    Return true if n is a happy number, and false if not.
*/
using namespace std;

bool isHappy(int n) {
    unordered_set<int> save;
    while (true) {
        save.insert(n);
        int happy = 0;
        do {
            int r = n % 10;
            happy += (r * r);
            n = (n - r) / 10;
        } while (n > 0);
        if (happy == 1)
            return true;
        else if (save.find(happy) != save.end())
            break;
        n = happy;
    }
    return false;
}

int main() {
    cout << "My answer for isHappy(19) = " << isHappy(19) << " and the right answer is 1" << endl;
    cout << "My answer for isHappy(2) = " << isHappy(2) << " and the right answer is 0" << endl;

    return 0;
}