#include<bits/stdc++.h>
using namespace std;
class Solution {
    void traverse(TreeNode * root,vector<vector<int>>&ans){
        if(root==NULL){
            return;
        }
        queue<TreeNode*>rem;
        rem.push(root);
        rem.push(NULL);
        int x=0;
        while(rem.size()>1){
            if(x==0){
                vector<int>v;
                while(rem.front()!=NULL){
                    TreeNode * node = rem.front();
                    v.push_back(node->val);
                    rem.pop();
                    if(node->left!=NULL){
                        rem.push(node->left);
                    }
                    if(node->right!=NULL){
                        rem.push(node->right);
                    }
                }
                rem.pop();
                rem.push(NULL);
                ans.push_back(v);
                x++;
            }
            else{
                vector<int>v;
                while(rem.front()!=NULL){
                    TreeNode * node = rem.front();
                    v.insert(v.begin(),node->val);
                    rem.pop();
                    if(node->left!=NULL){
                        rem.push(node->left);
                    }
                    if(node->right!=NULL){
                        rem.push(node->right);
                    }
                }
                rem.pop();
                rem.push(NULL);
                ans.push_back(v);
                x--;
            }
        }
        
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        traverse(root,ans);
        return ans;
    }
};
int main(){
}