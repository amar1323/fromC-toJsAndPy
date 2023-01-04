from typing import List,Optional
"""
    Problem statement:
    Given the root of a binary tree, return all root-to-leaf paths in any order.
    A leaf is a node with no children.
"""
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def helper(root: Optional[TreeNode], path: str, ret: List[str]):
  if root != None:
    path+=(str(root.val)+"->")
    if root.left ==None and root.right==None:
      ret.append(path[:len(path)-2])
    helper(root.left, path,ret)
    helper(root.right, path,ret)


def binaryTreePaths(root: Optional[TreeNode]) -> List[str]:
  ret=[]
  helper(root,"",ret)
  return ret


root1 =   TreeNode(1,   TreeNode(2, None,   TreeNode(5)),   TreeNode(3))
root2 =   TreeNode(1)

ans1 = binaryTreePaths(root1)
ans2 = binaryTreePaths(root2)


print( "My answer for binaryTreePaths(root1) = " ,  ans1  ," and the right answer is [\'1->2->5\',\'1->3\']")
print( "My answer for binaryTreePaths(root2) = " ,  ans2 , " and the right answer is [\'1\']")
        

