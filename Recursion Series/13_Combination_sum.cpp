#include<bits/stdc++.h>
using namespace std;
class Solution {
    vector<vector<int>>ans;
    vector<int>v;
    vector<int>temp;
    void solve(int ind, int target){
        if(target<0||ind>=v.size())return;
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(v[ind]>target)return;
        solve(ind+1,target);
        temp.push_back(v[ind]);
        solve(ind,target-v[ind]);
        temp.pop_back();
        
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        v=candidates;
        solve(0,target);
        return ans;
    }
};
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    Solution s;
    int target;
    cin>>target;
    s.combinationSum(v,target);
    return 0;
}