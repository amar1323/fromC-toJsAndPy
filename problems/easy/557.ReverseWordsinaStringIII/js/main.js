/*
    Problem statement:
    Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order
*/
/**
 * @param {string} s
 * @param {int} i
 * @param {int} j
 * @return {string} k
 */

var reverseWord = function(s,i,j){
  let k ="";
  for(var idx = j-1; idx>=i;idx--)
    k+=s[idx];
  return k;
}
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
  let j =0;
  let k="";
  for(let i=0; i<s.length;i++){
    if(s[i]==' '){
      k+=reverseWord(s,j,i);
      k+=' ';
      j = i+1;
    }
  }
  if(j<s.length) k+=reverseWord(s,j,s.length);
  return k;
};

let in1 ="Let's take LeetCode contest";
let in2 ="God Ding";

console.log( "My answer for reverseWords(in1) = ", reverseWords(in1), " and the right answer is s'teL ekat edoCteeL tsetnoc");
console.log( "My answer for reverseWords(in2) = ", reverseWords(in2), " and the right answer is doG gniD");
