#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>>p;
        vector<vector<int>>ans;
        for(int i : nums1){
            for(int j :nums2){
                int sum = i+j;
                if(p.size()<k)p.push({sum,{i,j}});
                else if(p.top().first > sum){
                    p.pop();
                    p.push({sum,{i,j}});
                }
                else break;
            }
        }
        while(!p.empty()){
            ans.push_back({p.top().second.first,p.top().second.second});
            p.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main(){
}