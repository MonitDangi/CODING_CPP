#include<bits/stdc++.h>
#include<iostream>
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
    int minSwaps(vector<int>arr, int n)
{
    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }
    sort(arrPos, arrPos + n);
 
    vector<bool> vis(n, false);
 
    int ans = 0;
 
    for (int i = 0; i < n; i++)
    {
        if (vis[i] || arrPos[i].second == i)
            continue;
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
 
            j = arrPos[j].second;
            cycle_size++;
        }
        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }
    return ans;
}
public:
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*>rem;
        rem.push(root);
        while(!rem.empty()){
            int s = rem.size();
            vector<int>v;
            while(s--){
                v.push_back(rem.front()->val);
                if(rem.front()->left)rem.push(rem.front()->left);
                if(rem.front()->right)rem.push(rem.front()->right);
                rem.pop();
            }
            ans += minSwaps(v,v.size());
        }
        return ans;
    }
};
int main(){
 
    return 0;
}