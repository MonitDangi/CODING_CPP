#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
         int s = nums.size();
        vector<int>dp1(s,1);
        vector<int>dp2(s,1);

        for(int i=1;i<s;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])dp1[i] = max(dp1[i],1+dp1[j]);
            }
        }
        for(int i=s-1;i>=0;i--){
            for(int j=i+1;j<s;j++){
                if(nums[i]>nums[j])dp2[i] = max(dp2[i], 1+dp2[j]);
            }
        }
        
        int ans = 0;
        for(int i=1;i<s-1;i++){
            if(dp1[i]!= 1 && dp2[i]!=1)ans = max(ans,dp1[i]+dp2[i]-1);
        }
        return s-ans;
    }
};
int main(){
    return 0;
}