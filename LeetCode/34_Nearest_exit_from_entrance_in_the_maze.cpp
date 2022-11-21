#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
    bool isValid(int i, int j, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n)return false;
        return true;
    }
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        map<vector<int>, int>mp;
        map<vector<int>, int>mp1;

        int n = maze.size();
        int m = maze[0].size();
        for(int i =0; i<1; i++){
            for(int j =0;j<m; j++){
                if(maze[i][j] == '.')mp[{i,j}]++;
            }
        }
        for(int i = n-1; i<n; i++){
            for(int j =0;j<m; j++){
                if(maze[i][j] == '.')mp[{i,j}]++;
            }
        }
        for(int i = 0; i<n; i++){
            for(int j =0;j<1; j++){
                if(maze[i][j] == '.')mp[{i,j}]++;
            }
        }
        for(int i = 0; i<n; i++){
            for(int j =m-1;j<m; j++){
                if(maze[i][j] == '.')mp[{i,j}]++;
            }
        }
        queue<vector<int>>rem;
        rem.push(entrance);
        int ans = 1;
        mp[entrance] = 0;

        while(!rem.empty()){
            int s = rem.size();
            while(s--){
                int i = rem.front()[0];
                int j = rem.front()[1];
                rem.pop();
                if(isValid(i-1,j,n,m)){
                    if(mp[{i-1,j}]){
                        return ans;
                    }
                    else if(mp1[{i-1,j}] == 0 && maze[i-1][j] == '.'){
                        rem.push({i-1,j});
                        mp1[{i-1,j}]++;
                    }
                }
                if(isValid(i+1,j,n,m)){
                    if(mp[{i+1,j}]){
                        return ans;
                    }
                    else if(mp1[{i+1,j}] == 0 && maze[i+1][j] == '.'){
                        rem.push({i+1,j});
                        mp1[{i+1,j}]++;
                    }
                }
                if(isValid(i,j-1,n,m)){
                    if(mp[{i,j-1}]){
                        return ans;
                    }
                    else if(mp1[{i,j-1}] == 0 && maze[i][j-1] == '.'){
                        rem.push({i,j-1});
                        mp1[{i,j-1}]++;
                    }
                }
                if(isValid(i,j+1,n,m)){
                    if(mp[{i,j+1}]){
                        return ans;
                    }
                    else if(mp1[{i,j+1}] == 0 && maze[i][j+1] == '.'){
                        mp1[{i,j+1}]++;
                        rem.push({i,j+1});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
int main(){
 
    return 0;
}