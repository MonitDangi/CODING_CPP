#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool isValid(int i, int j, int m , int n){
        if(i < 0 || i >= m || j < 0 || j >= n)return false;
        return true;
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int l = 0, h = m*n-1;
        int ans = h;
        while(l <= h){
            int mid = l +(h-l)/2;
            if(grid[0][0] > mid){
                l = mid+1;
                continue;
            }
            bool b = false;
            map<pair<int,int>,int>mp;
            mp[{0,0}]++;
            queue<pair<int,int>>rem;
            rem.push({0,0});
            while(!rem.empty()){
                int i = rem.front().first, j = rem.front().second;
                rem.pop();
                if(i == m-1 && j == n-1){
                    b = true;
                    break;
                }
                if(isValid(i+1, j, m, n) && grid[i+1][j] <= mid && mp.find({i+1,j}) == mp.end()){
                    rem.push({i+1,j});
                    mp[{i+1,j}]++;
                }
                if(isValid(i-1, j, m, n) && grid[i-1][j] <= mid && mp.find({i-1,j}) == mp.end()){
                    rem.push({i-1,j});
                    mp[{i-1,j}]++;
                }
                if(isValid(i, j+1, m, n) && grid[i][j+1] <= mid && mp.find({i,j+1}) == mp.end()){
                    rem.push({i,j+1});
                    mp[{i,j+1}]++;
                }
                if(isValid(i, j-1, m, n) && grid[i][j-1] <= mid && mp.find({i,j-1}) == mp.end()){
                    rem.push({i,j-1});
                    mp[{i,j-1}]++;
                }
            }
            if(b){
                ans = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
            
        }
        return ans;
    }
};
int main(){
}