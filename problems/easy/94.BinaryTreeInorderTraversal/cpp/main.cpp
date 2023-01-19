#include <iostream>
#include <vector>
/*
    Problem statement:
    Given the root of a binary tree, return the inorder traversal of its nodes' values.
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

void helper(TreeNode *root, vector<int> &ret) {
    if (root) {
        helper(root->left, ret);
        ret.push_back(root->val);
        helper(root->right, ret);
    }
}
vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;
    helper(root, ret);
    return ret;
}

int main() {
    TreeNode* root1 = new TreeNode(1, nullptr, new TreeNode(2, new TreeNode(3), nullptr));
    TreeNode* root2 = nullptr;
    TreeNode* root3 = new TreeNode(1);
    vector<int> ans1 = inorderTraversal(root1);
    vector<int> ans2 = inorderTraversal(root2);
    vector<int> ans3 = inorderTraversal(root3);
    string pr1= "[",pr2 ="[", pr3 = "[";
    for(auto i : ans1) pr1+= to_string(i)+",";
    for(auto i : ans2) pr2+= to_string(i)+",";
    for(auto i : ans2) pr3+= to_string(i)+",";
    pr1.pop_back();pr2.pop_back();pr3.pop_back();
    pr1+="]"; pr2+="]"; pr3+="]";  
    cout << "My answer for inorderTraversal(root1) = " << pr1   << " and the right answer is [1,3,2]" << endl;
    cout << "My answer for inorderTraversal(root2) = " << pr2   << " and the right answer is []" << endl;
    cout << "My answer for inorderTraversal(root3) = " << pr3   << " and the right answer is [1]" << endl;
    return 0;
}