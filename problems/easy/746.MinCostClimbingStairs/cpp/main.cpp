#include <vector>
#include <iostream>
/*
    Problem statement:
    You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
    You can either start from the step with index 0, or the step with index 1.
    Return the minimum cost to reach the top of the floor.
*/
using namespace std;

int minCostClimbingStairs(vector<int> cost) {
    if(cost.size()==1) return cost.back();
    if(cost.size()==2) return min(cost.front(), cost.back());
    int minC1 = cost[0];
    int minC2 = cost[1];
    int ret;
    for(int i = 2; i<cost.size();i++){
        ret = cost[i]+ min(minC1, minC2);
        minC1 = minC2;
        minC2=ret;
    }
    return min(minC1,minC2);
}

int main(){
    vector<int> in1 = {10,15,20};
    vector<int> in2 = {1,100,1,1,1,100,1,1,100,1};

    cout << "My answer for minCostClimbingStairs(in1) = "<<minCostClimbingStairs(in1) << " and the right answer is 15"<<endl;
    cout << "My answer for minCostClimbingStairs(in2) = "<<minCostClimbingStairs(in2) << " and the right answer is 6"<<endl;
    return 0;
}