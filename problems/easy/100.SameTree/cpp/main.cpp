#include <iostream>
/*
    Problem statement:
    Given the roots of two binary trees p and q, write a function to check if they are the same or not.
    
    Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.*/
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p && q && p->val == q->val)
        return isSameTree(p->left, q->left) * isSameTree(p->right, q->right);
    else if (p == nullptr && q == nullptr)
        return true;
    return false;
}

int main() {
    TreeNode* root1p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* root1q = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* root2p = new TreeNode(2, new TreeNode(1), nullptr);
    TreeNode* root2q = new TreeNode(2, nullptr, new TreeNode(1));
    TreeNode* root3p = new TreeNode(1, new TreeNode(5), new TreeNode(2));
    TreeNode* root3q = new TreeNode(1, new TreeNode(5), new TreeNode(2));

    cout << "My answer for invertTree(root1p,root1q) = " << isSameTree(root1p, root1q) << " and the right answer is 1" << endl;
    cout << "My answer for invertTree(root2p,root2q) = " << isSameTree(root2p, root2q) << " and the right answer is 0" << endl;
    cout << "My answer for invertTree(root3p,root3q) = " << isSameTree(root3p, root3q) << " and the right answer is 1" << endl;
    return 0;
}