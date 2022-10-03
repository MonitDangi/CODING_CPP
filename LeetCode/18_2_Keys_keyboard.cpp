#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSteps(int n) {
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=(i+1)/2;j++){
                if(i%j == 0){
                    if(j==1){
                        dp[i] = i;
                    }
                    else{
                        dp[i] = min(dp[i],((i/j)-1)+dp[j]+1);
                    }
                }
            }
        }
        return dp[n];
    }
};
int main(){
    return 0;
}