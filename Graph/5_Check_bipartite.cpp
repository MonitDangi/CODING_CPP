#include<bits/stdc++.h>
using namespace std;
class Solution {
    bool check(vector<vector<int>>& graph,int i, int n, vector<int>&color){
        queue<int>rem;
        rem.push(i);
        color[i] = 1;
        while(!rem.empty()){
            int curr = rem.front();
            rem.pop();
            for(auto x: graph[curr]){
                if(color[curr] == color[x])return false;
                if(color[x] == -1){
                    rem.push(x);
                    color[x] = 1-color[curr];
                }
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1){
                if(!check(graph,i,graph.size(),color))return false;
            }
        }
        return true;
    }
};
int main(){
}
