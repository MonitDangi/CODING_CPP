#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>>adj;
    int s;
    vector<int>sub;
    vector<int>dep;
    vector<int>sum;
    void dfs(int u, int par = -1){
        sub[u] =1;
        for(auto x:adj[u]){
            if(x==par)continue;
            dep[x] = dep[u] + 1;
            dfs(x, u);
            sub[u] += sub[x];
        }
    }
    void dfs2(int u, int par = -1){
        for(auto x:adj[u]){
            if(x == par)continue;
            sum[x] = sum[u] - sub[x] + (s - sub[x]);
            dfs2(x,u);
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        s =  n;
        adj.resize(n);
        sub.resize(n+1);
        dep.resize(n+1);
        sum.resize(n);
        for(auto &x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0);
        for(int i = 0; i < n; i++){
            sum[0] +=dep[i];
        }
        dfs2(0);
        return sum;
    }
};
int main(){
}