#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    int ans=-1;
    int left=0,right=n-1;
    int target;
    cin>>target;
    while(left<=right){
        int mid = (left+right)/2;
        if(v[mid]==target){
            if(mid==left||v[mid-1]!=target){
                ans=mid;
                break;
            }
        }
        else if(v[mid]>target){
            right=mid-1;
        }
        else if(v[mid]<target){
            left=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}