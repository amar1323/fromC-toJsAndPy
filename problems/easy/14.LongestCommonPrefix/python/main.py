from typing import List

"""
    Problem statement:
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".
"""

def longestCommonPrefix(strs: List[str]) -> str:
    if len(strs) == 0: return ""
    elif len(strs) == 1: return strs[0]
    ret =""
    for i in range(len(strs[0])):
        c = strs[0][i]
        for j in range(1,len(strs)):
            if i>= len(strs[j]) or c != strs[j][i]:
                return ret
        ret+=c
    return ret

in1 = ["flower","flow","flight"]
in2 = ["dog","racecar","car"]

print("My answer for longestCommonPrefix(in1)= ", longestCommonPrefix(in1), " and real answer is: fl")
print("My answer for longestCommonPrefix(in2)= ", longestCommonPrefix(in2), " and real answer is:")