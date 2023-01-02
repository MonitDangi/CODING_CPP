#include<bits/stdc++.h>
using namespace std;
class Solution {
    int dfs(int root, vector<vector<int>>&v, vector<int>&vis, vector<int>&nodeCount,long long &ans, int seats){
        vis[root] = 1;
        for(auto i:v[root]){
            if(vis[i] != 1)nodeCount[root] += dfs(i,v,vis,nodeCount,ans,seats);
        }
        if(root){
            ans += nodeCount[root]/seats;
            if(nodeCount[root]%seats)ans+=1;
        }
        return nodeCount[root];
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        long long ans = 0;
        vector<vector<int>>v(n);
        vector<int>vis(n,-1);
        vector<int>nodeCount(n,1);
        for(auto r:roads){
            v[r[0]].push_back(r[1]);
            v[r[1]].push_back(r[0]);
        }
        dfs(0,v,vis,nodeCount,ans,seats);
        return ans;
    }
};
int main(){
}