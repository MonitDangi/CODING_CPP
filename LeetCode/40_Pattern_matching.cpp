#include<bits/stdc++.h>
using namespace std;
int main(){
    string text,pattern;
    cin>>text>>pattern;
    unordered_map<string,vector<int>>mp;
    int s = pattern.size();
    for(int i=0;i<=text.size()-s;i++){
        mp[text.substr(i,s)].push_back(i);
    }
    if(mp[pattern].size()==0)cout<<"-1";
    else{
        for(int i=0;i<mp[pattern].size();i++){
            cout<<mp[pattern][i]<<" ";
        }
    }
    return 0;
}