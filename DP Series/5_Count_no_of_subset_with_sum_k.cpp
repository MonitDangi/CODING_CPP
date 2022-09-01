#include<bits/stdc++.h>
using namespace std;

int countArr(int idx, int target, vector<int>&arr){
    if(target==0)return 1;
    else if(target<0)return 0;
    if(idx==0){
        if(arr[0]==target)return 1;
        return 0;
    }
    int pick = countArr(idx-1,target-arr[idx],arr);
    int notpick = countArr(idx-1,target,arr);
    int ans = pick+notpick;
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int target;
    cin>>target;
    cout<<countArr(n-1,target,arr)<<endl;
    return 0;
}