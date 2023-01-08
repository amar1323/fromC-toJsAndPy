#include <iostream>
#include <vector>

/*
    Problem statement:
    A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.

    You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).

    Return the number of indices where heights[i] != expected[i].
*/
using namespace std;

int heightChecker(vector<int>& heights) {
    vector<int> expected(heights);
    sort(expected.begin(), expected.end());
    int ret = 0;
    for (int i = 0; i < heights.size(); i++) {
        if (heights[i] != expected[i]) ret++;
    }
    return ret;
}

int main() {
    vector<int> in1 = {1,1,4,2,1,3};
    vector<int> in2 = {5,1,2,3,4};
    vector<int> in3 = {1,2,3,4,5};
    cout << "My answer for heightChecker(in1) = " << heightChecker(in1) << " and the right answer is 3" << endl;
    cout << "My answer for heightChecker(in2) = " << heightChecker(in2) << " and the right answer is 5" << endl;
    cout << "My answer for heightChecker(in3) = " << heightChecker(in3) << " and the right answer is 0" << endl;

    return 0;
}