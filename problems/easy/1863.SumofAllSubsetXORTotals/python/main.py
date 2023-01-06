from typing import List
"""
    Problem statement:
    The XOR total of an array is defined as the bitwise XOR of all its elements, or 0 if the array is empty.

    For example, the XOR total of the array [2,5,6] is 2 XOR 5 XOR 6 = 1.
    Given an array nums, return the sum of all XOR totals for every subset of nums.

    Note: Subsets with the same elements should be counted multiple times.

    An array a is a subset of an array b if a can be obtained from b by deleting some (possibly zero) elements of b.
"""

def helper(nums:List[int], sub:List[int], idx:int, ret:List[int]):
    if sub:
        to_add = sub[0]
        for i in range(1, len(sub)):
            to_add = (to_add ^ sub[i])
        ret[0] += to_add
    for i in range(idx, len(nums)):
        sub.append(nums[i])
        helper(nums, sub, i + 1, ret)
        sub.pop()

def subsetXORSum(nums: List[int])->int:
    ret = [0]
    helper(nums, [], 0, ret)
    return ret[0]

in1 = [1,3]
in2 = [5,1,6]
in3 = [3,4,5,6,7,8]

print("My answer for subsetXORSum(in1) = " , subsetXORSum(in1), " and the right answer is 6"  )
print("My answer for subsetXORSum(in2) = " , subsetXORSum(in2), " and the right answer is 28" )
print("My answer for subsetXORSum(in3) = " , subsetXORSum(in3), " and the right answer is 480")
