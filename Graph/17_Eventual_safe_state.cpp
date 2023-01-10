#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool dfs(int i, vector<int> adj[], vector<int>&vis, vector<int>&pathvis){
        vis[i] = 1, pathvis[i] = 1;
        for(int x: adj[i]){
            if(!vis[x]){
                if(dfs(x, adj, vis, pathvis))return 1;
            }
            else if(pathvis[x])return 1;
        }
        pathvis[i] = 0;
        return 0;
    }
  public:
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<int>vis(n,0), pathvis(n,0);
        vector<int>ans;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, adj, vis, pathvis);
            }
            if(!pathvis[i])ans.push_back(i);
        }
        return ans;
    }
};
int main(){
}