#include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    map<int,int>v;
    void inorder(TreeNode* root ){
        if(root == NULL)return;
        inorder(root->left);
        v[root->val]++;
        inorder(root->right);
    }
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>>ans;
        inorder(root);
        for(auto x:queries){
            vector<int>temp;
            auto num = v.lower_bound(x);
            if(num->first == x){
                temp.push_back(x);
                temp.push_back(x);
            }
            else if(num == v.begin()){
                temp.push_back(-1);
                temp.push_back(num->first);
            }
            else if(num == v.end()){
                --num;
                temp.push_back(num->first);
                temp.push_back(-1);
                
            }
            else{
                --num;
                temp.push_back(num->first);
                ++num;
                temp.push_back(num->first);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
int main(){
}