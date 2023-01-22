#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans = 0;
        deque<int>dq;
        map<int,int>mp;
        int num1 = 0;
        for(int i = 0; i < nums.size(); i++){
            dq.push_back(nums[i]);
            mp[nums[i]]++;
            while(mp.size() > k){
                mp[dq.front()]--;
                if(mp[dq.front()] == 0)mp.erase(dq.front());
                dq.pop_front();
            }
            num1 += dq.size();
        }
        int num2 = 0;
        k--;
        while(dq.size()){
            mp[dq.front()]--;
            if(mp[dq.front()] == 0)mp.erase(dq.front());
            dq.pop_front();
        }
        for(int i = 0; i < nums.size(); i++){
            dq.push_back(nums[i]);
            mp[nums[i]]++;
            while(mp.size() > k){
                mp[dq.front()]--;
                if(mp[dq.front()] == 0)mp.erase(dq.front());
                dq.pop_front();
            }
            num2 += dq.size();
        }
        return num1-num2;
    }
};
int main(){
}