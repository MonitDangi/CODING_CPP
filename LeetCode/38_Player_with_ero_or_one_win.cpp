#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& m) {
        unordered_map<int,int>win;
        unordered_map<int,int>lose;
        vector<vector<int>>ans(2);
        for(int i=0;i<m.size();i++){
            win[m[i][0]]++;
            lose[m[i][1]]++;
        }
        for(auto x:win){
            if(lose[x.first] == 0)ans[0].push_back(x.first);
        }
        for(auto x:lose){
            if(x.second == 1)ans[1].push_back(x.first);
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};
int main(){
 
    return 0;
}