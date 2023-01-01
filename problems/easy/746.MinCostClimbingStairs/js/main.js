/*
    Problem statement:
    You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.
    You can either start from the step with index 0, or the step with index 1.
    Return the minimum cost to reach the top of the floor.
*/

/**
 * @param {number[]} cost
 * @return {number}
 */
var minCostClimbingStairs = function(cost) {
    if(cost.length==1) return cost[0];
    if(cost.length==2) return Math.min(cost[0],cost[1]);
    let minC1 = cost[0];
    let minC2 = cost[1];
    let ret = 0;
    for(let i =2; i<cost.length;i++){
      ret = cost[i]+Math.min(minC1, minC2);
      minC1 = minC2;
      minC2 = ret;
    }
    return Math.min(minC1,minC2);
};

let in1 = [10,15,20];
let in2 = [1,100,1,1,1,100,1,1,100,1];

console.log("My answer for minCostClimbingStairs(in1) = ",minCostClimbingStairs(in1), " and the right answer is 15");
console.log("My answer for minCostClimbingStairs(in2) = ",minCostClimbingStairs(in2), " and the right answer is 6");
