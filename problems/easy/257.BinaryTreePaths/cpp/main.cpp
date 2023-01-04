#include <iostream>
#include <vector>
#include <string>

/*
    Problem statement:
    Given the root of a binary tree, return all root-to-leaf paths in any order.
    A leaf is a node with no children.
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


void helper(TreeNode* root, string path, vector<string>& ret){
    if(root){
        path += (to_string(root->val)+"->");
        if(root->left==nullptr && root->right==nullptr){
          path.pop_back();
          path.pop_back();
          ret.push_back(path);
          return;
        }
        helper(root->left, path, ret);
        helper(root->right, path, ret);
    }

}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ret;
    helper(root, "", ret);
    return ret;
}


int main() {
    TreeNode* root1 = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)), new TreeNode(3));
    TreeNode* root2 = new TreeNode(1);
    auto ans1 = binaryTreePaths(root1);
    auto ans2 = binaryTreePaths(root2);
    string pr1="[", pr2="[";
    for(auto s:ans1) pr1+=s+",";
    for(auto s:ans2) pr2+=s+",";
    pr1.pop_back(), pr1+="]";
    pr2.pop_back(), pr2+="]";
    cout << "My answer for binaryTreePaths(root1) = " <<  pr1  << " and the right answer is [1->2->5,1->3]" << endl;
    cout << "My answer for binaryTreePaths(root2) = " <<  pr2  << " and the right answer is [1]" << endl;
    return 0;
}