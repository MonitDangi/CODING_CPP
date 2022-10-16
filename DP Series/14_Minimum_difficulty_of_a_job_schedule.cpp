#include<bits/stdc++.h>
using namespace std;
class Solution {
    int f(int ind,int prev,vector<int>& jobDifficulty, int d,vector<vector<vector<int>>>&dp){
        if(ind == jobDifficulty.size()){
            if(d == 0){
                return prev;
            }
            else return 1e5+7;
        }
        if(jobDifficulty.size()-ind < d){
            return 1e5+7;
        }
        if(ind == 0){
            int ans  = f(ind+1,jobDifficulty[ind],jobDifficulty,d-1,dp);
            return ans;
        }
        if(dp[ind][prev][d]!=-1)return dp[ind][prev][d];
        int sameDay = f(ind+1,max(prev,jobDifficulty[ind]),jobDifficulty,d,dp);
        int nextDay = prev + f(ind+1,jobDifficulty[ind],jobDifficulty,d-1,dp);
        return dp[ind][prev][d] = min(sameDay,nextDay);
    }
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size()<d)return -1;
        vector<vector<vector<int>>>dp(jobDifficulty.size()+1,vector<vector<int>>(1001,vector<int>(d+1,-1)));
        int ans = f(0,-1,jobDifficulty,d,dp);
        return ans;
    }
};
int main(){
    return 0;
}