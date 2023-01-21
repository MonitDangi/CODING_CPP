#include<bits/stdc++.h>
using namespace std;
int main(){
    int size;
    cin>>size;
    vector<int>location(size);
    for(int i = 0; i < size; i++){
        cin>>location[i];
    }
    int m;
    cin>>m;
    vector<int>from(m);
    vector<int>to(m);
    for(int i = 0; i < m; i++)cin>>from[i];
    for(int i = 0; i < m; i++)cin>>to[i];
    map<int,int>mp;
    for(int i: location){
        mp[i]++;
    }
    for(int i = 0; i < m; i++){
        mp.erase(from[i]);
        mp[to[i]]++;
    }
    for(auto x:mp)cout<<x.first<<"\n";
    return 0;
}