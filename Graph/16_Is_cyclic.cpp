#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool dfs(int i, vector<int>&vis, vector<int>&pathvis, vector<int> adj[]){
        if(pathvis[i])return true;
        if(vis[i] && !pathvis[i])return false;
        vis[i] = 1;
        pathvis[i] = 1;
        for(int x:adj[i]){
            if(dfs(x,vis,pathvis,adj))return true;
        }
        pathvis[i] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>vis(V,0), pathvis(V,0);
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, vis, pathvis, adj))return true;
            }
        }
        return false;
    }
};
int main(){
}