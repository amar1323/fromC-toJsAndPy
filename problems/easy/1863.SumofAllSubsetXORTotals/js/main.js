/*
    Problem statement:
    The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

    For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
    Given an array nums, return the sum of all XOR totals for every subset of nums.

    Note: Subsets with the same elements should be counted multiple times.

    An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.
*/

let ret = 0;
/**
 * @param {number[]} nums
 * @param {number[]} sub
 * @param {number} idx
 */
function helper(nums, sub, idx) {
  if (sub.length > 0) {
    let toAdd = sub[0];
    for (let i = 1; i < sub.length; i++) {
      toAdd = (toAdd ^ sub[i]);
    }
    ret += toAdd;
  }
  for (let i = idx; i < nums.length; i++) {
    sub.push(nums[i]);
    helper(nums, sub, i + 1);
    sub.pop();
  }
}
/**
 * @param {number[]} nums
 * @return {number}
 */
function subsetXORSum(nums) {
  const sub = [];
  ret=0
  helper(nums, sub, 0);
  return ret;
}

const in1 = [1,3];
const in2 = [5,1,6];
const in3 = [3,4,5,6,7,8];
console.log("My answer for subsetXORSum(in1) = " , subsetXORSum(in1), " and the right answer is 6"  );
console.log("My answer for subsetXORSum(in2) = " , subsetXORSum(in2), " and the right answer is 28" );
console.log("My answer for subsetXORSum(in3) = " , subsetXORSum(in3), " and the right answer is 480");