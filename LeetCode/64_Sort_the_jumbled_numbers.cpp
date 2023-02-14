#include<bits/stdc++.h>
using namespace std;
class Solution {
    static bool cmp(pair<int,int>&a, pair<int,int>&b){
        if(a.first == b.first){
            return b.second > a.second;
        }
        return a.first < b.first;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>>v;
        long long x = 0;
        for(int i = 0;  i < nums.size(); i++){
            if(nums[i] == 0){
                v.push_back({mapping[0],i});
                continue;
            }
            vector<int>temp;
            int x = nums[i];
            while(x){
                temp.push_back(mapping[x%10]);
                x/=10;
            }
            int y = 0;
            for(int j = temp.size()-1; j >=0; j--){
                y = y *10 + temp[j];
            }
            v.push_back({y,i});
        }
        sort(v.begin(),v.end(), cmp);
        vector<int>ans;
        for(int i = 0; i < v.size(); i++){
            ans.push_back(nums[v[i].second]);
        }
        return ans;
    }
};
int main(){
}