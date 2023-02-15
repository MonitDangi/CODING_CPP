#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++){
            int x = lower - nums[i];
            int y = upper - nums[i];
            int fi = lower_bound(nums.begin()+i+1, nums.end(),x)-nums.begin();
            int si = upper_bound(nums.begin()+i+1, nums.end(),y)-nums.begin();            
            ans += (si-fi);
        }
        return ans;
    }
};
int main(){
}