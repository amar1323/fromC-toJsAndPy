/*
    Problem statement:
    A string can be abbreviated by replacing any number of non-adjacent, non-empty substrings with their lengths. The lengths should not have leading zeros.
    
    For example, a string such as "substitution" could be abbreviated as (but not limited to):
    
    "s10n" ("s ubstitutio n")
    "sub4u4" ("sub stit u tion")
    "12" ("substitution")
    "su3i1u2on" ("su bst i t u ti on")
    "substitution" (no substrings replaced)
    The following are not valid abbreviations:
    
    "s55n" ("s ubsti tutio n", the replaced substrings are adjacent)
    "s010n" (has leading zeros)
    "s0ubstitution" (replaces an empty substring)
    Given a string word and an abbreviation abbr, return whether the string matches the given abbreviation.
    
    A substring is a contiguous non-empty sequence of characters within a string.
*/

/**
 * @param {string} word
 * @param {string} abbr
 * @return {boolean}
 */

var validWordAbbreviation = function(word, abbr) {
  let i=0, j=0;
  for(i=0; i<abbr.length;i++){
    let go="";
    while( abbr[i]>='0' && abbr[i]<='9'){
      go+=abbr[i];
      i++;
    }
    if(go.length && go[0]=='0') return false;
    j+=(go.length==0) ? 0 : parseInt(go);
    if(j==word.length && i==abbr.length) return true;
    if(j>word.length) return false;
    if(word[j]!= abbr[i]) return false;
    j++;
  }
  return j==word.length && i==abbr.length;
};

let w1 = "internationalization"; 
let a1= "i12iz4n";
let w2 = "apple"; 
let a2 = "a2e";

console.log("My answer for validWordAbbreviation(w1,a1) = ", validWordAbbreviation(w1,a1), " and the right answer is true");
console.log("My answer for validWordAbbreviation(w2,a2) = ", validWordAbbreviation(w2,a1), " and the right answer is false");
