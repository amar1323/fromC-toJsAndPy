from typing import List
"""
    Problem statement:
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
    Given a string s, return true if it is a palindrome, or false otherwise.
"""

def isPalindrome(s):
    i=0
    j=len(s)-1
    while i<j:
        while  s[i].isalnum()==False and i<j:i+=1
        while  s[j].isalnum()==False and i<j:j-=1
        if s[i].lower()!=s[j].lower(): return False
        i+=1
        j-=1
    return True


in1 = "A man, a plan, a canal: Panama"
in2 = "race a car"
in3 = " "
print("My answer for isPalindrome(in1) = ", isPalindrome(in1), " and the right answer is True")
print("My answer for isPalindrome(in2) = ", isPalindrome(in2), " and the right answer is True")
print("My answer for isPalindrome(in3) = ", isPalindrome(in3), " and the right answer is True")
