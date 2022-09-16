class Solution {
    int f(vector<int>&nums, vector<int>&mul, int left,int right,int curr,vector<vector<int>>&dp){
        if(curr == mul.size())return 0;
        if(dp[left][curr]!=INT_MIN)return dp[left][curr];
        int l = nums[left]* mul[curr] + f(nums,mul,left+1,right,curr+1,dp);
        int r = nums[right]* mul[curr] + f(nums,mul,left,right-1,curr+1,dp);
        return dp[left][curr] = max(l,r);
    }
    
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        vector<vector<int>>dp(mul.size()+1,vector<int>(mul.size()+1,INT_MIN));
        int ans = f(nums,mul,0,nums.size()-1,0,dp);
        return ans;
    }
};