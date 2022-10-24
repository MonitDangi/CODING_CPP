#include<bits/stdc++.h>
using namespace std;
class Solution {
    void check(int ind,vector<string>&arr,string &str,int &ans){
        if(ind == arr.size()){
            return;
        }
        check(ind+1,arr,str,ans);
        string s1 = str+arr[ind];

        if(s1.size()>26)return;
        unordered_map<int,int>mp;
        for(int i=0;i<s1.size();i++){
            if(mp[s1[i]])return;
            mp[s1[i]]++;
        }
        int size=s1.size();
        ans = max(ans,size);
        check(ind+1,arr,s1,ans);
    }
public:
    int maxLength(vector<string>& arr) {
        int ans =0;
        string str;
        check(0,arr,str,ans);
        return ans;
    }
};
int main(){
    return 0;
}