/*
    Problem statement:
    he Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
*/

/**
 * @param {number} n
 * @return {number}
 */

var fib = function(n) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  let f0 = 0;
  let f1 = 1;
  let ret=0;
  for (let i = 2; i <= n; i++) {
      ret = f0 + f1;
      f0 = f1;
      f1 = ret;
  }
  return ret;
};

console.log("My answer for fib(2) = ",fib(2), " and the right answer is 1");
console.log("My answer for fib(3) = ",fib(3), " and the right answer is 2");
console.log("My answer for fib(4) = ",fib(4), " and the right answer is 3");