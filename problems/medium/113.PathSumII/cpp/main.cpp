#include <vector>
/*
    Problem statement
    Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.
    A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
*/
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void helper(TreeNode* root, int targetSum, vector<int>& sub, vector<vector<int>>& ret){
    if(root){
        sub.push_back(root->val);
        if(root->val== targetSum &&root->left==nullptr && root->right==nullptr){
            ret.push_back(sub);
            sub.pop_back();
            return;
        }
        helper(root->left, targetSum-root->val, sub, ret);
        helper(root->right, targetSum-root->val, sub, ret);
        sub.pop_back();
    }
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<int> sub;
    vector<vector<int>> ret;
    helper(root, targetSum, sub, ret);
    return ret;
}

int main(){


    return 0;
}