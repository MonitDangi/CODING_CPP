#include<bits/stdc++.h>
using namespace std;
class Solution {
    int mod = 1e9+7;
    int solve(int count,int n,int k,int target,vector<vector<int>>&dp){
        if(count==n)return target == 0;
        if(dp[count][target]!=-1)return dp[count][target];
        long long ans = 0;
        for(int i=1;i<=k;i++){
            if(i>target)break;
            ans = (ans+solve(count+1,n,k,target-i,dp))%mod;
        }
        return  dp[count][target] = ans;
    }
    
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        int ans = solve(0,n,k,target,dp);
        return ans;
    }
};
int main(){
    return 0;
}