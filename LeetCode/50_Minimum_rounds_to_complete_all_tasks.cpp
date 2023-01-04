#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans = 0;
        unordered_map<int,int>mp;
        for(int i:tasks)mp[i]++;
        for(auto x:mp){
            if(x.second < 2)return -1;
            else{
                ans += (x.second/3);
                if(x.second%3)ans++;
            }
        }
        return ans;
    }
};
int main(){
}