#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() == 0)return 0;
        int ans = 0;
        vector<unordered_map<long long,int>>dp(nums.size());
        long long diff = 0;
        for(int i = 1; i<nums.size();++i){
            for(int j = i-1;j>=0;j--){
                diff = (long long)nums[i] - (long long)nums[j];
                if(dp[j][diff]){
                    ans += dp[j][diff];
                    dp[i][diff] += dp[j][diff];
                }
                ++dp[i][diff];
            }
        }
        return ans;
    }
};
int main(){
 
    return 0;
}