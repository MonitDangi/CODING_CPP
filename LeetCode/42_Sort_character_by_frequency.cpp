#include<bits/stdc++.h>
using namespace std;
class Solution {
    static int comp(pair<int,int>&a, pair<int,int>&b){
        if(a.second <= b.second)return false;
        return true;
    }
public:
    string frequencySort(string s) {
        unordered_map<int,int>mp;
        for(int i =0 ;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto x:mp){
            v.push_back(x);
        }
        string ans;
        sort(v.begin(),v.end(),comp);
        for(auto x:v){
            for(int i=0;i<x.second;i++){
                ans.push_back(char(x.first));
            }
        }
        return ans;
    }
};
int main(){
 
    return 0;
}