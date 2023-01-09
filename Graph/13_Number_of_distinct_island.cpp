#include<bits/stdc++.h>
using namespace std;
class Solution {
    void dfs(int i, int j, vector<vector<int>>&vis, vector<vector<int>>&grid, vector<pair<int,int>>&vec, int i0, int j0){
        vis[i][j] = 1;
        vec.push_back({i-i0, j-j0});
        int n = grid.size(), m = grid[0].size();
        int delrow[] = {-1,0,1,0}, delcol[] = {0,-1,0,1};
        for(int x = 0; x < 4; x++){
            int row = i+delrow[x], col = j+delcol[x];
            if(row >= 0 && col >= 0 && row < n && col < m){
                if(!vis[row][col] && grid[row][col]){
                    dfs(row,col,vis, grid, vec, i0, j0);
                }
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m,0));
        set<vector<pair<int,int>>>ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && grid[i][j]){
                    vector<pair<int,int>>vec;
                    dfs(i,j,vis, grid, vec, i,j);
                    ans.insert(vec);
                }
            }
        }
        return ans.size();
    }
};
int main(){
}