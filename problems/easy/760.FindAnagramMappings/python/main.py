from typing import List
"""
    Problem statement:
    You are given two integer arrays nums1 and nums2 where nums2 is an anagram of nums1. Both arrays may contain duplicates.

    Return an index mapping array mapping from nums1 to nums2 where mapping[i] = j means the ith element in nums1 appears in nums2 at index j. If there are multiple answers, return any of them.

    An array a is an anagram of an array b means b is made by randomizing the order of the elements in a.
"""


def anagramMappings(nums1:List[int], nums2:List[int])->List[int]:
    m1 = {}
    m2 = {}
    for i in range(len(nums1)):
        if nums1[i] not in m1:
            m1[nums1[i]] = [i]
        else:
            m1[nums1[i]].append(i)
        if nums2[i] not in m2:
            m2[nums2[i]] = [i]
        else:
            m2[nums2[i]].append(i)
    ret = [None] * len(nums1)
    for i in range(len(ret)):
        ret[m1[nums1[i]].pop()] = m2[nums1[i]].pop()
    return ret


num11 = [12,28,46,32,50]
num12 = [50,12,32,46,28]
num21 = [84,46]
num22 = [84,46]    
ans1 = anagramMappings(num11,num12)
ans2 = anagramMappings(num21,num22)


print("My answer for anagramMappings(num11,num12) = " , ans1, " and the right answer is [1,4,3,2,0]")
print("My answer for anagramMappings(num21,num22) = " , ans2, " and the right answer is [0,1]")
        

