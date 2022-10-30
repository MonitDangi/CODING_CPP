#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        queue<vector<int>>rem;
        rem.push({0,0,0,k});
        while(rem.size()){
            auto v = rem.front();
            int i = v[0];
            int j = v[1];
            rem.pop();
            if(i<0 || j<0 || i>=m || j>=n)continue;
            if(i == m-1 && j == n-1)return v[2];
            if(grid[i][j] == 1){
                if(v[3]>0){
                    v[3]--;
                }
                else continue;
            }
            if(dp[i][j] != -1 && dp[i][j] >= v[3])continue;
            dp[i][j] = v[3];
            rem.push({i+1,j,v[2]+1,v[3]});
            rem.push({i,j+1,v[2]+1,v[3]});
            rem.push({i-1,j,v[2]+1,v[3]});
            rem.push({i,j-1,v[2]+1,v[3]});
        }

        return -1;
    }
};
int main(){
    return 0;
}