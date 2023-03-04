#include <vector>

using namespace std;
/*
    Problem statement:
    Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
    You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

int singleNumber(vector<int>& nums) {
    int a = 0;
    for (int i : nums) {
        a ^= i;
    }
    return a;
}

int main(){

    return 0;
}