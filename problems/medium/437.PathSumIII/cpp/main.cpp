/*
    Problem statement
    Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

    The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ret=0;

void explorePath(TreeNode * root ,long long int sum){
   if(!root)return ;
   if(root->val==sum) ret++;
   explorePath(root->left,sum-root->val);
   explorePath(root->right,sum-root->val);
  
}


int pathSum(TreeNode* root, int sum) {
  if(!root)return 0;
  explorePath(root,(long long int)sum);
  pathSum(root->left,sum);
  pathSum(root->right,sum);
  return ret;
}

int main(){

    return 0;
}