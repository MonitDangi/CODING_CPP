#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int odd_no = 0, cnt = 0;
        int ans = 0;
        deque<int>dq, ind;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2){
                odd_no++;
                dq.push_back(nums[i]);
                ind.push_back(i+1);
            }
            else{
                dq.push_back(nums[i]);
            }
            if(odd_no > k){
                cnt = ind.front();
                ind.pop_front();
            }
            while(odd_no > k){
                while(dq.front()%2 == 0){
                    dq.pop_front();
                }
                dq.pop_front();
                odd_no--;
            }
            if(k == odd_no)ans += ind.front()-cnt;
        }
        return ans;
    }
};
int main(){
}