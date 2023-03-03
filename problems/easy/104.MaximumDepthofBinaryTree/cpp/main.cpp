#include <algorithm>
/*
    Problem statement:
    Given the root of a binary tree, return its maximum depth.
    A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int helper(TreeNode* root, int depth){
    if(root){
        return std::max(helper(root->left, depth+1), helper(root->right, depth+1));
    }
    return depth;

}

int maxDepth(TreeNode* root) {
    return helper(root,0);
}