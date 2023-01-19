from typing import List, Optional
from collections import deque
"""
    Problem statement:
    Given the root of a binary tree, return the inorder traversal of its nodes' values.
"""


class TreeNode:
    def __init__(self, val=None, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def helper(root: Optional[TreeNode], ret: Optional[TreeNode]):
    if root:
        helper(root.left, ret)
        ret.append(root.val)
        helper(root.right, ret)



def inorderTraversal(root: Optional[TreeNode]) -> List[int]:
    ret = []
    helper(root, ret)
    return ret

root1 =  TreeNode(1, None,  TreeNode(2,  TreeNode(3), None))
root2 =  TreeNode()
root3 =  TreeNode(1)

print( "My answer for inorderTraversal(root1) = " , inorderTraversal(root1)   , " and the right answer is [1,3,2]" )
print( "My answer for inorderTraversal(root2) = " , inorderTraversal(root2)   , " and the right answer is []" )
print( "My answer for inorderTraversal(root3) = " , inorderTraversal(root3)   , " and the right answer is [1]" )