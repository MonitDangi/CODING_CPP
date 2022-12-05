#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    // adj matrix by roads
    vector<pair<int, int>> adj[100001];
    
    int minScore(int n, vector<vector<int>>& roads) {
        // build adj matrix
        for(auto i : roads) {
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        vector<int> vis(n + 1, 0);
        queue<int> rem;
        rem.push(1);
        int ans = INT_MAX;
        while(rem.size()){
            int from = rem.front();
            rem.pop();
            vis[from] = 1;
            for(auto p: adj[from]) {
                if(!vis[p.first]) {
                    ans = min(ans, p.second);
                    rem.push(p.first);
                }
            }
        }
        return ans;
        
    }
};
int main(){
 
    return 0;
}