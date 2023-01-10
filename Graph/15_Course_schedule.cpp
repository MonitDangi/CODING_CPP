#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<int>com;
    unordered_map<int,int>mp;
    bool dfs(int n, vector<vector<int>>&adj){
        if(com[n])return true;
        if(mp[n])return false;
        mp[n]++;
        for(auto x:adj[n]){
            if(!dfs(x,adj)){
                mp[n]--;
                return false;
            }
        }
        mp[n]--;
        return true;

    }
public:
    bool canFinish(int num, vector<vector<int>>& pr) {
        vector<vector<int>>adj(num);
        for(auto &x:pr){
            adj[x[0]].push_back(x[1]);
        }
        com.resize(num,0);
        for(int i = 0; i < num; i++){
            if(!dfs(i,adj))return false;
            com[i] = 1;
        }
        return true;
    }
};
int main(){
}