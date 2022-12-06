#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
    int m,n;
    bool is(int i, int j){
        if(i<0 || i >= m||j < 0||j >= n)return false;
        return true;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        queue<vector<int>>rem;
        int ans = 1; 
        m = matrix.size(), n = matrix[0].size();
        for(int i = 0;i < m; i++){
            for(int j = 0; j < n; j++){
                rem.push({i,j,1});
            }
        }
        vector<vector<int>>values(m,vector<int>(n,0));
        while(rem.size()){
            int i = rem.front()[0], j = rem.front()[1], count = rem.front()[2];
            rem.pop();
            if(ans<count)ans = count;
            if(is(i-1,j) &&matrix[i-1][j]>matrix[i][j] && count > values[i-1][j]){
                values[i-1][j] = count;
                rem.push({i-1,j,count+1});
            }
            if(is(i+1,j) && matrix[i+1][j]>matrix[i][j] &&count > values[i+1][j]){
                values[i+1][j] = count;
                rem.push({i+1,j,count+1});
            }
            if(is(i,j-1) && matrix[i][j-1]>matrix[i][j] &&count > values[i][j-1]){
                values[i][j-1] = count;
                rem.push({i,j-1,count+1});
            }
            if(is(i,j+1) && matrix[i][j+1]>matrix[i][j] &&count > values[i][j+1]){
                values[i][j+1] = count;
                rem.push({i,j+1,count+1});
            }
        }
        return ans;
    }
};
int main(){
 
    return 0;
}