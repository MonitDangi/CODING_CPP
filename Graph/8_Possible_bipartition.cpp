#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool isBipartite(vector<vector<int>>&adj, int n, int i, vector<int>&color){
        queue<int>rem;
        rem.push(i);
        color[i] = 1;
        while(!rem.empty()){
            int curr = rem.front();
            rem.pop();
            for(int ele:adj[curr]){
                if(color[ele] == color[curr])return false;
                if(color[ele]==-1){
                    color[ele] = 1-color[curr];
                    rem.push(ele);
                }
            }
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n+1);
        for(auto &x:dislikes){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i] == -1){
                if(!isBipartite(adj,n,i,color))
                    return false;    
            }
        }
        return true;
    }
};
int main(){
}