from typing import List
"""
    Problem statement:
    You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
    You can either start from the step with index 0, or the step with index 1.
    Return the minimum cost to reach the top of the floor.
"""

def minCostClimbingStairs(cost: List[int]) -> int:
    if len(cost)==1: return cost[0]
    elif len(cost)==2: return min(cost[0],cost[1])
    minC1 = cost[0]
    minC2 = cost[1]
    for i in range(2,len(cost)):
        ret = cost[i]+min(minC1, minC2)
        minC1 = minC2
        minC2 = ret
    return min(minC1,minC2)

in1 = [10,15,20]
in2 = [1,100,1,1,1,100,1,1,100,1]

print("My answer for minCostClimbingStairs(in1) = ", minCostClimbingStairs(in1),  " and the right answer is 15")
print("My answer for minCostClimbingStairs(in2) = ", minCostClimbingStairs(in2),  " and the right answer is 6")
        

