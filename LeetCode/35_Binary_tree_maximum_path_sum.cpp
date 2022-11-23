#include<bits/stdc++.h>
using namespace std;
class Solution {
    int pathSum(TreeNode * root, int & maxi){
        if(root == NULL)return 0;
        int left = max(0,pathSum(root->left,maxi));
        int right = max(0,pathSum(root->right,maxi));
        maxi = max(maxi, left+right+root->val);
        return max(left,right)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        pathSum(root, maxi);
        return maxi;
    }
};
int main(){
 
    return 0;
}