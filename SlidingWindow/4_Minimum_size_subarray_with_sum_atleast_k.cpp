#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<int,long long>>dq;
        dq.push_back({-1,0});
        long long sum = 0;
        int ans = nums.size()+1;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            while(dq.size() && dq.back().second >= sum){
                dq.pop_back();
            }
            dq.push_back({i,sum});
            while(sum - dq.front().second >= k){
                ans = min(ans, i - dq.front().first);
                dq.pop_front();
            }
        }
        if(ans > nums.size())return -1;
        return ans;
    }
};
int main(){
}