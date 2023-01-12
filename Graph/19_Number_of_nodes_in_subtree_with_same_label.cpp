#include<bits/stdc++.h>
using namespace std;
class Solution {
    void find(int i, vector<int>adj[], vector<int>&vis, vector<int>&freq,vector<int>&ans,string&l){
        vis[i] = 1;
        int v = freq[l[i]-'a'];
        for(auto x:adj[i]){
            if(!vis[x]){
                find(x,adj,vis,freq,ans,l);
            }
        }
        ans[i] = freq[l[i]-'a']-v+1;
        freq[l[i]-'a']++;
    }
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>freq(26,0);
        vector<int>ans(n,0);
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        find(0,adj,vis,freq,ans,labels);
        return ans;
    }
};
int main(){
}