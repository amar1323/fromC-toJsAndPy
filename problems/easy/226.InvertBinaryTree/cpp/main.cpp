#include <iostream>
#include <queue>
/*
    Problem statement:
    Given the root of a binary tree, invert the tree, and return its root.
*/
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    string print(){
        string ret = "[";
        if(this){
            queue<TreeNode*> q;
            q.push(this);
            while(q.size()){
                auto curr = q.front();
                q.pop();
                ret+=to_string(curr->val)+",";
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            ret.pop_back();

        }
        ret+="]";
        return move(ret);
    }
};

void helper(TreeNode* root){
    if(root){
        swap(root->left, root->right);
        helper(root->left);
        helper(root->right);
    }
}
TreeNode* invertTree(TreeNode* root) {
    helper(root);
    return root;
}
int main() {
    TreeNode* root1 = new TreeNode(4,new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7, new TreeNode(6), new TreeNode(9)));
    TreeNode* root2 = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    TreeNode* root3= new TreeNode();

    TreeNode* ans1 = invertTree(root1);
    TreeNode* ans2 = invertTree(root2);
    TreeNode* ans3 = nullptr;

    cout << "My answer for invertTree(root1) = " << ans1->print()<< " and the right answer is [4,7,2,9,6,3,1]" << endl;
    cout << "My answer for invertTree(root2) = " << ans2->print() << " and the right answer is [2,3,1]" << endl;
    cout << "My answer for invertTree(root3) = " << ans3->print()<< " and the right answer is []" << endl;  
    return 0;
}