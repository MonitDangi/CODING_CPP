#include<bits/stdc++.h>
using namespace std;
class Solution {
    int solve(int n, int egg, vector<vector<int>>&dp){
        if(dp[n][egg] != -1)return dp[n][egg];
        if(egg == 1 || n <= 1)return n;
        int ans = INT_MAX;
        int low = 0, high = n, temp = 0;
        while(low <= high){
            int mid = low+(high-low)/2;
            int left =  solve(mid-1, egg-1, dp);
            int right = solve(n-mid, egg, dp);
            temp = 1+max(left,right);
            ans = min(ans, temp);
            if(left < right){
                low = mid+1;
            }
            else high = mid-1;
        }
        return dp[n][egg] = ans;
    }
public:
    int twoEggDrop(int n) {
        vector<vector<int>>dp(n+1, vector<int>(3,-1));
        int ans = solve(n, 2, dp);
        return ans;
    }
};
int main(){
}