#include<bits/stdc++.h>
using namespace std;
class Solution {
    int robber(TreeNode * root, map<TreeNode *, int> &mp){
        if(!root)return 0;
        if(mp.find(root)!=mp.end())return mp[root];
        int ans = root->val;
        if(root->left)ans += robber(root->left->left,mp)+ robber(root->left->right, mp);
        if(root->right)ans += robber(root->right->left,mp)+ robber(root->right->right, mp);
        return mp[root] = max(ans, robber(root->left, mp)+robber(root->right, mp));
    }
public:
    int rob(TreeNode* root) {
        map<TreeNode *, int>mp;
        int ans = robber(root, mp);
        return ans;
    }
};
int main(){
}