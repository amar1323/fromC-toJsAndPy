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

def isSameTree(p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
    if p and q and p.val == q.val:
        return isSameTree(p.left, q.left) * isSameTree(p.right, q.right)
    elif p is None and q is None:
        return True
    return False

root1p = TreeNode(1, TreeNode(2), TreeNode(3))
root1q = TreeNode(1, TreeNode(2), TreeNode(3))
root2p = TreeNode(2, TreeNode(1), None)
root2q = TreeNode(2, None, TreeNode(1))
root3p = TreeNode(1, TreeNode(5), TreeNode(2))
root3q = TreeNode(1, TreeNode(5), TreeNode(2))

print("My answer for invertTree(root1p,root1q) = " , bool(isSameTree(root1p, root1q)) , " and the right answer is True")
print("My answer for invertTree(root2p,root2q) = " , bool(isSameTree(root2p, root2q)) , " and the right answer is False")
print("My answer for invertTree(root3p,root3q) = " , bool(isSameTree(root3p, root3q)) , " and the right answer is True")