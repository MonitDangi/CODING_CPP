#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool isValid(int i, int j, int m, int n){
        if(i>=0 && j>=0&&i<m &&j<n)return true;
        return false;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>>rem;
        for(int i = 0; i<n; i++){
            if(grid[0][i]){
                rem.push({0,i});
                grid[0][i] = 0;
            }
            if(grid[m-1][i]){
                rem.push({m-1,i});
                grid[m-1][i] = 0;
            }
        }
        for(int i =0; i<m; i++){
            if(grid[i][0]){
                rem.push({i,0});
                grid[i][0] = 0;
            }
            if(grid[i][n-1]){
                rem.push({i,n-1});
                grid[i][n-1] = 0;
            }
        }
        while(rem.size()){
            auto x = rem.front();
            rem.pop();
            int i = x.first, j= x.second;
            if(isValid(i-1,j,m,n)&& grid[i-1][j]){
                rem.push({i-1,j});
                grid[i-1][j] = 0;
            }
            if(isValid(i+1,j,m,n)&& grid[i+1][j]){
                rem.push({i+1,j});
                grid[i+1][j] = 0;
            }
            if(isValid(i,j-1,m,n)&& grid[i][j-1]){
                rem.push({i,j-1});
                grid[i][j-1] = 0;
            }
            if(isValid(i,j+1,m,n)&& grid[i][j+1]){
                rem.push({i,j+1});
                grid[i][j+1] = 0;
            }
        }
        int ans = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++)if(grid[i][j])ans++;
        }
        return ans;
    }
};
int main(){
}