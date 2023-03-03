#include <bitset>
#include <string>
/*
    Problem statement:
    The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
    Given two integers x and y, return the Hamming distance between them.
*/

using namespace std;

int hammingDistance(int x, int y) {
    string sX = bitset<32>(x).to_string();
    string sY = bitset<32>(y).to_string();
    int ret = 0;
    for(int i = 0; i<sX.size();i++)
        ret+=(sX[i]!=sY[i]) ? 1:0;
    return ret;
}

int main(){

    return 0;
}