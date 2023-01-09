/*
    Problem statement:
    You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.

    We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.

    Return the reformatted license key.
*
*/

/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
function licenseKeyFormatting(s, k) {
  let ret = "";
  let l = 0;
  for (let i = s.length - 1; i >= 0; i--) {
      if (s[i] === "-") continue;
      l++;
      
      ret += s[i].toUpperCase();
      if (l === k) {
          l = 0;
          ret += "-";
      }
  }
  if (ret.slice(-1) === "-") ret = ret.slice(0, -1);
  return ret.split("").reverse().join("");
}

const in1 = "5F3Z-2e-9-w";
const in2 = "2-5g-3-J";

console.log("My answer for licenseKeyFormatting(in1,4) = " , licenseKeyFormatting(in1,4) , " and the right answer is 5F3Z-2E9W" );
console.log("My answer for licenseKeyFormatting(in2,2) = " , licenseKeyFormatting(in2,2) , " and the right answer is 2-5G-3J" );