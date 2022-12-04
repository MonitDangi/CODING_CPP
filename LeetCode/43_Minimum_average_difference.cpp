#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long long totalSum = nums[0];
        int n = nums.size();
        vector<long long>sum;
        int ans = 0;
        int avg = INT_MAX;
        sum.push_back(nums[0]);
        for(int i = 1;i < nums.size(); i++){
            sum.push_back(totalSum + nums[i]);
            totalSum  = sum.back();
        }
        int temp_avg ;
        for(int i = 0;i<nums.size();i++){
            if(n-i-1 == 0){
                temp_avg = sum[i]/(i+1);
            }
            else temp_avg = abs(sum[i]/(i+1)- (totalSum-sum[i])/(n-i-1));
            if(temp_avg < avg){
                avg = temp_avg;
                ans = i;
            }
        }
        return ans;
    }
};
int main(){
 
    return 0;
}