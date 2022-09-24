#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
    void path(TreeNode* root, int targetSum,vector<vector<int>>&ans,vector<int>&v){
        if(root->left==NULL&&root->right==NULL){
            if(targetSum==root->val){
                v.push_back(root->val);
                ans.push_back(v);
                v.pop_back();
            }
            return;
        }
        v.push_back(root->val);
        if(root->left){
            path(root->left,targetSum-root->val,ans,v);
        }
        if(root->right){
            path(root->right,targetSum-root->val,ans,v);
        }
        v.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        vector<int>v;
        path(root,targetSum,ans,v);
        return ans;
    }
};
int main(){
    return 0;
}