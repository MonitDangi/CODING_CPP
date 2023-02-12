#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,int>>rem;
        vector<pair<int, int>>dp[n];
        for(auto & x: flights){
            dp[x[0]].push_back({x[1], x[2]});
        }
        rem.push({src,0});
        int ans = INT_MAX;
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;
        k++;
        while(!rem.empty() && k--){
            int sz = rem.size();
            while(sz--){
                
                int so = rem.front().first;
                int cost = rem.front().second;
                rem.pop();
                for(auto &x : dp[so]){
                    if(dist[x.first] > cost + x.second){
                        dist[x.first] = min(dist[x.first], cost + x.second);
                        rem.push({x.first, cost + x.second});
                    }
                }
            }
        }
        if(dist[dst] == INT_MAX)return -1;
        return dist[dst];;
    }
};
int main(){
}