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
    print() {
        let ret = "[";
        if (this) {
          const q = [];
          q.push(this);
          while (q.length) {
            const curr = q.shift();
            ret += curr.val + ",";
            if (curr.left) q.push(curr.left);
            if (curr.right) q.push(curr.right);
          }
          ret = ret.slice(0, -1);
        }
        ret += "]";
        return ret;
    }
}
/**
 * @param {TreeNode} root
 */
function helper(root) {
    if (root) {
        [root.left, root.right] = [root.right, root.left];
        helper(root.left);
        helper(root.right);
    }
}
/**
 * @param {TreeNode} root
 * @return {TreeNode}
 */
function invertTree(root) {
    helper(root);
    return root;
}

const root1 = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
const root2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
const root3 = new TreeNode();

const ans1 = invertTree(root1);
const ans2 = invertTree(root2);
const ans3 = invertTree(root3);

console.log("My answer for invertTree(root1) = ",ans1.print()," and the right answer is [4,7,2,9,6,3,1]");
console.log("My answer for invertTree(root2) = ",ans2.print()," and the right answer is [2,3,1]");
console.log("My answer for invertTree(root3) = ",ans3.print()," and the right answer is []");