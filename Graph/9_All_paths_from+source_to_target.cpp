#include<bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(vector<vector<int>>&graph,vector<int>path, int src, int dst,vector<vector<int>>&ans){
        path.push_back(src);
        if(src == dst){
            ans.push_back(path);
            return;
        }
        for(auto x:graph[src]){
            dfs(graph,path,x,dst,ans);
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        if(graph.size() == 0)return ans;
        vector<int>path;
        dfs(graph, path, 0, graph.size()-1, ans);
        return ans;
    }
};
int main(){
}