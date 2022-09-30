#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>>points;
        for(int i=0;i<buildings.size();i++){
            points.push_back({buildings[i][0],-buildings[i][2]});
            points.push_back({buildings[i][1],buildings[i][2]});
        }
        unordered_map<int,int>mp;
        sort(points.begin(),points.end());
        priority_queue<int>rem;
        int curr=0;
        rem.push(0);
        mp[0]++;
        vector<vector<int>>ans;
        for(int i=0;i<points.size();i++){
            if(points[i].second<0){
                rem.push(-points[i].second);
                mp[-points[i].second]++;
            }
            else{
                mp[points[i].second]--;
            }
            while(mp[rem.top()]==0)rem.pop();
            if(curr != rem.top()){
                ans.push_back({points[i].first,rem.top()});
                curr = rem.top(); 
            }
        }
        return ans;
    }
};
int main(){
    return 0;
}