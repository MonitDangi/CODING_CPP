#include<bits/stdc++.h>
using namespace std;
class Solution {
    int ans = 0;
    int solve(TreeNode * root){
        if(root == NULL)return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        if(l == 0 && r == 0){
            return -1;
        }
        if(l == -1 || r == -1){
            ans += 1;
            return 1;
        }
        if(l == 1 || r == 1)return 0;
        return -1;
    }
public:
    int minCameraCover(TreeNode* root) {
        int p = solve(root);
        if(p == -1)ans++;
        return ans;
    }
};
int main(){
}