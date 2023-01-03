/*
    Problem statement:
    Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
*/
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
  if (nums1.length < nums2.length) {
    [nums2, nums1] = [nums1, nums2];
  }
  // nums1.length >= nums2.length
  const ret = [];
  const s2 = new Set(nums2);
  for (const n1 of nums1) {
    if (s2.has(n1)) {
      ret.push(n1);
      s2.delete(n1);
    }
    if (s2.size === 0) {
      break;
    }
  }
  return ret;
}
let num11 = [1,2,2,1];
let num12 = [2,2];
let num21 = [4,9,5];
let num22 = [9,4,9,8,4];

console.log("My answer for intersection(num11,num12)= ", intersection(num11,num12),   " and the right answer is [2]");
console.log("My answer for intersection(num21,num22)= ", intersection(num21,num22) ,  " and the right answer is [9,4]");
