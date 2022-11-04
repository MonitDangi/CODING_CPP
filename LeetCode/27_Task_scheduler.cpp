#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0)return tasks.size();
        unordered_map<char,int>mp;
        for(auto x:tasks){
            mp[x]++;
        }
        priority_queue<int>pq;
        for(auto x:mp){
            pq.push(x.second);
        }
        int ans = 0;
        while(pq.size()){
            vector<int>temp;
            int time =0;
            for(int i=0;i<=n;i++){
                if(pq.size()){
                    temp.push_back(pq.top()-1);
                    pq.pop();
                    time++;
                }
            }
            for(auto x:temp){
                if(x)pq.push(x);
            }
            ans += pq.empty()?time:n+1;
        }
        return ans;
    }
};
int main(){
    return 0;
}