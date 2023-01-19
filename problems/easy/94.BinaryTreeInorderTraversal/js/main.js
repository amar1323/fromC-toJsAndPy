/*
    Problem statement:
    Given the root of a binary tree, return the inorder traversal of its nodes' values.

*
*/

class TreeNode {
    constructor(val, left, right) {
      this.val = val;
      this.left = left;
      this.right = right;
    }
}
/**
 * @param {TreeNode} root
 * @param {number[]} ret
 */

function helper(root, ret) {
  if (root) {
      helper(root.left, ret);
      ret.push(root.val);
      helper(root.right, ret);
  }
}
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
function inorderTraversal(root) {
  let ret = [];
  helper(root, ret);
  return ret;
}

const root1 = new TreeNode(1, null, new TreeNode(2, new TreeNode(3), null));
const root2 = new TreeNode();
const root3 = new TreeNode(1);

console.log( "My answer for inorderTraversal(root1) = " , inorderTraversal(root1)   , " and the right answer is [1,3,2]" );
console.log( "My answer for inorderTraversal(root2) = " , inorderTraversal(root2)   , " and the right answer is []" );
console.log( "My answer for inorderTraversal(root3) = " , inorderTraversal(root3)   , " and the right answer is [1]" );