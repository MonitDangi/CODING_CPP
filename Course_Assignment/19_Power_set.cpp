#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<string>ans;
    int n= pow(2,s.size());
    for(int i=0;i<n;i++){
        string a;
        for(int j=0;j<s.size();j++){
            if(i&(1<<j)){
                a.push_back(s[j]);
            }
        }
        ans.push_back(a);
    }
    for(int i=0;i<ans.size();i++){
        cout<<"& "<<ans[i]<<endl;
    }
    return 0;
}