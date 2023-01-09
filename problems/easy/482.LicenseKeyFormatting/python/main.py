"""
    Problem statement:
    You are given a license key represented as a string s that consists of only alphanumeric characters and dashes. The string is separated into n + 1 groups by n dashes. You are also given an integer k.

    We want to reformat the string s such that each group contains exactly k characters, except for the first group, which could be shorter than k but still must contain at least one character. Furthermore, there must be a dash inserted between two groups, and you should convert all lowercase letters to uppercase.

    Return the reformatted license key.

"""

def licenseKeyFormatting(s: str, k: int) -> str:
    ret = ""
    l = 0
    for i in range(len(s) - 1, -1, -1):
        if s[i] == "-":
            continue
        l += 1
        
        ret += s[i].upper()
        if l == k:
            l = 0
            ret += "-"
    if len(ret)>0 and ret[-1] == "-":
        ret = ret[:-1]
    return ret[::-1]

in1 = "5F3Z-2e-9-w"
in2 = "2-5g-3-J"

print("My answer for licenseKeyFormatting(in1,4) = " , licenseKeyFormatting(in1,4) , " and the right answer is 5F3Z-2E9W" )
print("My answer for licenseKeyFormatting(in2,2) = " , licenseKeyFormatting(in2,2) , " and the right answer is 2-5G-3J" )