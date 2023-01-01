/*
    Problem statement:
    You are climbing a staircase. It takes n steps to reach the top.
    Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

/**
 * @param {number} n
 * @return {number}
 */


var climbStairs = function(n) {
  if(n==2) return 2;
  if(n==1) return 1;
  let dp_0 = 1;
  let dp_1 = 2;
  let ret = 0;
  for(let i = 2; i<n;i++){
    ret = dp_0+ dp_1;
    dp_0 = dp_1;
    dp_1 = ret;
  }
  return ret;
};

console.log("My answer for climbStairs(2) = ",climbStairs(2), " and the right answer is 2");
console.log("My answer for climbStairs(3) = ",climbStairs(3), " and the right answer is 3");
console.log("My answer for climbStairs(5) = ",climbStairs(5), " and the right answer is 8");