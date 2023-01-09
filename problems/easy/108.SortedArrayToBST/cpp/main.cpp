#include <iostream>
#include <queue>
/*
    Problem statement:
    Given an integer array nums where the elements are sorted in ascending order, convert it to a 
    height-balanced binary search tree.*/
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

TreeNode* helper(vector<int>& nums, int s, int e){
    if(s>=e) return nullptr;
    TreeNode* root = new TreeNode(nums[(s+e)/2]);
    root->left = helper(nums, s, (s+e)/2);
    root->right = helper(nums, (s+e)/2+1, e);
    return root;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return helper(nums, 0, nums.size());
}

int main() {
    vector<int> in1 = {-10,-3,0,5,9};
    vector<int> in2 = {1,2};
    auto ans1 = sortedArrayToBST(in1);
    auto ans2 = sortedArrayToBST(in2);
    cout << "My answer for invertTree(in1) = " << ans1->print()<< " and the right answer is [0,-3,9,-10,5]" << endl;
    cout << "My answer for invertTree(in2) = " << ans2->print() << " and the right answer is [2,1]" << endl;
    return 0;
}