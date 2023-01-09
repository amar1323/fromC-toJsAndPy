/*
    Problem statement:
    Given an integer array nums where the elements are sorted in ascending order, convert it to a 
    height-balanced binary search tree.
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
 * @param {number[]} nums
 * @return {TreeNode}
 */
function helper(nums, s, e) {
  if (s >= e) return null;
  let root = new TreeNode(nums[Math.floor((s + e) / 2)]);
  root.left = helper(nums, s, Math.floor((s + e) / 2));
  root.right = helper(nums, Math.floor((s + e) / 2) + 1, e);
  return root;
}

function sortedArrayToBST(nums) {
  return helper(nums, 0, nums.length);
}

const in1 = [-10,-3,0,5,9];
const in2 = [1,2];

const ans1 = sortedArrayToBST(in1);
const ans2 = sortedArrayToBST(in2);

console.log("My answer for invertTree(in1) = " , ans1.print(), " and the right answer is [0,-3,9,-10,5]" );
console.log("My answer for invertTree(in2) = " , ans2.print() , " and the right answer is [2,1]");