#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>ans(n, -1);
        ans[0] = 0;
        vector<int> adjred[n];
        vector<int>adjblue[n];
        for(auto & x: redEdges){
            adjred[x[0]].push_back(x[1]);
        }
        for(auto & x: blueEdges){
            adjblue[x[0]].push_back(x[1]);
        }
        vector<int>vis1(n, 0);
        vector<int>vis2(n, 0);
        queue<pair<int,int>>rem;
        rem.push({0,0});
        rem.push({0,1});
        vis1[0] = vis2[0] = 1;
        int d = 1;
        while(rem.size()){
            int s = rem.size();
            while(s--){
                auto x = rem.front();
                rem.pop();
                if(x.second == 0){
                    for(auto it: adjred[x.first]){
                        if(vis1[it] == 0){
                            vis1[it] = 1;
                            if(ans[it]==-1)ans[it]=d;
                            rem.push({it, 1});
                        }
                    }
                }
                else{
                    for(auto it: adjblue[x.first]){
                        if(vis2[it] == 0){
                            vis2[it] = 1;
                            if(ans[it]==-1)ans[it]=d;
                            rem.push({it, 0});
                        }
                    }
                }
            }
            d++;
        }
        return ans;
    }
};
int main(){
}