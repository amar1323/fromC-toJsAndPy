#include <bitset>
#include <string>
/*
    Problem statement:
    Reverse bits of a given 32 bits unsigned integer.
*/
using namespace std;

uint32_t reverseBits(uint32_t n) {
    string s = bitset<32>(n).to_string();
    uint32_t ret=0;
    uint32_t mult=1;
    for(int i=0; i<s.size();i++){
        if(s[i]=='1') ret+=mult;
        mult*=2;
    }
    return ret;
}

int main(){

    return 0;
}