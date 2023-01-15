#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pr) {
        vector<int>ans;
        vector<int>count(n,0);
        vector<int>adj[n];
        for(auto &x : pr){
            count[x[0]]++;
            adj[x[1]].push_back(x[0]);
        }
        queue<int>q;
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(count[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int x = q.front();
            ans.push_back(x);
            q.pop();
            cnt++;
            for(auto it: adj[x]){
                count[it]--;
                if(count[it] == 0)q.push(it);
            }
        }
        if(cnt < n)return {};
        return ans;
    }
};
int main(){
}