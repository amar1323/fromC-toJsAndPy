/*
    Problem statement:
    Given a binary tree, determine if it is height-balanced:
    A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
*
*/
function TreeNode(val, left, right) {
    this.val = (val===undefined ? 0 : val)
    this.left = (left===undefined ? null : left)
    this.right = (right===undefined ? null : right)
}
/**
 * @param {TreeNode} root
 * @return {int}
 */
function helper(root) {
    if (root) {
        return Math.max(1 + helper(root.left), 1 + helper(root.right));
    } else {
        return 0;
    }
}
/**
 * @param {TreeNode} root
 * @return {boolean}
 */

function isBalanced(root) {
    if (root) {
        if (Math.abs(helper(root.left) - helper(root.right)) >= 2) {
            return false;
        }
        return isBalanced(root.left) && isBalanced(root.right);
    }
    return true;
}

let root1 = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
let root2 = new TreeNode(1, new TreeNode(2), new TreeNode(2, new TreeNode(3), new TreeNode(3, new TreeNode(4), new TreeNode(4, new TreeNode(5), new TreeNode(5)))));
let root3= new TreeNode();

console.log( "My answer for isBalanced(root1) = " , isBalanced(root1)," and the right answer is true" );
console.log( "My answer for isBalanced(root2) = " , isBalanced(root2), " and the right answer is false");
console.log( "My answer for isBalanced(root3) = " , isBalanced(root3)," and the right answer is true" );