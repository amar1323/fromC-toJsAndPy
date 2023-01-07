/*
    Problem statement:
    Given the head of a singly linked list, return true if it is a palindrome or false otherwise.*
*/

function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}
 
let caller;
/**
 * @param {ListNode} current
 * @return {boolean}
 */

function helper(current) {
  if (current) {
    if (!helper(current.next)) return false;
    if (current.val !== caller.val) return false;
    caller = caller.next;
  }
  return true;
}

function isPalindrome(current) {
  caller = current;
  return helper(current);
}

const in1 = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
const in2 = new ListNode(1, new ListNode(2));

console.log("My answer for isPalindrome(in1) = " , isPalindrome(in1),  " and the right answer is true");
console.log("My answer for isPalindrome(in2) = " , isPalindrome(in2),  " and the right answer is false");