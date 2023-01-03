from typing import List
"""
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
"""

def validWordAbbreviation(word: str, abbr: str) -> bool:
    i = 0
    j = 0
    while i < len(abbr):
        go =""
        while i<len(abbr) and abbr[i].isnumeric():
            go+=abbr[i]
            i+=1
        if go!="" and go[0]=='0': return False
        elif go!="": j += int(go)
        if j==len(word) and i==len(abbr): return True
        if j > len(word): return False
        if j < len(word)and i<len(abbr) and word[j] != abbr[i]: return False
        j+=1
        i+=1
    return i == len(abbr) and j== len(word)



w1 = "internationalization"
a1= "i12iz4n"
w2 = "apple" 
a2 = "a2e"

print("My answer for validWordAbbreviation(w1,a1) = ", validWordAbbreviation(w1,a1), " and the right answer is True")
print("My answer for validWordAbbreviation(w2,a2) = ", validWordAbbreviation(w2,a1), " and the right answer is False")
        

