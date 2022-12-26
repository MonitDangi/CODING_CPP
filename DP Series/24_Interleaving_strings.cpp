#include<bits/stdc++.h>
using namespace std;
class Solution {
    unordered_map<string,bool>mp;
    bool check(string &s1,string &s2,string &s3, int i,int j,int k){
        if(k==s3.size()){
            return true;
        }
        
        string key = to_string(i)+"*"+to_string(j)+"*"+to_string(k);
        if(mp.find(key)!=mp.end())return mp[key]; 
        
        if(i==s1.size())
            return mp[key] = (s2[j]==s3[k])?check(s1,s2,s3,i,j+1,k+1):false;
        
        if(j==s2.size())
            return mp[key] = (s1[i]==s3[k])?check(s1,s2,s3,i+1,j,k+1):false;
        
        bool first=false,second=false;
        
        if(s1[i]==s3[k]){
            first = check(s1,s2,s3,i+1,j,k+1);
        }
        if(s2[j]==s3[k]){
            second = check(s1,s2,s3,i,j+1,k+1);
        }
        return mp[key]=first||second;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())return false;
        return check(s1,s2,s3,0,0,0);
    }
};
int main(){
}