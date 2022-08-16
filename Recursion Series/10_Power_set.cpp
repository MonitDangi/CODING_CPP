#include<bits/stdc++.h>
using namespace std;
vector<string>ans;

int main(){
    string s ;
    cin>>s;
    int n=s.size();
    for(int i=0;i<(1<<n);i++){
        string a="";
        for(int j=0;j<n;j++)
        if(i&(1<<j))
        a.push_back(s[j]);
        ans.push_back(a);
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}