/*
    Problem statement:
    Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helper(TreeNode* r, TreeNode* l){
    if(r==nullptr && l == nullptr) return true;
    else if((r && l==nullptr) || (l && r == nullptr) ) return false;
    if(r->val != l->val) return false;
    return helper(r->left, l->right)*helper(r->right, l->left);
}

bool isSymmetric(TreeNode* root) {
    if(root){
        return helper(root->left, root->right);
    }
    return true;   
}

int main(){

    return 0;
}