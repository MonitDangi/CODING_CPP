#include<bits/stdc++.h>
using namespace std;
class Solution {
    int profit(int ind, vector<int>& prices, int buy, vector<vector<int>>&dp){
        if(ind >= prices.size())return 0;
        int ans = 0;
        if(dp[ind][buy] != -1)return dp[ind][buy];
        if(buy){
            int take = -prices[ind] + profit(ind+1,prices,0,dp);
            int nottake = profit(ind+1,prices,1,dp);
            ans = max(take,nottake);
        }
        else {
            int sell = prices[ind] + profit(ind+2,prices,1,dp);
            int notsell = profit(ind+1,prices,0,dp);
            ans = max(sell, notsell);
        }
        return dp[ind][buy] = ans;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(), vector<int>(2,-1));
        int ans = profit(0,prices,1,dp);
        return ans;
    }
};
int main(){
    return 0;
}