#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination)return true;
        unordered_map<int,set<int>>mp;
        for(int i =0;i<edges.size(); i++){
            mp[edges[i][0]].insert(edges[i][1]);
            mp[edges[i][1]].insert(edges[i][0]);
        }
        unordered_map<int,int>mp2;
        queue<int>rem;
        rem.push(source);
        while(!rem.empty()){
            int num = rem.front();
            rem.pop();
            if(mp2[num])continue;
            mp2[num]++;
            auto x = mp[num];
            for(auto y:x){
                if(y == destination)return true;
                else if(mp2[y]==0){
                    rem.push(y);
                }
            }
        }
        return false;
    }
};
int main(){
}