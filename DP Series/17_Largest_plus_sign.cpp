#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>dp1(n,vector<int>(n,1));
        for(auto x:mines){
            dp1[x[0]][x[1]] = 0;
        }
        vector<vector<int>>dp2 = dp1;
        vector<vector<int>>dp3 = dp1;
        vector<vector<int>>dp4 = dp1;
        for(int i =0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == 0 || dp1[i][j] == 0)continue;
                else dp1[i][j] = 1+ dp1[i][j-1];
            }
        }
        for(int i =0; i < n; i++){
            for(int j = n-1; j >= 0; j--){
                if(j == n-1 || dp2[i][j] == 0)continue;
                else dp2[i][j] = 1+ dp2[i][j+1];
            }
        }
        for(int i =0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == 0 || dp3[j][i] == 0)continue;
                else dp3[j][i] = 1+ dp3[j-1][i];
            }
        }
        for(int i =n-1; i >= 0; i--){
            for(int j = n-1; j >= 0; j--){
                if(j == n-1 || dp4[j][i] == 0)continue;
                else dp4[j][i] = 1+ dp4[j+1][i];
            }
        }
        int ans =0;
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                int x = min(dp1[i][j],min(dp2[i][j],min(dp3[i][j],dp4[i][j])));
                ans = max(ans,x);
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}