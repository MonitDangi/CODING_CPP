#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>nums;
        for(int i=0;i<arr.size();i++){
            int y = abs(arr[i]-x);
            cout<<y<<endl;
            nums.push_back({y,arr[i]});
        }
        sort(nums.begin(),nums.end());
        vector<int>ans;
        int ind =0;
        while(k--){
            ans.push_back(nums[ind++].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
    return 0;
}