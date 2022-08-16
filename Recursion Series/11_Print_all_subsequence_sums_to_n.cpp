#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>ans;

void recur(int index, int target, vector<int>&arr, vector<int>&v){
    if(index>=arr.size()||target <0)return;
    if(target==0){
        ans.push_back(v);
        return;
    }
    recur(index+1,target,arr,v);
    v.push_back(arr[index]);
    recur(index+1,target-arr[index],arr,v);
    v.pop_back();
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    
    vector<int>v;

    int target;
    cin>>target;

    recur(0,target,arr,v);
    return 0;
}