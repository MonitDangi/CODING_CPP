#include<bits/stdc++.h>
using namespace std;
class Solution {
    int getcount(int same){
        if(same==1)
            return 1;
        if(same<10)
            return 2;
        if(same<100)
            return 3;
        else
            return 4;
    }
public:
    int getLengthOfOptimalCompression(string s, int K) {
        
        if(K==s.size())return 0;
        int n = s.size();
        
        vector<vector<int>>dp(n+1,vector<int>(K+1,n));
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            for(int k=0;k<=K;k++){
                if(k>0){
                    dp[i][k] = min(dp[i][k],dp[i-1][k-1]);
                }
                int same =0, diff =0;
                for(int j=i;j>=1;j--){
                    if(s[j-1]==s[i-1])same++;
                    else diff++;
                    if(diff > k)break;

                    dp[i][k] = min(dp[i][k],dp[j-1][k-diff]+getcount(same));
                }
            }
        }
        return dp[n][K];
    }
};
int main(){
    return 0;
}