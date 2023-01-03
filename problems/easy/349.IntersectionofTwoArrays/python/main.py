from typing import List
"""
    Problem statement:
    Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
"""
def intersection(nums1: List[int], nums2: List[int]) -> List[int]:
    if len(nums1) < len(nums2):
        nums1, nums2 = nums2, nums1
    # len(nums1) >= len(nums2)
    ret = []
    s2 = set(nums2)
    for n1 in nums1:
        if n1 in s2:
            ret.append(n1)
            s2.remove(n1)
        if not s2:
            break
    return ret


num11 = [1,2,2,1]
num12 = [2,2]
num21 = [4,9,5]
num22 = [9,4,9,8,4]

print("My answer for intersection(num11,num12)= ", intersection(num11,num12),   " and the right answer is [2]")
print("My answer for intersection(num21,num22)= ", intersection(num21,num22) ,  " and the right answer is [9,4]")
