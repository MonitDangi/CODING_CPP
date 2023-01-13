#include<bits/stdc++.h>
using namespace std;
class Solution {
    int dfs(int i, vector<int>adj[], string &s, int &ans){
        int lc = 0, lsc = 0;
        for(auto x:adj[i]){
            int lcc = dfs(x, adj, s, ans);
            if(s[i] == s[x])continue;
            if(lcc > lc){
                lsc = lc;
                lc = lcc;
            }
            else if(lcc > lsc){
                lsc = lcc;
            }

        }
        ans = max(ans, lc+lsc+1);
        return lc+1;
    }
public:
    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<int>adj[n];
        for(int i = 1; i < parent.size(); i++){
            adj[parent[i]].push_back(i);
        }
        int ans = 1;
        dfs(0, adj, s, ans);
        return ans;
    }
};
int main(){
}