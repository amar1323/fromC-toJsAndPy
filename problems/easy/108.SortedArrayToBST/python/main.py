from collections import deque
from typing import Optional, List
"""
    Problem statement:
    Given a binary tree, determine if it is height-balanced:
    A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

"""


class TreeNode:
    def __init__(self, val=None, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

    def print(self):
        ret = "["
        if self:
            q = deque()
            q.append(self)
            while q:
                curr = q.popleft()
                ret += str(curr.val) + ","
                if curr.left: q.append(curr.left)
                if curr.right: q.append(curr.right)
            ret = ret[:-1]
        ret += "]"
        return ret

def helper(nums: List[int], s:int, e:int) -> Optional[TreeNode]:
    if s >= e:
        return None
    root = TreeNode(nums[(s + e) // 2])
    root.left = helper(nums, s, (s + e) // 2)
    root.right = helper(nums, (s + e) // 2 + 1, e)
    return root

def sortedArrayToBST(nums: List[int]) -> Optional[TreeNode]:
    return helper(nums, 0, len(nums))

in1 = [-10,-3,0,5,9]
in2 = [1,2]

ans1 = sortedArrayToBST(in1)
ans2 = sortedArrayToBST(in2)

print("My answer for invertTree(in1) = " , ans1.print(), " and the right answer is [0,-3,9,-10,5]" )
print("My answer for invertTree(in2) = " , ans2.print() , " and the right answer is [2,1]")