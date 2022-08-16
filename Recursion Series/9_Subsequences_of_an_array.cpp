#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;
void subs( int index, vector<int>arr, vector<int>&v){
    if(index>=arr.size()){
       ans.push_back(v);
       return; 
    }
    subs(index+1,arr,v);
    v.push_back(arr[index]);
    subs(index+1,arr,v);
    v.pop_back();
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    vector<int>v;
    subs(0,arr,v);
    return 0;
}