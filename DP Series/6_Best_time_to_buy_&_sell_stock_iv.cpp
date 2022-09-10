class Solution {
    int n;
    int profit(int ind,vector<int>& v,int buy,int rem,vector<vector<vector<int>>>&dp){
        if(ind == n)return 0;
        if(rem == 0){
            return 0;
        }
        if(dp[ind][rem-1][buy]!=-1)return dp[ind][rem-1][buy];
        int p =0;
        if(buy){
            int x1 = - v[ind]+profit(ind+1,v,0,rem,dp);
            int y1 = profit(ind+1,v,1,rem,dp);
            p= max(x1,y1);
        }
        else{
            p= max(v[ind]+profit(ind+1,v,1,rem-1,dp),profit(ind+1,v,0,rem,dp));
        }
        return dp[ind][rem-1][buy] = p ;
        
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(k,vector<int>(2,-1)));
        n=prices.size();
        int ans = profit(0,prices,1,k,dp);
        return ans;
    }
};