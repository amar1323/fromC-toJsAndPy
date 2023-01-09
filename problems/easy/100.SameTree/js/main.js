/*
    Problem statement:
    Given a binary tree, determine if it is height-balanced:
    A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
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
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
function isSameTree(p, q) {
  if (p && q && p.val === q.val) {
      return isSameTree(p.left, q.left) * isSameTree(p.right, q.right);
  } else if (p === null && q === null) {
      return true;
  }
  return false;
}

const root1p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
const root1q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
const root2p = new TreeNode(2, new TreeNode(1), null);
const root2q = new TreeNode(2, null, new TreeNode(1));
const root3p = new TreeNode(1, new TreeNode(5), new TreeNode(2));
const root3q = new TreeNode(1, new TreeNode(5), new TreeNode(2));

console.log("My answer for invertTree(root1p,root1q) = " , isSameTree(root1p, root1q) , " and the right answer is true");
console.log("My answer for invertTree(root2p,root2q) = " , isSameTree(root2p, root2q) , " and the right answer is false");
console.log("My answer for invertTree(root3p,root3q) = " , isSameTree(root3p, root3q) , " and the right answer is true");
