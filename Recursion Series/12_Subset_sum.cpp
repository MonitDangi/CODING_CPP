#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>ans;
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    for(int i=0;i<(1<<n);i++){
        int sum=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                sum+= arr[j];
            }
        }
        ans.push_back(sum);
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}