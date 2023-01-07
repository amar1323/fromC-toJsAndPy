from collections import Counter
from typing import List
"""
    Problem statement:
    Every valid email consists of a local name and a domain name, separated by the '@' sign. Besides lowercase letters, the email may contain one or more '.' or '+'.

    For example, in "alice@leetcode.com", "alice" is the local name, and "leetcode.com" is the domain name.
    If you add periods '.' between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name. Note that this rule does not apply to domain names.

    For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.
    If you add a plus '+' in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered. Note that this rule does not apply to domain names.

    For example, "m.y+name@email.com" will be forwarded to "my@email.com".
    It is possible to use both of these rules at the same time.

    Given an array of strings emails where we send one email to each emails[i], return the number of different addresses that actually receive mails.

"""

def numUniqueEmails(emails: List[str]) -> int:  
  s = set()
  for i in range(len(emails)):
    toAdd = ""
    j = 0
    ignore = False
    c = ""
    while c != "@":
      c = emails[i][j]
      j += 1
      if c == "+":
        ignore = True
      if not ignore and c != "." and c != "@":
        toAdd += c
    domaine = emails[i][j - 1:] if c == "@" else emails[i][j:]
    toAdd += domaine
    s.add(toAdd)
  return len(s)

in1 = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
in2 = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"]

print( "My answer for numUniqueEmails(in1) = " ,numUniqueEmails(in1) ," and the right answer is 2")
print( "My answer for numUniqueEmails(in2) = " ,numUniqueEmails(in2) ," and the right answer is 3")