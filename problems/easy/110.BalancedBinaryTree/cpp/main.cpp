#include <iostream>
/*
    Problem statement:
    Given a binary tree, determine if it is height-balanced:
    A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.
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

int helper(TreeNode* root){
    if(root)
        return max(1+helper(root->left), 1+helper(root->right));
    else 
        return 0;
}

bool isBalanced(TreeNode* root) {
    if(root){
        if( abs(helper(root->left)-helper(root->right))>=2) return false;
        return isBalanced(root->left)*isBalanced(root->right);
    }
    return true;
}

int main() {
    TreeNode* root1 = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    TreeNode* root2 = new TreeNode(1, new TreeNode(2), new TreeNode(2, new TreeNode(3), new TreeNode(3, new TreeNode(4), new TreeNode(4, new TreeNode(5), new TreeNode(5)))));
    TreeNode* root3=nullptr;

    cout << "My answer for isBalanced(root1) = " << isBalanced(root1)<< " and the right answer is 1" << endl;
    cout << "My answer for isBalanced(root2) = " << isBalanced(root2) << " and the right answer is 0" << endl;
    cout << "My answer for isBalanced(root3) = " << isBalanced(root3)<< " and the right answer is 1" << endl;  
    return 0;
}