from typing import List, Optional
"""
    Problem statement:
    Given a binary tree, determine if it is height-balanced:
    A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

"""

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def helper(root: Optional[TreeNode]) -> int:
    if root:
        return max(1 + helper(root.left), 1 + helper(root.right))
    else:
        return 0

def isBalanced(root: Optional[TreeNode]) -> bool:
    if root:
        if abs(helper(root.left) - helper(root.right)) >= 2:
            return False
        return isBalanced(root.left) * isBalanced(root.right)
    return True

root1 = TreeNode(3,  TreeNode(9),  TreeNode(20,  TreeNode(15),  TreeNode(7)))
root2 = TreeNode(1,  TreeNode(2),  TreeNode(2,  TreeNode(3),  TreeNode(3,  TreeNode(4),  TreeNode(4,  TreeNode(5),  TreeNode(5)))))
root3 = TreeNode()

print( "My answer for isBalanced(root1) = " , isBalanced(root1)," and the right answer is True" )
print( "My answer for isBalanced(root2) = " , isBalanced(root2), " and the right answer is False")
print( "My answer for isBalanced(root3) = " , isBalanced(root3)," and the right answer is True" )