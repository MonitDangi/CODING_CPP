#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool isValid(int i , int j, int n){
        if(i < 0 || i >= n||j <0||j>=n)return false;
        return true;
    }
public:
    bool a = true, b = true;
    int maxDistance(vector<vector<int>>& grid) {
        unordered_map<int, unordered_map<int, int>>mp;
        int n = grid.size();
        queue<pair<int,int>>rem;
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    rem.push({i,j});
                    mp[i][j]++;
                    a = false;
                }
                else b = false;
                
            }
        }
        if(a || b)return -1;
        int dist = 0;
        while(!rem.empty()){
            int s = rem.size();
            while(s--){
                int i = rem.front().first;
                int j = rem.front().second;
                rem.pop();
                if(isValid(i+1, j, n) && mp[i+1][j] == 0){
                    mp[i+1][j]++;
                    rem.push({i+1, j});
                    ans = dist+1;
                }
                if(isValid(i-1, j, n) && mp[i-1][j] == 0){
                    mp[i-1][j]++;
                    rem.push({i-1, j});
                    ans = dist+1;
                }
                if(isValid(i, j+1, n) && mp[i][j+1] == 0){
                    mp[i][j+1]++;
                    rem.push({i, j+1});
                    ans = dist+1;
                }
                if(isValid(i, j-1, n) && mp[i][j-1] == 0){
                    mp[i][j-1]++;
                    rem.push({i, j-1});
                    ans = dist+1;
                }
            }
            dist++;
        }
        return ans;
    }
};
int main(){
}