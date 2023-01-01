#include <vector>
#include <iostream>
/*
    Problem statement:
    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/
using namespace std;

int climbStairs(int n) {
    if(n==2) return 2;
    if(n==1) return 1;
    int dp_0=1;
    int dp_1=2;
    int ret;
    for(int i = 2; i<n;i++){
        ret=dp_0+dp_1;
        dp_0 = dp_1;
        dp_1 = ret;
    }
    return ret;
}

int main(){
    int ans1 = climbStairs(2);
    int ans2 = climbStairs(3);
    int ans3 = climbStairs(5);

    cout << "My answer for climbStairs(2) = "<<ans1 << " and the right answer is 2"<<endl;
    cout << "My answer for climbStairs(3) = "<<ans2 << " and the right answer is 3"<<endl;
    cout << "My answer for climbStairs(5) = "<<ans3 << " and the right answer is 8"<<endl;
    return 0;
}