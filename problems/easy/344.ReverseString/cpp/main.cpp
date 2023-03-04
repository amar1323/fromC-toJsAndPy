#include <vector>
/*
    Problem statement:
    Write a function that reverses a string. The input string is given as an array of characters s.
    You must do this by modifying the input array in-place with O(1) extra memory.
*/
using namespace std;

void reverseString(vector<char>& s) {
    s = vector<char>(s.rbegin(),s.rend());
}


int main(){

    return 0;
}
