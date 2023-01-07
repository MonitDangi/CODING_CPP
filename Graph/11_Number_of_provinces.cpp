#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& g) {
        int n = g[0].size();
        vector<int>vis(n,0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(vis[i])continue;
            ans++;
            queue<int>rem;
            rem.push(i);
            while(!rem.empty()){
                int x = rem.front();
                vis[x]++;
                rem.pop();
                for(int y=0;y<n;y++){
                    if(g[x][y] && !vis[y])rem.push(y);
                }
            }
        }
        return ans;
    }
};
int main(){
}