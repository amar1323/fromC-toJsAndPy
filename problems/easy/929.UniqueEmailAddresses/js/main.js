/*
    Problem statement:
    Every valid email consists of a local name and a domain name, separated by the '@' sign. Besides lowercase letters, the email may contain one or more '.' or '+'.

    For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.
    If you add periods '.' between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name. Note that this rule does not apply to domain names.

    For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
    If you add a plus '+' in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered. Note that this rule does not apply to domain names.

    For example, "m.y+name@email.com" will be forwarded to "my@email.com".
    It is possible to use both of these rules at the same time.

    Given an array of strings emails where we send one email to each emails[i], return the number of different addresses that actually receive mails.
*
*/
/**
@param {string[]}  emails
@return {number}  
*/
function numUniqueEmails(emails) {
  const s = new Set();
  for (let i = 0; i < emails.length; i++) {
    let toAdd = "";
    let j = 0;
    let ignore = false;
    let c;
    do {
      c = emails[i][j++];
      if (c === "+") ignore = true;
      if (!ignore && c !== "." && c !== "@") toAdd += c;
    } while (c !== "@");

    let domaine;
    if (c === "@") domaine = emails[i].substr(j - 1);
    else domaine = emails[i].substr(j);
    toAdd += domaine;
    s.add(toAdd);
  }
  return s.size;
}

const in1 = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"];
const in2 = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"];

console.log( "My answer for numUniqueEmails(in1) = " ,numUniqueEmails(in1) ," and the right answer is 2");
console.log( "My answer for numUniqueEmails(in2) = " ,numUniqueEmails(in2) ," and the right answer is 3");