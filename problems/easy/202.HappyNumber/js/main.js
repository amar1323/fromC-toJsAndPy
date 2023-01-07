/*
    Problem statement:
    Write an algorithm to determine if a number n is happy.

    A happy number is a number defined by the following process:

    Starting with any positive integer, replace the number by the sum of the squares of its digits.
    Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    Those numbers for which this process ends in 1 are happy.
    Return true if n is a happy number, and false if not.
*/

/**
 * @param {number} n
 * @return {boolean}
 */


function isHappy(n) {
  const save = new Set();
  while (true) {
    save.add(n);
    let happy = 0;
    do {
      let r = n % 10;
      happy += (r * r);
      n = Math.floor((n - r) / 10);
    } while (n > 0);
    if (happy === 1) return true;
    else if (save.has(happy)) break;
    n = happy;
  }
  return false;
}

console.log("My answer for isHappy(19) = ",isHappy(19), " and the right answer is true");
console.log("My answer for isHappy(2) = ",isHappy(2), " and the right answer is false");