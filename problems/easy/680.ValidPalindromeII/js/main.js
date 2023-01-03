/*
    Problem statement:
    Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*/
/**
 * @param {string} s
 * @param {int} i
 * @param {int} j
 * @return {boolean}
 */
var checkPalindrome=function(s,m,n){
  for(let i=m, j=n; i<j;i++,j--){
    if(s[i]!=s[j]) return false;
  }
  return true;
}

/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function(s) {
    for(let i=0, j=s.length-1; i<j;i++,j--){
      if(s[i]!=s[j]){
        return checkPalindrome(s,i+1,j) || checkPalindrome(s,i,j-1);
      }
    }
    return true;
};


console.log("My answer for validWordAbbreviation(\"aba\") = " ,validPalindrome("aba"),     " and the right answer is true");
console.log("My answer for validWordAbbreviation(\"abca\") = ", validPalindrome("abca") ,  " and the right answer is true");
console.log("My answer for validWordAbbreviation(\"abc\") = " ,validPalindrome("abc"),     " and the right answer is false");
