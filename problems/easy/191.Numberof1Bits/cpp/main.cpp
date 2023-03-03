#include <bitset>
#include <string>
/*
    Problem statement:
    Number of ones in a binary representation of n
*/
using namespace std;

int hammingWeight(uint32_t n) {
    string s = bitset<32>(n).to_string();
    int ret=0;
    for(auto c : s) ret+=(c=='1')?1:0;
    return ret;
}

int main(){


    return 0;
}