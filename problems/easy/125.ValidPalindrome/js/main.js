/*
    Problem statement:
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
    Given a string s, return true if it is a palindrome, or false otherwise.
*/

function isAlphaNumeric(code) {
  if (!(code > 47 && code < 58) && // numeric (0-9)
    !(code > 64 && code < 91) && // upper alpha (A-Z)
    !(code > 96 && code < 123)) { // lower alpha (a-z)
    return false;
  }
  return true;
};

/**
 * @param {string} s
 * @return {boolean}
 */

var isPalindrome = function (s) {
  for (let i = 0, j = s.length - 1; i < j; i++, j--) {
    while (!isAlphaNumeric(s.charCodeAt(i)) && i<j) i++;
    while (!isAlphaNumeric(s.charCodeAt(i)) && i<j) j--;
    if (s[i].toLocaleLowerCase() != s[j].toLocaleLowerCase())
      return false;
  }
  return true;
};

let in1 = "A man, a plan, a canal: Panama";
let in2 = "race a car";
let in3 = " ";
console.log("My answer for isPalindrome(in1) = ", isPalindrome(in1), " and the right answer is true");
console.log("My answer for isPalindrome(in2) = ", isPalindrome(in2), " and the right answer is false");
console.log("My answer for isPalindrome(in3) = ", isPalindrome(in3), " and the right answer is true");