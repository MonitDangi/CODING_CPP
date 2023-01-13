#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v;
    int num;
    for(int i = 0; i < n; i++){
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    unordered_map<int,int>m1;
    unordered_map<int,int>m2;
    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                m1[v[i]*v[j]+v[k]]++;
                if(v[i])m2[v[i]*(v[j]+v[k])]++;
            }
        }
    }
    int ans = 0;
    for(auto x:m1){
        ans += x.second*(m2[x.first]);
    }
    cout<<ans<<endl;
    return 0;
}