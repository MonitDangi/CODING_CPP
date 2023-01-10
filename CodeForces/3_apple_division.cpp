#include<iostream>
#include<vector>
using namespace std;
void f(int ind, vector<int>&v, long long sum, long long temp,int &ans){
    if(ans > abs(sum-temp))ans= abs(sum-temp);
    if(ind == v.size())return;
    f(ind+1,v,sum,temp,ans);
    f(ind+1,v,sum-v[ind],temp+v[ind],ans);
}
int main(){
    int n;
    cin>>n;
    vector<int>v;
    long long sum = 0;
    for(int i = 0; i<n; i++){
        int num;
        cin>>num;
        v.push_back(num);
        sum +=num;
    }
    int ans = 1e9;
    f(0,v,sum,0,ans);
    cout<<ans<<endl;
    return 0;
}