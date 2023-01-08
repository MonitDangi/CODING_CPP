#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n =  points.size();
        int ans = 2;
        if(n<2)return n;
        for(int i = 0; i<n; i++){
            unordered_map<double,int>mp;
            for(int j = 0; j< n; j++){
                if(i==j)continue;
                mp[atan2(points[j][1]-points[i][1],points[j][0]-points[i][0])]++;
            }
            for(auto x:mp){
                if(x.second+1>ans)ans=x.second+1;
            }
        }
        return ans;
    }
};
int main(){
}