/*
    Problem statement:
    Given the root of a binary tree, return all root-to-leaf paths in any order.
    A leaf is a node with no children.
*/


function TreeNode(val, left, right) {
  this.val = (val === undefined ? 0 : val)
  this.left = (left === undefined ? null : left)
  this.right = (right === undefined ? null : right)
}
/**
 * @param {TreeNode} root
 * @param {string} path
 * @param {string[]} ret
 */

var helper=function(root, path,ret){
  if(root != null){
    path+=root.val+"->";
    if(root.left ==null && root.right==null){
      ret.push(path.slice(0, path.length-2));
    }
    helper(root.left,path,ret);
    helper(root.right,path,ret);
  }
}


/**
 * @param {TreeNode} root
 * @return {string[]}
 */

var binaryTreePaths = function (root) {
  let ret = [];
  helper(root,"",ret);
  return ret;
};

const root1 =  new TreeNode(1,  new TreeNode(2, null,  new TreeNode(5)),  new TreeNode(3));
const root2 =  new TreeNode(1);

const ans1 = binaryTreePaths(root1);
const ans2 = binaryTreePaths(root2);


console.log( "My answer for binaryTreePaths(root1) = " ,  ans1  ," and the right answer is [\'1->2->5\',\'1->3\']");
console.log( "My answer for binaryTreePaths(root2) = " ,  ans2 , " and the right answer is [\'1\']");