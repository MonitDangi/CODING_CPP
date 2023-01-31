#include<bits/stdc++.h>
using namespace std;
class Solution {
    // vector<pair<int,int>>v;
    // unordered_map<int,unordered_map<int,int>>dp;
    // unordered_map<int,unordered_map<int,int>>dp2;
    // int find(int ind, int maxScore, int age){
    //     if(ind == v.size())return 0;
    //     int take = 0, ntake = 0;
    //     ntake = find(ind+1, maxScore, age);
    //     if(dp[ind][maxScore]> 0)return dp[ind][maxScore];
    //     if(dp2[ind][maxScore] > 0)return 0;
    //     if(age == v[ind].first){
    //         take = v[ind].second + find(ind+1, v[ind].second, age);
    //     }
    //     else if(age < v[ind].first && maxScore <= v[ind].second){
    //          take = v[ind].second + find(ind+1, v[ind].second, v[ind].first);
    //     }
    //     int ans = max(take, ntake);
    //     if(ans == 0)return  dp2[ind][maxScore]++;
    //     return dp[ind][maxScore] = ans;
    // }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>>v;
        for(int i = 0;  i < ages.size(); i++){
            v.push_back({ages[i], scores[i]});
        }
        // dp.resize(ages.size(), vector<int>(m+1,-1));
        sort(v.begin(), v.end());
        int ans = 0;
        int n = ages.size();
        int dp[n];
        for(int i = 0; i < n; i++){
            dp[i] = v[i].second;
            for(int j = 0; j < i; j++){
                if(v[j].second <= v[i].second){
                    dp[i] = max(dp[i], dp[j] + v[i].second);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
int main(){
}