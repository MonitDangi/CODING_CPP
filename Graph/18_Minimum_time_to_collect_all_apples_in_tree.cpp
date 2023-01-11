#include<bits/stdc++.h>
using namespace std;
class Solution {
    int count(int i,vector<int>arr[], vector<bool>&ha, vector<int>&vis){
        int ans = 0;
        vis[i] = 1;
        for(auto x:arr[i]){
            if(vis[x])continue;
            int temp = count(x,arr,ha,vis);
            if(temp > 0)ans += temp+1;
        }
        if((ha[i] || ans )&&i>0)ans++;
        return ans;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& ha) {
        vector<int> arr[n];
        vector<int>vis(n,0);
        for(auto &x:edges){
            arr[x[0]].push_back(x[1]);
            arr[x[1]].push_back(x[0]);
        }
        int ans = count(0,arr,ha,vis);
        return ans;
    }
};
int main(){
}