#include <vector>
#include <string>
/*
    Problem statement:
    Given an integer n, return a string array answer (1-indexed) where:
        answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
        answer[i] == "Fizz" if i is divisible by 3.
        answer[i] == "Buzz" if i is divisible by 5.
        answer[i] == i (as a string) if none of the above conditions are true.
*/
using namespace std;

vector<string> fizzBuzz(int n) {
    vector<string> ret(n);
    for(int i=1; i<=n;i++){
        if(i%3==0 && i%5==0) ret[i-1]="FizzBuzz";
        else if(i%3==0) ret[i-1]="Fizz";
        else if(i%5==0) ret[i-1]="Buzz";
        else ret[i-1] = to_string(i);
    }
    return ret;
}

int main(){

    return 0;
}