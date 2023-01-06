from typing import List, Optional
from collections import deque
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

def helper(root: Optional[TreeNode]) -> int:
    if root:
        root.left, root.right = root.right,root.left
        helper(root.left)
        helper(root.right)

def invertTree(root: Optional[TreeNode]) -> TreeNode:
    helper(root)
    return root

root1 =  TreeNode(4,  TreeNode(2,  TreeNode(1),  TreeNode(3)),  TreeNode(7,  TreeNode(6),  TreeNode(9)))
root2 =  TreeNode(2,  TreeNode(1),  TreeNode(3))
root3 =  TreeNode()

ans1 = invertTree(root1)
ans2 = invertTree(root2)
ans3 = invertTree(root3)
print("My answer for invertTree(root1) = ",ans1.print()," and the right answer is [4,7,2,9,6,3,1]")
print("My answer for invertTree(root2) = ",ans2.print()," and the right answer is [2,3,1]")
print("My answer for invertTree(root3) = ",ans3.print()," and the right answer is []")