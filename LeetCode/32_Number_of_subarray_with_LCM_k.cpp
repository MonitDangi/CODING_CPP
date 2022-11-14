#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int ans = 0;
        for(int i = 0;i<nums.size(); i++){
            if(k%nums[i]>0)continue;
            long long l = nums[i]; 
            if(nums[i]>=k)ans++;
            for(int j=i+1;j<nums.size();j++){
                if(k%nums[j]>0)break;
                l = lcm(l,nums[j]);
                if(l >= k)ans++;
                
            }
            
        }
        return ans;
    }
};
int main(){
 
    return 0;
}