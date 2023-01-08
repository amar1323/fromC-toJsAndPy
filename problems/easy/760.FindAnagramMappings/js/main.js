/*
    Problem statement:
    You are given two integer arrays nums1 and nums2 where nums2 is an anagram of nums1. Both arrays may contain duplicates.

    Return an index mapping array mapping from nums1 to nums2 where mapping[i] = j means the ith element in nums1 appears in nums2 at index j. If there are multiple answers, return any of them.

    An array a is an anagram of an array b means b is made by randomizing the order of the elements in a.
*/

/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]} 
 */


function anagramMappings(nums1, nums2) {
  const m1 = new Map();
  const m2 = new Map();
  for (let i = 0; i < nums1.length; i++) {
      if (!m1.has(nums1[i])) {
          m1.set(nums1[i], [i]);
      } else {
          m1.get(nums1[i]).push(i);
      }
      if (!m2.has(nums2[i])) {
          m2.set(nums2[i], [i]);
      } else {
          m2.get(nums2[i]).push(i);
      }
  }
  const ret = new Array(nums1.length);
  for (let i = 0; i < ret.length; i++) {
      ret[m1.get(nums1[i]).pop()] = m2.get(nums1[i]).pop();
  }
  return ret;
}

const num11 = [12,28,46,32,50];
const num12 = [50,12,32,46,28];
const num21 = [84,46];
const num22 = [84,46];    
const ans1 = anagramMappings(num11,num12);
const ans2 = anagramMappings(num21,num22);


console.log("My answer for anagramMappings(num11,num12) = " , ans1, " and the right answer is [1,4,3,2,0]");
console.log("My answer for anagramMappings(num21,num22) = " , ans2, " and the right answer is [0,1]");