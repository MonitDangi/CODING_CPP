#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>mp;
        int sum = 0;
        int ans =0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(mp[sum-goal]){
                ans += mp[sum-goal];
            }
            if(sum == goal )ans++;
            mp[sum]++;
        } 
        return ans;
    }
};
int main(){
    return 0;
}