#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int checkDecodes(int ind,string &s,vector<int>&dp){
    if(ind >= s.size())return 1;
    if(s[ind]=='0')return 0;
    if(ind == s.size()-1)return 1;
    if(dp[ind]!=-1)return dp[ind];
    int pick1 =0,pick2= 0;
    pick1 = checkDecodes(ind+1,s,dp);
    int val = stoi(s.substr(ind,2));
    if(val<=26)pick2 = checkDecodes(ind+2,s,dp);
    return dp[ind] = pick1+pick2;
}

    int numDecodings(string s) {
        vector<int>dp(s.size()+1,-1);
        int ans = checkDecodes(0,s,dp);
        return ans;
    }
};
int main(){
    return 0;
}