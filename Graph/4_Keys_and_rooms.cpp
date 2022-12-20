#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>vis(rooms.size(),0);
        queue<int>rem;
        for(int i =0;i<rooms[0].size();i++){
            rem.push(rooms[0][i]);
        }
        vis[0] = 1;
        while(!rem.empty()){
            int f = rem.front();
            rem.pop();
            for(auto x:rooms[f]){
                if(vis[x]==0)rem.push(x);
            }
            vis[f]=1;
        }
        for(auto x:vis)if(!x)return false;
        return true;
    }
};
int main(){
}