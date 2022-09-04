class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>mp;
        queue<pair<TreeNode*,pair<int,int>>>rem;
        rem.push({root,{0,0}});
        while(!rem.empty()){
            auto p = rem.front();
            rem.pop();
            TreeNode * node = p.first;
            int x=p.second.first, y=p.second.second;
            mp[x][y].insert(node->val);
            if(node->left){
                rem.push({node->left,{x-1,y+1}});
            }
            if(node->right){
                rem.push({node->right,{x+1,y+1}});
            }
        }
        for(auto p:mp){
            vector<int>col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};