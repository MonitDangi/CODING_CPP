#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
    static bool cmp(vector<int>&a, vector<int>&b){
        return a[1]<b[1];
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>jobs(n);
        for(int i = 0; i < n; i++){
            jobs[i] = {startTime[i],endTime[i],profit[i]};
        }
        sort(jobs.begin(),jobs.end(),cmp);
        map<int,int>mp = {{1,0}};
        for(auto x:jobs){
            auto p = mp.upper_bound(x[0]);
            p--;
            int val = x[2] + p->second;
            if(mp.count(x[1]) == 0) mp[x[1]] = mp.rbegin()->second;
            mp[x[1]] = max(x[2]+p->second,mp[x[1]]);
        }

        return mp.rbegin()->second;
    }
};
int main(){
 
    return 0;
}