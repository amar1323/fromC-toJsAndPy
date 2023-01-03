from typing import List
"""
    Problem statement:
    Given a string s, return true if the s can be palindrome after deleting at most one character from it.
"""
def checkPalindrome(s: str, m: int, n: int) ->bool:
    i=m
    j=n
    while i<j:
        if s[i]!= s[j]:
            return False
        i+=1
        j-=1
    return True


def validPalindrome(s: str) -> bool:
    i=0
    j=len(s)-1
    while i<j:
        if s[i]!=s[j]:
            return checkPalindrome(s,i+1,j) or checkPalindrome(s,i,j-1) 
        i+=1
        j-=1
    return True




print("My answer for validPalindrome(\"aba\") = " ,validPalindrome("aba"),     " and the right answer is True")
print("My answer for validPalindrome(\"abca\") = ", validPalindrome("abca") ,  " and the right answer is True")
print("My answer for validPalindrome(\"abc\") = " ,validPalindrome("abc"),     " and the right answer is False")
