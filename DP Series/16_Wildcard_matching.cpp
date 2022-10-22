#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool checkEqual(string &s, string &p ,int idx1, int idx2, vector<vector<int>>&dp){
        if(idx1<0 && idx2<0)return true;
        else if(idx1>=0 && idx2<0)return false;
        else if(idx1<0 && idx2>=0){
            for(int k = 0;k<=idx2;k++)if(p[k]!='*')return false;
            return true;
        }
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        bool ans = false;
        if(s[idx1] == p[idx2] || p[idx2] == '?')ans  = checkEqual(s, p, idx1-1, idx2-1, dp);
        else if(p[idx2] == '*'){
            if(checkEqual(s, p, idx1, idx2-1, dp))return true;
            else if(checkEqual(s, p, idx1-1, idx2, dp))return true;
        }
        return dp[idx1][idx2] = ans;
    }
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n =p.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        bool ans = checkEqual(s, p, m-1, n-1, dp); 
        return ans;
    }
};
int main(){
    return 0;
}